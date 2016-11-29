#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>


using namespace std;

class ConnectionPoint {
  public:
    ConnectionPoint(){}

    void setPotential(double value) {
      potential = value;
    }

    double getPotential() {
      return potential;
    }

private:
  double potential = 0;

};


class Component {
  public:
    Component(string pname) {
      name = pname;
    }

    string getName() {
      return name;
    }

    double getTerminal0() {
      return terminal0;
    }

    double getTerminal1() {
      return terminal1;
    }

    //virtual void moveVoltage(int& terminal0, int& terminal1, double exec_step) = 0;

    double getVoltage() {
      return abs(terminal0 - terminal1);
    }

    virtual double getCurrent() = 0;

    string getType() {
      return type;
    }

    virtual void movePotential(double exec_time, ConnectionPoint& cp1, ConnectionPoint& cp2) = 0;


  protected:
    double terminal0;
    double terminal1;
    double voltage;
    double current;
    string name;
    ConnectionPoint cp1;
    ConnectionPoint cp2;
    string type;
};

class Battery : public Component {
  public:
    Battery(string pname, ConnectionPoint& cp1, ConnectionPoint& cp2, double pvoltage)
      : Component(pname) {
        voltage = pvoltage;
        terminal0 = pvoltage;
        terminal1 = 0;
        cp1.setPotential(pvoltage);
        cp2.setPotential(0);
        current = 0;
        type = "battery";
    }


    // resets battery so that it never runs out
    void movePotential(double exec_time, ConnectionPoint& cp1, ConnectionPoint& cp2) override {
      terminal0 = voltage;
      terminal1 = 0;
      cp1.setPotential(terminal0);
      cp2.setPotential( 0);
    }

    // overrides getCurrent with Battery specific formula. Current is always 0.
    double getCurrent() override {
      return 0;
    }
};

class Resistor : public Component {
  public:
    Resistor(string pname, ConnectionPoint& cp1, ConnectionPoint& cp2, double presistance)
      : Component(pname) {
        resistance = presistance;
        terminal0 = cp1.getPotential();
        terminal1 = cp2.getPotential();
        type = "resistor";
    }

    // move potential according to resistor behaviour
    void movePotential(double exec_step, ConnectionPoint& cp1, ConnectionPoint& cp2) override {
      terminal0 = cp1.getPotential();
      terminal1 = cp2.getPotential();
      double potential_diff = abs(terminal0 - terminal1);
      if (terminal0 < terminal1) {
        terminal0 += (potential_diff / resistance) * exec_step;
        terminal1 -= (potential_diff / resistance) * exec_step;
      } else {
        terminal0 -= (potential_diff / resistance) * exec_step;
        terminal1 += (potential_diff / resistance) * exec_step;
      }
    }

  // overrides getCurrent with Resistor specific formula
  double getCurrent() override {
    return (getVoltage() / resistance);
  }

  private:
    double resistance;
};

class Capacitor : public Component {
  public:
    Capacitor(string pname, ConnectionPoint& cp1, ConnectionPoint& cp2, double pcapacity)
      : Component(pname) {
        capacity = pcapacity;
        terminal0 = cp1.getPotential();
        terminal1 = cp2.getPotential();
        charge = 0;
        type = "capacitor";
    }

    // move potential following capacity behaviour
    void movePotential(double exec_step, ConnectionPoint& cp1, ConnectionPoint& cp2) override {
      double potential_diff = abs(terminal0 - terminal1);
      charge += capacity * (potential_diff - charge) * exec_step;
      if (terminal0 > terminal1) {
        terminal0 -= charge;
        terminal1 += charge;
      } else {
        terminal0 += charge;
        terminal1 -= charge;
      }
    }

    // overrides getCurrent with Capacity specific formula
    double getCurrent() {
      return capacity * (voltage - charge);
    }

  private:
    double capacity;
    double charge;
};


void deallocate_component(vector<Component*> vec) {
  while (!vec.empty()) {
    vec.pop_back();
  }
}

// print first two lines on terminal
void printHeaders(vector<Component*> net) {
  for (int i = 0; i < net.size(); i++) {
    // first header line, add a space if name is two letters (R1, C1, etc)
    if (net.at(i) -> getName().size() == 2) cout << "  ";
    cout << "      " << net.at(i) -> getName();
  }
  cout << endl;
  for (int i = 0; i < net.size(); i++) {
    cout << "Volt " << "Curr ";
  }
  cout << endl;
}

// classes of component have to access connection points
// only works with cp1 and cp2, should be modified later
void simulate(vector<Component*> net, double simul_time, int lines, double step,
              ConnectionPoint& cp1, ConnectionPoint& cp2) {
  int lines_between_prints = simul_time / lines;
  int incr;
  printHeaders(net); // print the two header lines
  for (double time = 0; time <= simul_time + step; time += step) {
    incr++;
    if ((time == 0) || ((incr % lines_between_prints) == 0)) {
      cout << "\nAT TIME t=" << time;
      for (int i = 0; i < net.size(); i++) {
        // for debug right now
        cout << "\n" << net.at(i) -> getName() << " final voltage: " << net.at(i) -> getVoltage();
        cout << "\n" << net.at(i) -> getName() << " final current: " << net.at(i) -> getCurrent();
      }
    }
    for (int i = 0; i < net.size(); i++) {
      net.at(i) -> movePotential(step, cp1, cp2);

    }
  }



  cout << endl;
}

int main(int argc, char* argv[]) {
  ConnectionPoint cp1, cp2;
  vector<Component*> net;
  net.push_back(new Battery("Bat", cp1, cp2, 24.0));
  net.push_back(new Resistor("R1", cp1, cp2, 6.0));
  net.push_back(new Resistor("R2", cp1, cp2, 8.0));
  simulate(net, 10000, 10, 0.1, cp1, cp2);
  deallocate_component(net);
}

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

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
    //virtual void moveVoltage(int& terminal0, int& terminal1, double exec_time) = 0;

    // double getVoltage() {
    //   return abs(terminal0 - terminal1);
    // }

    //virtual double getIntensity() = 0;
    //virtual double getCurrent() = 0;


  protected:
    double terminal0;
    double terminal1;
    double voltage;
    double current;
    string name;
    ConnectionPoint cp1;
    ConnectionPoint cp2;
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
    }


    // double getIntensity() override {
    //   // TODO
    //   return 0.0;
    // }
};

class Resistor : public Component {
  public:
    Resistor(string pname, ConnectionPoint cp1, ConnectionPoint cp2, double presistance)
      : Component(pname) {
        resistance = presistance;
        terminal0 = cp1.getPotential();
        terminal1 = cp2.getPotential();
      }

  // void moveVoltage(int& terminal0, int& terminal1, double exec_time) override {
  //   terminal1 = (terminal0 / resistance) * exec_time;
  // }

  // double getIntensity() override {
  //   return (getVoltage() / resistance);
  // }

  private:
    double resistance;
};

class Capacitor : public Component {
  public:
    Capacitor(string pname, ConnectionPoint cp1, ConnectionPoint cp2, double pcapacity)
      : Component(pname) {
        capacity = pcapacity;
        terminal0 = cp1.getPotential();
        terminal1 = cp2.getPotential();
      }
    // void moveVoltage(int& terminal0, int& terminal1, double exec_time) override {
    //  // TODO
    // }
    //
    // double getIntensity() override {
    //   // TODO
    //   return 0.0;
    // }
  private:
    double capacity;
};



void deallocate_component(vector<Component*> vec) {
  while (!vec.empty()) {
    vec.pop_back();
  }
}

void simulate(vector<Component*> net, double simul_time, int lines, double step) {
  for (double time = 0; time < simul_time; time += step) {
    // EACH SIMULATION STEP BY STEP
    // COUT's
  }
}

int main() {
  ConnectionPoint cp1, cp2;
  vector<Component*> net;
  net.push_back(new Battery("Bat1", cp1, cp2, 24.0));
  net.push_back(new Resistor("R1", cp1, cp2, 6.0));
  net.push_back(new Resistor("R2", cp1, cp2, 8.0));
  simulate(net, 10000, 10, 0.1);
  deallocate_component(net);
}

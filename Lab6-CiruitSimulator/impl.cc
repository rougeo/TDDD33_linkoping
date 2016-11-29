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
    Component(string pname, string ptype, double pterminal0, double pterminal1, ConnectionPoint *pcp1, ConnectionPoint *pcp2 ) {
      name = pname;
      type = ptype;
      terminal0 = pterminal0;
      terminal1 = pterminal1;
      cp1 = pcp1;
      cp2 = pcp2;
      //cp1->setPotential(pcp1.getPotential());
      //cp2->setPotential(pcp2.getPotential());
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
    virtual double getCurrent() = 0;

    string getType() {
      return type;
    }
    double getVoltage() {
     return abs(terminal0 - terminal1);
   }

    virtual void movePotential(double exec_time) = 0;

    double charge (double voltage, double resistance,double step){
      return (voltage/resistance)*step;
    }
    double getcp1_potentiel(){
      return cp1->getPotential();
    }
    double getcp2_potentiel(){
      return cp2->getPotential();
    }
  protected:
    double terminal0;
    double terminal1;
    double voltage;
    double current;
    string name;
    ConnectionPoint* cp1;
    ConnectionPoint* cp2;
    string type;
};


class Battery : public Component {
  public:
    Battery(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double pvoltage)
      : Component(pname, "battery",0,pvoltage,pcp1,pcp2) {
        voltage = pvoltage;
        //cp1->setPotential(pcp1.getPotential());
        //cp2->setPotential(pcp2.getPotential());
        current = 0;

    }


    // resets battery so that it never runs out
    void movePotential(double exec_time) override {
      //terminal0 = voltage;
      //terminal1 = 0;
      cp1->setPotential(voltage);
      cp2->setPotential(0);
      //cp1->setPotential(terminal0);
      //cp2->setPotential(0);
    }

    // overrides getCurrent with Battery specific formula. Current is always 0.
    double getCurrent() override {
     return 0;
   }
};

class Resistor : public Component {
public:
    Resistor(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double presistance)
      : Component(pname, "battery",pcp1->getPotential(),pcp2->getPotential(),pcp1,pcp2){


        resistance = presistance;
        //terminal0 = pcp1.getPotential();
        //terminal1 = pcp2.getPotential();

        //cp1->setPotential(pcp1.getPotential());
        //cp2->setPotential(pcp2.getPotential());
    }

    // move potential according to resistor behaviour
    void movePotential(double exec_step) override {
      terminal0 = cp1->getPotential();
      terminal1 = cp2->getPotential();
      double potential_diff = abs(cp1->getPotential() - cp2->getPotential());
      double q;

      if (cp1->getPotential() > cp2->getPotential()) {
        q = charge(potential_diff, resistance,exec_step);
        cp1->setPotential(cp1->getPotential() - q );
        cp2->setPotential(cp2->getPotential() + q);
      }
      else{
        q = charge(potential_diff, resistance,exec_step);
        cp2->setPotential(cp2->getPotential() - q );
        cp1->setPotential(cp1->getPotential() + q);
      }

    //  std::cout << "this is the movePotentiel " << cp1->getPotential() << " "<< cp2->getPotential()<< std::endl;
    }


  // overrides getCurrent with Resistor specific formula
  double getCurrent() override {
    return (getVoltage() / resistance);
  }

  double getResistance(){
    return resistance;
  }

  private:
    double resistance;
};


void deallocate_component(vector<Component*> vec) {
  while (!vec.empty()) {
    vec.pop_back();
  }
}

// print first two lines on terminal
void printHeaders(vector<Component*> net) {
  for (int i = 0; i < net.size(); i++) {"  ";
    cout << "      " << net.at(i) -> getName();
  }
  cout << endl;
  for (int i = 0; i < net.size(); i++) {
    cout << "Volt " << "Curr ";
  }
  cout << endl;
}

void simulate(vector<Component*> net, double simul_time, int lines, double step) {
  printHeaders(net);
  for (double time = 0; time <= simul_time; time += step) {
    for (int i = 0; i < net.size(); i++) {
      net.at(i) -> movePotential(step);
    }


  }
  for (int i = 0; i < net.size(); i++) {
    // for debug right now
    cout << "\n" << net.at(i) -> getName() << " final voltage: " << net.at(i) ->getVoltage();//abs(net.at(i) ->getcp1_potentiel() - net.at(i)->getcp2_potentiel()) ;
    cout << "\n" << net.at(i) -> getName() << " final current: " << net.at(i) -> getCurrent();
  }

}

// classes of component have to access connection points
// only works with cp1 and cp2, should be modified later
/*
void simulate(vector<Component*> net, double simul_time, int lines, double step) {
  int lines_between_prints = simul_time / lines;
  int incr;
  printHeaders(net); // print the two header lines
  for (double time = 0; time <= simul_time + step; time += step) {
    for (int i = 0; i < net.size(); i++) {
      net.at(i) -> movePotential(step);
  double getResistance(){
    return resistance;
    }
  }
    for (int i = 0; i < net.size(); i++) {
      // for debug right now
      cout << "\n" << net.at(i) -> getName() << " final voltage: " << net.at(i) -> getVoltage();
      cout << "\n" << net.at(i) -> getName() << " final current: " << net.at(i) -> getCurrent();
    }



  cout << endl;
}

*/
int main(int argc, char* argv[]) {
  ConnectionPoint *n{new ConnectionPoint()};
  ConnectionPoint *p{new ConnectionPoint()};
  ConnectionPoint *l{new ConnectionPoint()};
  ConnectionPoint *m{new ConnectionPoint()};
  vector<Component*> net;

  //std::cout << n->getPotential() << std::endl;

  net.push_back(new Battery("Bat", n, p, 24.0));
  net.push_back(new Resistor("R1", p, l, 6.0));
  net.push_back(new Resistor("R2", l, m, 4.0));
  net.push_back(new Resistor("R3", m, n, 8.0));
  net.push_back(new Resistor("R4", l, n, 12.0));
  simulate(net, 200000, 10, 0.01);
  //deallocate_component(net);
  return 0;
}

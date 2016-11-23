#include <algorithm>

class Component {
  public:
    // constructor


    virtual void moveVoltage(int& terminal0, int& terminal1, double exec_time) = 0;

    double getVoltage() {
      return abs(terminal0 - terminal1);
    }

    virtual double getIntensity() = 0;
    virtual double getCurrent() = 0;


  private:
    double terminal0;
    double terminal1;
    double voltage;
    double current;
};

class Battery : public Component {
  public:
    Battery(string name, double voltage, ConnectionPoint cp1, ConnectionPoint cp2) {
      name = name;
      voltage = getVoltage();
      cp1 = setPotential(max(terminal0, terminal1));
      cp2 = setPotential(min(terminal0, terminal1));
    }


    double getIntensity() override {

    }
  private:
    string name;
};

class Resistor : public Component {
  public:
  void moveVoltage(int& terminal0, int& terminal1, double exec_time) override {
    terminal1 = (terminal0 / resistance) * exec_time;
  }

  double getIntensity() override {
    return (getVoltage() / resistance);
  }

  private:
    double resistance;
};

class Capacitor : public Component {
  public:
    void moveVoltage(int& terminal0, int& terminal1, double exec_time) override {

    }

    double getIntensity() override {

    }
  private:
};

class ConnectionPoint {
  public:
    ConnectionPoint(){}

    setPotential(double value) {
      potential = value;
    }
private:
  double potential;

};


void simulate(...) {

}

int main() {
  // init components and connections
  // call simulate
}

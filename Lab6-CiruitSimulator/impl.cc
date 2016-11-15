class Component {
  public:
    // constructor


    virtual void moveVoltage(int& terminal0, int& terminal1) = 0;

    double getVoltage() {
      voltage = abs(terminal0 - terminal1);
    }

    virtual double getIntensity() = 0;

  private:
    int terminal0;
    int terminal1;
    double voltage;
    double current;
}

class Battery : public Component {
  public:
    void moveVoltage(int& terminal0, int& terminal1) override {

    }

    double getIntensity() override {

    }
  private:
    int terminal0;
    int terminal1;

};

class Resistor : public Component {
  public:
    void moveVoltage(int& terminal0, int& terminal1) override {

  }
  private:
    int terminal0;
    int terminal1;

  double getIntensity() override {

  }
};

class Capacitor : public Component {
  public:
    void moveVoltage(int& terminal0, int& terminal1) override {

    }

    double getIntensity() override {

    }
  private:
    int terminal0;
    int terminal1;
};

class ConnectionPoint {
  // start point
  // end point
};


void simulate(...) {

}

int main() {
  // init components and connections
  // call simulate
}

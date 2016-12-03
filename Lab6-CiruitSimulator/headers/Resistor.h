#ifndef RESISTOR_H
#define RESISTOR_H

#include "ConnectionPoint.h"
#include "Component.h"

class Resistor : public Component {
  public:
    Resistor(std::string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double presistance);
    void movePotential(double exec_step) override;
    double getCurrent() override;
    double getResistance();
  private:
    double resistance;
};

#endif

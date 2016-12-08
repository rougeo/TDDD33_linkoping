#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "ConnectionPoint.h"
#include "Component.h"

class Capacitor : public Component {
  public:
    Capacitor(std::string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double pcapacity);
    void movePotential(double exec_step) override;
    double getCurrent() override;
    double getCapacity();

  private:
    double capacity;
    double q = 0;
};

#endif

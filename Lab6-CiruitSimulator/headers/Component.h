#ifndef COMPONENT_H
#define COMPONENT_H

#include "ConnectionPoint.h"

class Component {
  public:
    Component(std::string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2);
    std::string getName();
    virtual double getCurrent() = 0;
    double getVoltage();
    virtual void movePotential(double exec_time) = 0;

  protected:
    double voltage;
    double current;
    std::string name;
    ConnectionPoint* cp1;
    ConnectionPoint* cp2;
  };

#endif

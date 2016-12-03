#ifndef COMPONENT_H
#define COMPONENT_H

#include "ConnectionPoint.h"

class Component {
  public:
    Component(std::string pname, std::string ptype, double pterminal0, double pterminal1, ConnectionPoint* pcp1, ConnectionPoint* pcp2);
    std::string getName();
    virtual double getCurrent() = 0;
    std::string getType(); // remove it later if not used
    double getVoltage();
    virtual void movePotential(double exec_time) = 0;


  protected:
    double terminal0;
    double terminal1;
    double voltage;
    double current;
    std::string name;
    ConnectionPoint* cp1;
    ConnectionPoint* cp2;
    std::string type;
};

#endif

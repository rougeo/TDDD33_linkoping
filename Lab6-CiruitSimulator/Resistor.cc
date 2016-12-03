#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "Resistor.h"

using namespace std;


Resistor::Resistor(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double presistance)
  : Component(pname, "battery",pcp1->getPotential(),pcp2->getPotential(),pcp1,pcp2){
    resistance = presistance;
}


void Resistor::movePotential(double exec_step) {
  terminal0 = cp1->getPotential();
  terminal1 = cp2->getPotential();
  double potential_diff = abs(cp1->getPotential() - cp2->getPotential());
  double q;

  if (cp1->getPotential() > cp2->getPotential()) {
    q = (potential_diff / resistance) * exec_step;
    cp1->setPotential(cp1->getPotential() - q );
    cp2->setPotential(cp2->getPotential() + q);
  }
  else{
    q = (potential_diff / resistance) * exec_step;
    cp2->setPotential(cp2->getPotential() - q );
    cp1->setPotential(cp1->getPotential() + q);
  }
}


double Resistor::getCurrent() {
  return (getVoltage() / resistance);
}

double Resistor::getResistance() {
  return resistance;
}

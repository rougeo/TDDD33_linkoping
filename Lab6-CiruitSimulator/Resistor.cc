#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/Resistor.h"

using namespace std;


Resistor::Resistor(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double presistance)
  : Component(pname, pcp1, pcp2) {
    resistance = presistance;
}

void Resistor::movePotential(double exec_step) {
  double potential_diff = abs(cp1->getPotential() - cp2->getPotential());
  double q;
  q = (potential_diff / resistance) * exec_step;

  if (cp1->getPotential() > cp2->getPotential()) {
    cp1->setPotential(cp1->getPotential() - q );
    cp2->setPotential(cp2->getPotential() + q);
  } else{
    cp1->setPotential(cp1->getPotential() + q );
    cp2->setPotential(cp2->getPotential() - q);
  }
  voltage = abs(cp1->getPotential() - cp2->getPotential());
}

double Resistor::getCurrent() {
  return (voltage / resistance);
}

double Resistor::getResistance() {
  return resistance;
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/Capacitor.h"

using namespace std;

Capacitor::Capacitor(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double pcapacity)
  : Component(pname, "capacitor", pcp1->getPotential(), pcp2->getPotential(), pcp1, pcp2) {
    capacity = pcapacity;
    q = 0;
}

// move potential following capacity behaviour
void Capacitor::movePotential(double exec_step) {
  double potential_diff = abs(cp1->getPotential() - cp2->getPotential());
  q += capacity * (potential_diff - q) * exec_step;
  if (cp1->getPotential() > cp2->getPotential()) {
    cp1->setPotential(cp1->getPotential() - q);
    cp2->setPotential(cp2->getPotential() + q);
  } else {
    cp1->setPotential(cp1->getPotential() + q);
    cp2->setPotential(cp2->getPotential() - q);
  }

  terminal0 = cp1->getPotential();
  terminal1 = cp2->getPotential();
}

// overrides getCurrent with Capacity specific formula
double Capacitor::getCurrent() {
  return capacity * (voltage - q);
}

double Capacitor::getCapacity() {
  return capacity;
}

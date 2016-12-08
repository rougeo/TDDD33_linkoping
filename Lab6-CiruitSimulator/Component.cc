#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/Component.h"

using namespace std;

Component::Component(string pname, string ptype, double pterminal0, double pterminal1, ConnectionPoint *pcp1, ConnectionPoint *pcp2 ) {
  name = pname;
  type = ptype;
  terminal0 = pterminal0;
  terminal1 = pterminal1;
  cp1 = pcp1;
  cp2 = pcp2;
}

string Component::getName() {
  return name;
}

double Component::getVoltage() {
 return abs(cp1->getPotential() - cp2->getPotential());
}

double Component::getCp1() {
  return cp1->getPotential();
}

double Component::getCp2() {
  return cp2->getPotential();
}

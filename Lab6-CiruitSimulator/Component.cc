#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "Component.h"

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

string Component::getType() {
  return type;
}

double Component::getVoltage() {
 return abs(terminal0 - terminal1);
}

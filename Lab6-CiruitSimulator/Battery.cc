#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/Battery.h"

using namespace std;

Battery::Battery(string pname, ConnectionPoint* pcp1, ConnectionPoint* pcp2, double pvoltage)
  : Component(pname, "battery", 0, pvoltage, pcp1, pcp2) {
    voltage = pvoltage;
    current = 0;
}

void Battery::movePotential(double exec_time) {
  cp1->setPotential(voltage);
  cp2->setPotential(0);
}

double Battery::getCurrent() {
   return 0;
}

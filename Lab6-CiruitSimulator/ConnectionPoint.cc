#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/ConnectionPoint.h"

using namespace std;

ConnectionPoint::ConnectionPoint(){
  potential = 0;
}

void ConnectionPoint::setPotential(double value) {
  potential = value;
}

double ConnectionPoint::getPotential() {
  return potential;
}

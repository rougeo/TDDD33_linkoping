#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "headers/ConnectionPoint.h"
#include "headers/Component.h"
#include "headers/Battery.h"
#include "headers/Resistor.h"
#include "headers/Capacitor.h"

using namespace std;


void deallocate_component(vector<Component*> vec) {
  while (!vec.empty()) {
    vec.pop_back();
  }
}

// print first two lines on terminal
void printHeaders(vector<Component*> net) {
  for (int i = 0; i < net.size(); i++) {
    if (i == 0) cout << "        " << net.at(i) -> getName();
    else cout << "          " << net.at(i) -> getName();
  }
  cout << endl;
  for (int i = 0; i < net.size(); i++) {
    cout << " Volt  " << "Curr ";
  }
  cout << endl;
}

// function that takes care of all cases of the annoying output requirement
void printValue(double val1, double val2) {
  if ((val1 > 10) && (val2 > 10)) {
    cout << setprecision(2) << fixed << val1 << " " << val2;
  } else if ((val1 > 10) && (val2 < 10)) {
    cout << setprecision(2) << fixed << val1 << "  " << val2;
  } else if ((val1 < 10) && (val2 > 10)) {
    cout << setprecision(2) << fixed << " " << val1 << " " << val2;
  } else if ((val1 < 10) && (val2 < 10)) {
    cout << setprecision(2) << fixed << " " << val1 << "  " << val2;
  }
  cout << " ";
}

void simulate(vector<Component*> net, double simul_time, int lines, double step) {
  printHeaders(net);
  double target_time_line = simul_time / lines;
  for (double time = 0; time <= simul_time + step; time += step) {
    if ((time >= target_time_line)) {
      for (int i = 0; i < net.size(); i++) {
        printValue(net.at(i) -> getVoltage(), net.at(i) -> getCurrent());
      }
      target_time_line += simul_time / lines;
      cout << endl;
    }

    for (int i = 0; i < net.size(); i++) {
      net.at(i) -> movePotential(step);
    }
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  ConnectionPoint *p{new ConnectionPoint()};
  ConnectionPoint *l{new ConnectionPoint()};
  ConnectionPoint *r{new ConnectionPoint()};
  ConnectionPoint *n{new ConnectionPoint()};
  vector<Component*> net;

  net.push_back(new Battery("Bat", p, n, 24.0));
  net.push_back(new Resistor("R1", p, l, 150.0));
  net.push_back(new Resistor("R2", p, r, 50.0));
  net.push_back(new Capacitor("C3", l, r, 1.0));
  net.push_back(new Resistor("R4", l, n, 300.0));
  net.push_back(new Capacitor("C5", r, n, 0.75));
  simulate(net, 200000, 10, 0.01);
  deallocate_component(net);
  return 0;
}

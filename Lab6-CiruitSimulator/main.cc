#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>
#include <stdexcept>

#include "headers/ConnectionPoint.h"
#include "headers/Component.h"
#include "headers/Battery.h"
#include "headers/Resistor.h"
#include "headers/Capacitor.h"

#define EXEMPLE2

using namespace std;

void deallocate_component(vector<Component*> vec) {
  while (!vec.empty()) {
    vec.pop_back();
  }
}

// print first two lines on terminal
void printHeaders(vector<Component*> net) {
  for (size_t i = 0; i < net.size(); i++) {
    if (i == 0) cout << "        " << net.at(i) -> getName();
    else cout << "          " << net.at(i) -> getName();
  }
  cout << endl;
  for (size_t i = 0; i < net.size(); i++) {
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
  for (double time = 0; time <= simul_time; time += 1) {
    if ((time >= target_time_line)) {
      for (size_t i = 0; i < net.size(); i++) {
        printValue(net.at(i) -> getVoltage(), net.at(i) -> getCurrent());
      }
      target_time_line += simul_time / lines;
      cout << endl;
    }

    for (size_t i = 0; i < net.size(); i++) {
      net.at(i) -> movePotential(step);
    }
  }
  cout << endl;
}

bool checkForTypeValidity(string value) {
  try {
    stoi(value);
  } catch(invalid_argument) {
    cerr  << "Error on argument " << value
          << ": strings are not acceptable parameters." << endl;
    return false;
  } catch (out_of_range) {
    cerr  << "Value " << value << " is out of range of C++ double type." << endl;
    return false;
  }
  return true;
}

bool checkForValueValidity(double value) {
  if (value < 0) {
    cerr << "Values cannot be negative";
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (argc != 5) {
    cerr  << "Invalid arguments. Usage: ./a.out simul_time nbrOfLines step voltage"
          << endl;
  } else {
    for (int i = 1; i < argc; i++) {
      if (!checkForTypeValidity(argv[i])) {
        cout << "Exiting ..." << endl;
        return -1;
      }

      if (!checkForValueValidity(stoi(argv[i]))) {
        cout << "Exiting ..." << endl;
        return -1;
      }
    }
    // if both checks are passed, go on with the program
    double voltage = stod(argv[4]);
    double step = stod(argv[3]);
    double lines = stod(argv[2]);
    double simul_time = stod(argv[1]);

    #ifdef EXEMPLE1
      ConnectionPoint *p{new ConnectionPoint()};
      ConnectionPoint *l{new ConnectionPoint()};
      ConnectionPoint *r{new ConnectionPoint()};
      ConnectionPoint *n{new ConnectionPoint()};
      vector<Component*> net;

      net.push_back(new Battery("Bat", p, n, voltage));
      net.push_back(new Resistor("R1", p, l, 6.0));
      net.push_back(new Resistor("R2", l, r, 4.0));
      net.push_back(new Resistor("R3", r, n, 8.0));
      net.push_back(new Resistor("R4", l, n, 12.0));
    #endif

    #ifdef EXEMPLE2
      ConnectionPoint *p{new ConnectionPoint()};
      ConnectionPoint *l{new ConnectionPoint()};
      ConnectionPoint *r{new ConnectionPoint()};
      ConnectionPoint *n{new ConnectionPoint()};
      vector<Component*> net;

      net.push_back(new Battery("Bat", p, n, voltage));
      net.push_back(new Resistor("R1", p, l, 150.0));
      net.push_back(new Resistor("R2", p, r, 50.0));
      net.push_back(new Resistor("R3", l, r, 100.0));
      net.push_back(new Resistor("R4", l, n, 300.0));
      net.push_back(new Resistor("R5", r, n, 250.0));
    #endif

    #ifdef EXEMPLE3
      ConnectionPoint *p;
      ConnectionPoint *l;
      ConnectionPoint *r;
      ConnectionPoint *n;
      vector<Component*> net;

      net.push_back(new Battery("Bat", p, n, voltage));
      net.push_back(new Resistor("R1", p, l, 150.0));
      net.push_back(new Resistor("R2", p, r, 50.0));
      net.push_back(new Capacitor("C3", l, r, 1.0));
      net.push_back(new Resistor("R4", l, n, 300.0));
      net.push_back(new Capacitor("C5", r, n, 0.75));
    #endif

    cout << simul_time << endl << lines << endl<< step << endl;
    simulate(net, simul_time, lines, step);
    deallocate_component(net);
    return 0;
  }
}

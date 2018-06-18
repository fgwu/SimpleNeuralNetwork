#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;
struct Connection
{
  double weight;
  double deltaWeight;
};

class Neuron;

typedef vector<Neuron> Layer;

void showVectorVals(string label, vector<double> &v);
#endif

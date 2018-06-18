#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

#include "training_data.h"

using namespace std;

void TrainingData::getTopology(vector<unsigned> &topology)
{
  string line;
  string label;

  getline(m_trainingDataFile, line);
  stringstream ss(line);
  ss >> label;
  if(this->isEof() || label.compare("topology:") != 0)
  {
    abort();
  }

  while(!ss.eof())
  {
    unsigned n;
    ss >> n;
    topology.push_back(n);
  }
  return;
}

TrainingData::TrainingData(const string filename)
{
  m_trainingDataFile.open(filename.c_str());
}


unsigned TrainingData::getNextInputs(vector<double> &inputVals)
{
  inputVals.clear();

  string line;
  getline(m_trainingDataFile, line);
  stringstream ss(line);

  string label;
  ss >> label;
  if (label.compare("in:") == 0) {
    char c;
    double oneValue;
    while (ss >> c) {
      oneValue = (c - 'a') / 26.0;
      inputVals.push_back(oneValue);
    }
  }

  return inputVals.size();
}

unsigned TrainingData::getTargetOutputs(vector<double> &targetOutputVals)
{
  targetOutputVals.clear();

  string line;
  getline(m_trainingDataFile, line);
  stringstream ss(line);

  string label;
  ss>> label;
  if (label.compare("out:") == 0) {
    double oneValue;
    while (ss >> oneValue) {
      targetOutputVals.push_back(oneValue / 10.0);
    }
  }

  return targetOutputVals.size();
}

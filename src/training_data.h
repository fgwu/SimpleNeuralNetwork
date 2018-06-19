#ifndef TRAINING_DATA_H
#define TRAINING_DATA_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class TrainingData
{
  public:
  TrainingData(const string filename);
  bool isEof(void) { return m_trainingDataFile.eof(); }
  void SeekToBegin();

  void getTopology(vector<unsigned> &topology);

  // Returns the number of input values read from the file:
  unsigned getNextInputs(vector<double> &inputVals);
  unsigned getTargetOutputs(vector<double> &targetOutputVals);

  long lines;

  private:

  ifstream m_trainingDataFile;
};

#endif

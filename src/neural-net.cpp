#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

#include "global.h"
#include "training_data.h"
#include "neuron.h"
#include "net.h"
using namespace std;


void showVectorVals(string label, vector<double> &v)
{
  cout << label << " ";
  for(unsigned i = 0; i < v.size(); ++i)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

void showInputVectorVals(string label, vector<double> &v)
{
  cout << label << " ";
  for(unsigned i = 0; i < v.size(); ++i)
  {
//    cout << (char)('a' + (int)(v[i]));
    cout << v[i] << " ";
  }
  cout << endl;
}

void showOutputVectorVals(string label, vector<double> &v)
{
  cout << label << " ";
  for(unsigned i = 0; i < v.size(); ++i)
  {
    cout << v[i] << " ";
//    cout << (int)(v[i]) << " ";
  }
  cout << endl;
}

int main()
{

  TrainingData trainData("../script/training.txt");
  //e.g., {3, 2, 1 }
  vector<unsigned> topology;
  topology.push_back(6);
  topology.push_back(10);
  topology.push_back(1);

  Net myNet(topology);

  vector<double> inputVals, targetVals, resultVals;

  for (int i = 0; i < 1; i++) {
    cout << i << "\n";
    while(!trainData.isEof())
    {
      // Get new input data and feed it forward:
      if(trainData.getNextInputs(inputVals) != topology[0])
        break;
//      showVectorVals(": Inputs :", inputVals);
      myNet.feedForward(inputVals);

      // Collect the net's actual results:
      myNet.getResults(resultVals);
//      showVectorVals("Outputs:", resultVals);

      // Train the net what the outputs should have been:
      trainData.getTargetOutputs(targetVals);
//      showVectorVals("Targets:", targetVals);
      assert(targetVals.size() == topology.back());

      myNet.backProp(targetVals);

      // Report how well the training is working, average over recnet
//    cout << "Net recent average error: "
//         << myNet.getRecentAverageError() << endl;
    }
    trainData.SeekToBegin();
  }

  TrainingData testData("../script/testing.txt");
  int testSamples = 0;
  double accu_err = 0;
  while(!testData.isEof())
  {
    ++testSamples;
    cout << endl << "test sample" << testSamples << "\n";

    // Get new input data and feed it forward:
    if(testData.getNextInputs(inputVals) != topology[0])
      break;
    showInputVectorVals(": Inputs :", inputVals);
    myNet.feedForward(inputVals);

    // Collect the net's actual results:
    myNet.getResults(resultVals);
    showOutputVectorVals("Outputs:", resultVals);

    // Train the net what the outputs should have been:
    testData.getTargetOutputs(targetVals);
    showOutputVectorVals("Targets:", targetVals);

    accu_err += abs(resultVals[0] - targetVals[0]);

  }

  cout << "avg err = " << accu_err / testSamples << "\n";

  cout << endl << "Done" << endl;

}

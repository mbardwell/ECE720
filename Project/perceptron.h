/**********************************************************/
/*                       PERCEPTRON.H                     */
/**********************************************************/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <string>
#include <ctime>    // For time()
#include <random>
#include "memory1.h"
#include "memory1.c"
#include "auxiliary.h"
#include "cmath"
using namespace std;

#define HLU 0
#define HLB 1
#define SIGU 0
#define SIGB 0
#define alpha 0.1

#define TRAININGSIZE 100
#define NOINPUTS 2
#define NOOUTPUTS 1
#define VERBOSE 0
#define LEARNINGRATE 0.1
#define NOEPOCHS 5

class Perceptron {
private:
  double * weight_buffer;
  double * classification;
  double ** se;
  double ** rmse;
  int iteration = 1, epoch = 1;
  string EOL;
  double tot, guess, error;
  double rmse_temp = 0, numhold = 0; // se: squared error
  int correct_guesses = 0, wrong_guesses = 0;

public:
  Perceptron(double ** input);
  void inputCheck(double ** input);
  void generateBuffers();
  void zeroBuffers();
  void generateWeights();
  void calculate(double ** input);
  void activation();
  void train(double ** input);
  void statistics();
  void freeBuffer(double ** input);
  void toFile();
  void verify(double ** input);
  void classify(double ** input);
};

#endif

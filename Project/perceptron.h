/**********************************************************/
/*                       PERCEPTRON.H                     */
/**********************************************************/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <ctime>    // For time()
#include <random>
#include "memory1.h"
#include "memory1.c"
#include "auxiliary.h"
#include "cmath"
using namespace std;

#define HLU 0
#define HLB 0
#define SIGU 0
#define SIGB 1
#define alpha 0.1

class Perceptron {
private:
  double * weight_buffer;
  double * se;
  double * rmse;
  // double *
  int iteration = 0, EOL = 0;
  double tot, guess, error;
  double rmse_temp = 0, epoch = 1; // se: squared error

public:
  Perceptron(double ** input);
  void inputCheck(double ** input);
  void generateWeights();
  void calculate(double ** input);
  void activation();
  void train(double ** input);
  void statistics();
  void freeBuffer(double ** input);
};

#endif

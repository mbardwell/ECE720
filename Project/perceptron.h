#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <ctime>    // For time()
#include <random>
#include "memory1.h"
#include "memory1.c"
#include "auxiliary.h"
using namespace std;

#define HLU 0
#define HLB 1
#define SIGA 0
#define SIGB 0

class Perceptron {
private:
  double * weight_buffer;
  int iteration = 0;
  double sum, guess;

public:
  Perceptron(double ** input);
  void inputCheck(double ** input);
  void generate_weights();
  void calculate(double ** input);
  void activation();
  void train(double ** input);
};

#endif

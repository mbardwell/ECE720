/**********************************************************/
/*                       PERCEPTRON.H                     */
/**********************************************************/

#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H

#include <iostream>
#include <ctime>    // For time()
#include <random>
#include "memory1.h"
#include "errormessages.h"
using namespace std;

#define MIN_DATA_SIZE 1
#define MAX_DATA_SIZE 2

class Perceptron {
/* Private by default */
  double * input_buffer;
  double * output_buffer;
  double * weight_buffer;
  double sum = 0, bias = 0;
  double noIterations = 0;

public:
  /* Constructors */
  Perceptron() { //double * userInputs
    plswork();
    // input_buffer = writing(userInputs);
    // inputCheck();
  }
  // Perceptron(double * userInputs, double userBias) {
  //   input_buffer = writing(userInputs);
  //   // inputCheck();
  //   // inputs = userInputs;
  //   // bias = userBias;
  // }

  /* Methods */
  int plswork();
  double * writing(double * userInputs);
  // void inputCheck();
  // void generate_data();
  // void printSummary();
  // double iteration();
  // double activation(double sum);

};

#endif // main.h

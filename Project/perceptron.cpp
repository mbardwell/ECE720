#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  inputCheck(input);
  generate_weights();
  calculate(input);
  activation();
  train(input);
}

void Perceptron::inputCheck(double ** input) {
  cout << "Checking inputs" << endl;
  for (int i = 0; i < NOINPUTS; i++) {
    for (int j = 0; j < TRAININGSIZE; j++) {
      // cout << "line: " << input[i][j] << endl; // DEBUGGING
      // cout << "Input [i][j] [" << i << "][" << j << "]" << endl;
      if ((input[i][j] < -1) | (input[i][j] > 1)) {
        cout << "Input [i][j] [" << i << "][" << j << "] exceeds (-1,1) range" << endl;
        exit(-1);
      }
    }
  }
}

void Perceptron::generate_weights() {
  cout << "Generating weights" << endl;
  weight_buffer = (double *) my_malloc(NOINPUTS*sizeof(double));
  /* Random Method */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < NOINPUTS; i++) { // rows
    weight_buffer[i] = urd(eng);
    cout << "weight: " << weight_buffer[i] << endl;
  }
}

void Perceptron::calculate(double ** input) {
  cout << "Calculating sum" << endl;
  sum = 0; // restart sum between
  for (int i = 0; i < NOINPUTS; i++) { // rows
    sum += input[i][iteration]*weight_buffer[i];
    // cout << "input: " << input[i][j] << endl;
    // cout << "sum: " << sum << endl;
  }
}

void Perceptron::activation() {
  cout << "Activating neuron" << endl;
  if (HLU) {
    if (sum <= 0) guess = 0;
    else if (sum > 0) guess = 1;
  }
  if (HLB) {
    if (sum <= 0) guess = -1;
    else if (sum > 0) guess = 1;
  }
  cout << "Guess " << guess << endl;
}

void Perceptron::train(double ** input) {
  double error = input[NOINPUTS][iteration] - guess;
  for (int i = 0; i < NOINPUTS; i++) {
    weight_buffer[i] += error*input[i][iteration]*LEARNINGRATE;
    cout << "error: " << error << endl;
    cout << "input: " << input[i][iteration] << endl;
    cout << "new weights [" << i << "]:  " << weight_buffer[i] << endl;
  }
}

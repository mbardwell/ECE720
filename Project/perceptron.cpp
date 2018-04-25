#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  inputCheck(input);
  generate_weights();
  for(int i = 0; i < TRAININGSIZE; i++) {
    calculate(input);
    activation();
    train(input);
  }
  cin >> EOL; while (1) if (EOL) freebuffer(input);
}

void Perceptron::inputCheck(double ** input) {
  cout << "Checking inputs" << endl;
  for (int i = 0; i < NOINPUTS; i++) {
    for (int j = 0; j < TRAININGSIZE; j++) {
      if (VERBOSE) {
        cout << "line: " << input[i][j] << endl; // DEBUGGING
        cout << "Input [i][j] [" << i << "][" << j << "]" << endl;
      }
      if ((input[i][j] < -1) | (input[i][j] > 1)) {
        cout << "Input [i][j] [" << i << "][" << j << "] exceeds (-1,1) range" << endl;
        exit(-1);
      }
    }
  }
}

void Perceptron::generate_weights() {
  cout << "Generating weights: " << endl;
  weight_buffer = (double *) my_malloc(NOINPUTS*sizeof(double));
  /* Random Method */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < NOINPUTS; i++) { // rows
    weight_buffer[i] = urd(eng);
    if (VERBOSE) { cout << "weight: " << weight_buffer[i] << " ";}
  } cout << endl;
}

void Perceptron::calculate(double ** input) {
  cout << "Calculating sum for iteration: " << iteration << endl;
  sum = 0; // restart sum between
  for (int i = 0; i < NOINPUTS; i++) { // rows
    sum += input[i][iteration]*weight_buffer[i];
    if (VERBOSE) {
      cout << "input: " << input[i][iteration];
      cout << " weight: " << weight_buffer[i];
      cout << " sum: " << sum << endl;
    }
  }
}

void Perceptron::activation() {
  cout << "Activating neuron. ";
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
  error = input[NOINPUTS][iteration] - guess;
  for (int i = 0; i < NOINPUTS; i++) {
    weight_buffer[i] += error*input[i][iteration]*LEARNINGRATE;
    if (VERBOSE) {
      cout << "error: " << error;
      cout << " input: " << input[i][iteration] << endl;
      cout << "new weights [" << i << "]:  " << weight_buffer[i] << endl;
    }
  }
  iteration++;
}

void Perceptron::rmse() {

}

void Perceptron::freebuffer(double ** input) {
  my_free(weight_buffer);
  cout << "weights freed" << endl;
  for (int i = 0; i < (NOINPUTS + 1); i++) {
    cout << "i: " << i << endl;
    my_free(input[i]);
  }
  my_free(input);
  exit(-1);
}

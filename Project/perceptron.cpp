/**********************************************************/
/*                       PERCEPTRON.CPP                   */
/**********************************************************/


#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  cout << "Generating rmse buffer" << endl;
  rmse = (double *) my_malloc(TRAININGSIZE*sizeof(double));
  inputCheck(input);
  generateWeights();
  cout << "training" << endl;
  for(int i = 0; i < TRAININGSIZE; i++) {
    calculate(input);
    activation();
    train(input);
    statistics();
  }
  cout << "Enter number to free buffers and end program: ";
  cin >> EOL;
  while (1) if (EOL) freeBuffer(input);
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

void Perceptron::generateWeights() {
  cout << "Generating weights" << endl;
  weight_buffer = (double *) my_malloc(NOINPUTS*sizeof(double));
  /* Random Method */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < NOINPUTS; i++) { // rows
    weight_buffer[i] = urd(eng);
    if (VERBOSE) cout << "weight: " << weight_buffer[i] << " ";
  }
}

void Perceptron::calculate(double ** input) {
  sum = 0; // restart sum between
  for (int i = 0; i < NOINPUTS; i++) { // rows
    sum += input[i][iteration]*weight_buffer[i];
    if (VERBOSE) {
      cout << "Calculating sum for iteration: " << iteration << endl;
      cout << "input: " << input[i][iteration];
      cout << " weight: " << weight_buffer[i];
      cout << " sum: " << sum << endl;
    }
  }
}

void Perceptron::activation() {
  if (HLU) {
    if (sum <= 0) guess = 0;
    else if (sum > 0) guess = 1;
  }
  if (HLB) {
    if (sum <= 0) guess = -1;
    else if (sum > 0) guess = 1;
  }
  if (VERBOSE) {
    cout << "Activating neuron. " << endl;
    cout << "Guess " << guess << endl;
  }
}

void Perceptron::train(double ** input) {
  error = input[NOINPUTS][iteration] - guess;
  mse += pow(error,2);
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

void Perceptron::statistics() {
  rmse[iteration] = sqrt(mse)/(iteration + 1);
  if (VERBOSE) {
    cout << "iteration: " << iteration;
    cout << " Root mean squared error: " << rmse[iteration] << endl;
  }

  if (iteration == (TRAININGSIZE -1)) {
    ofstream file;
    file.open ("C:/Users/Michael/Documents/ece720/Project/test/results.txt");
    for (int i = 1; i < TRAININGSIZE; i++) {
      file << rmse[i] << "\n";
    }
    cout << "Last RMSE: " << rmse[TRAININGSIZE-1] << endl;
    file.close();
  }
}

void Perceptron::freeBuffer(double ** input) {
  cout << "Freeing weights" << endl;
  my_free(weight_buffer);

  cout << "Freeing inputs" << endl;
  for (int i = 0; i < (NOINPUTS + 1); i++) {
    my_free(input[i]);
  }
  my_free(input);
  cout << "Freeing rmse" << endl;
  my_free(rmse);
  exit(-1);
}

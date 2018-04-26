/**********************************************************/
/*                       PERCEPTRON.CPP                   */
/**********************************************************/


#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  inputCheck(input);
  generateBuffers();
  generateWeights();

  while (1) {
    cout << "Enter 'train' to train or 1 to free buffers and end program: ";
    cin >> EOL;
    if (EOL == "1") freeBuffer(input);
    else if (EOL == "train") {
      iteration = 1;
      cout << "training" << endl;
      for(int i = 0; i < TRAININGSIZE; i++) {
        calculate(input);
        activation();
        train(input);
        statistics();
        iteration++;
      }
    }
  }
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

void Perceptron::generateBuffers() {
    cout << "Generating weight buffer" << endl;
    weight_buffer = (double *) my_malloc(NOINPUTS*sizeof(double));
    cout << "Generating RMSE buffers" << endl;
    rmse = (double *) my_malloc(TRAININGSIZE*sizeof(double));
    cout << "Generating SE buffers" << endl;
    se = (double *) my_malloc(TRAININGSIZE*sizeof(double));
}

void Perceptron::generateWeights() {
  cout << "Generating weights" << endl;

  /* Random Method */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < NOINPUTS; i++) { // rows
    weight_buffer[i] = urd(eng);
    if (VERBOSE) cout << "weight: " << weight_buffer[i] << " ";
  }
}

void Perceptron::calculate(double ** input) {
  tot = 0; // restart tot between
  for (int i = 0; i < NOINPUTS; i++) { // rows
    tot += input[i][iteration-1]*weight_buffer[i];
    if (VERBOSE) {
      cout << "Calculating tot for iteration: " << iteration << endl;
      cout << "input: " << input[i][iteration-1];
      cout << " weight: " << weight_buffer[i];
      cout << " tot: " << tot << endl;
    }
  }
}

void Perceptron::activation() {
  if (HLU) {
    if (tot <= 0) guess = 0;
    else if (tot > 0) guess = 1;
  }
  if (HLB) {
    if (tot <= 0) guess = -1;
    else if (tot > 0) guess = 1;
  }
  if (SIGU) {
    guess =  1/(1 + exp(-alpha*tot));
  }
  if (SIGB) {
    guess =  (1-exp(-alpha*tot))/(1 + exp(-alpha*tot));
  }
  if (VERBOSE) {
    cout << "Activating neuron. " << endl;
    cout << "Guess " << guess << endl;
  }
}

void Perceptron::train(double ** input) {
  error = input[NOINPUTS][iteration-1] - guess;
  se[iteration-1] += pow(error,2);
  for (int i = 0; i < NOINPUTS; i++) {
    weight_buffer[i] += error*input[i][iteration-1]*LEARNINGRATE;
    if (VERBOSE) {
      cout << "error: " << error;
      cout << " input: " << input[i][iteration-1] << endl;
      cout << "new weights [" << i << "]:  " << weight_buffer[i] << endl;
    }
  }
}

void Perceptron::statistics() {
  rmse_temp = 0;
  for (int i = 0; i < iteration; i++) {
    rmse_temp += se[i];
  }
      rmse[iteration-1] = sqrt(rmse_temp)/(iteration*epoch + 1);
  if (VERBOSE) {
    cout << "iteration: " << iteration;
    cout << " Root mean squared error: " << rmse[iteration-1] << endl;
  }

  if (iteration == (TRAININGSIZE)) {
    ofstream file;
    file.open ("C:/Users/Michael/Documents/ece720/Project/test/results.txt");
    for (int i = 0; i < TRAININGSIZE; i++) {
      file << rmse[i] << "\n";
    }
    cout << "Last RMSE: " << rmse[TRAININGSIZE-1] << endl;
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
  cout << "Freeing statistics buffers" << endl;
  my_free(rmse);
  my_free(se);
  exit(1);
}

/**********************************************************/
/*                       PERCEPTRON.CPP                   */
/**********************************************************/


#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  inputCheck(input);
  generateBuffers();
  zeroBuffers();
  generateWeights();

  while (1) {
    if (epoch > NOEPOCHS) {
      cout << "Reached max number of allowable epochs" << endl;
      freeBuffer(input);
    }
    cout << "Enter 'train' to train or 1 to free buffers and end program: ";
    cin >> EOL;
    if (EOL == "1") freeBuffer(input);
    else if (EOL == "train") {
      cout << "training" << endl;
      train(input);
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
    cout << "Generating SE buffers" << endl;
    se = (double **) my_malloc(NOEPOCHS*sizeof(double *));
    for (int i = 0; i < NOEPOCHS; i++) {
      se[i] = (double *) my_malloc(TRAININGSIZE*sizeof(double));
    }
    cout << "Generating RMSE buffers" << endl;
    rmse = (double **) my_malloc(NOEPOCHS*sizeof(double *));
    for (int i = 0; i < NOEPOCHS; i++) {
      rmse[i] = (double *) my_malloc(TRAININGSIZE*sizeof(double));
    }
    cout << "Generating SE buffers" << endl;
}

void Perceptron::zeroBuffers() {
  for (int i = 0; i < NOEPOCHS; i++) {
    for (int j = 0; j < TRAININGSIZE; j++) {
      se[i][j] = 0;
      rmse[i][j] = 0;
    }
  }
}

void Perceptron::generateWeights() {
  cout << "Generating weights";
  if (VERBOSE) cout << ": ";
  if (!VERBOSE) cout << "\n";

  /* Random Method */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < NOINPUTS; i++) { // rows
    weight_buffer[i] = urd(eng);
    if (VERBOSE) cout << "w" << i << ": " << weight_buffer[i] << " ";
  }
  if (VERBOSE) cout << endl;
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
  for(iteration = 1; iteration <= TRAININGSIZE; iteration++) {
    calculate(input);
    activation();
    error = input[NOINPUTS][iteration-1] - guess;
    for (int j = 0; j < NOINPUTS; j++) {
      weight_buffer[j] += error*input[j][iteration-1]*LEARNINGRATE;
      if (VERBOSE) {
        cout << "error: " << error;
        cout << " input: " << input[j][iteration-1] << endl;
        cout << "new weights [" << j << "]:  " << weight_buffer[j] << endl;
      }
    }
    se[epoch-1][iteration-1] = pow(error,2);
    statistics();
  }
  epoch++;
}

void Perceptron::statistics() {
  rmse_temp = 0;
  for (int j = 0; j < iteration; j++) {
    rmse_temp += se[epoch-1][j];
  }
  rmse[epoch-1][iteration-1] = sqrt(rmse_temp + numhold)/(iteration + ((epoch-1)*TRAININGSIZE));
  if (VERBOSE) {
    cout << "iteration: " << iteration << " epoch: " << epoch;
    cout << " Root mean squared error: " << rmse[epoch-1][iteration-1] << endl;
  }
  if (iteration == TRAININGSIZE) {
    numhold = rmse_temp + numhold;
    cout << "Last RMSE: " << rmse[epoch-1][TRAININGSIZE-1] << endl;
  }
}

void Perceptron::freeBuffer(double ** input) {
  toFile();
  cout << "Freeing weights" << endl;
  my_free(weight_buffer);

  cout << "Freeing inputs" << endl;
  for (int i = 0; i < (NOINPUTS + NOOUTPUTS); i++) {
    my_free(input[i]);
  }
  my_free(input);
  cout << "Freeing statistics buffers" << endl;
  for (int i = 0; i < (NOEPOCHS); i++) {
    my_free(rmse[i]);
  }
  my_free(rmse);
  for (int i = 0; i < (NOEPOCHS); i++) {
    my_free(se[i]);
  }
  my_free(se);
  exit(1);
}

void Perceptron::toFile() {
  epoch--;
  ofstream file;
  file.open ("C:/Users/Michael/Documents/ece720/Project/test/results.txt");
  for (int i = 0; i < epoch; i++) {
    for (int j = 0; j < TRAININGSIZE; j++) {
      file << rmse[i][j] << "\n";
    }
  }
  file.close();
}

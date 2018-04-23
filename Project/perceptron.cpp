#include "perceptron.h"

Perceptron::Perceptron(double ** input) {
  inputCheck(input);
  // writing(input);
  // generate_weights();
  // calculate();
  // activation();
}

void Perceptron::inputCheck(double ** input) {
  cout << "Checking inputs" << endl;
  for (int i = 0; i < NOINPUTS; i++) {
    for (int j = 0; j < TRAININGSIZE; j++) {
      if ((input[i][j] < -1) | (input[i][j] > 1)) {
        cout << "Input [i][j] [" << i << "][" << j << "] exceeds (-1,1) range" << endl;
        exit(-1);
      }
    }
  }
}

// void Perceptron::writing(double ** input) {
//   cout << "Writing input data to buffer" << endl;
//   input_buffer = (double *)my_malloc(input[0]*sizeof(double));
//   for (int i = 0; i < input[0]; i++) {
//     input_buffer[i] = input[i+1];
//     cout << "input_buffer: " << input_buffer[i] << endl;
//   }
// }

void Perceptron::generate_weights() {
  cout << "Generating weight data" << endl;
  weight_buffer = (double *)my_malloc(TRAININGSIZE*sizeof(double));
  /* Random Method 1 */
  // srand(unsigned(time(NULL))); // Initialize RNG
  // weights = (double)(rand()-(RAND_MAX/2))/RAND_MAX; // Init weight randomly

  /* Random Method 2 */
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(-1, 1);

  for (int i = 0; i < TRAININGSIZE; i++) {
    weight_buffer[i] = urd(eng);
    cout << "weight buffer:" << weight_buffer[i] << endl;
  }
}

double Perceptron::calculate() {
  cout << "Calculating sum" << endl;
  for(int i = 0; i < TRAININGSIZE; i++) {
    sum += input_buffer[i]*weight_buffer[i];
  }
  cout << "sum: " << sum << endl;
}

void Perceptron::activation() {
  cout << "Activating neuron" << endl;
  if (HLU) {
    if (sum <= 0) fout = 0;
    else if (sum > 0) fout = 1;
  }
  if (HLB) {
    if (sum <= 0) fout = -1;
    else if (sum > 0) fout = 1;
  }
  cout << "Activation function output: " << fout << endl;
}

void Perceptron::train(double * input, double target) {

}

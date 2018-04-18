#include "perceptron.h"

/* Reads */
int plswork() {
  return 1;
}

double * writing(double * userInputs, double * in_buff) {
  int no_of_data_points = userInputs[0];
  cout << "no_of_data_points: " << userInputs[0] << endl;
  cout << "Reading data into a local buffer" << endl;
  int buffersize = (no_of_data_points+2)*sizeof(double);
  cout << "buffersize" << buffersize << endl;
  // in_buff = (double *) my_malloc(buffersize);
  for (int i = 0; i < no_of_data_points; i++) {
    in_buff[i] = userInputs[i+1];
    cout << userInputs[i] << endl;
  }
  return in_buff;
}

// Used to randomly generate weights
void generate_data(double input_buffer[]) {
  cout << "Generating weight data" << endl;
  int no_of_data_points = MAX_DATA_SIZE;
  // input_buffer = (double *) my_malloc((no_of_data_points+2)*sizeof(double));

  /* Random Method 1 */
  // srand(unsigned(time(NULL))); // Initialize RNG
  // weights = (double)(rand()-(RAND_MAX/2))/RAND_MAX; // Init weight randomly

  /* Random Method 2 */
  random_device seed;
  mt19937_64 gen(seed());
  uniform_real_distribution<double> dist(0, 5000);

  for (int i = 0; i < no_of_data_points; i++) {
    input_buffer[i] = (dist(gen)-2500)/5000;
  }
}
void inputCheck(double * input_buffer) {
  for (int i = 0; i < MAX_DATA_SIZE; i++) {
    if (-1 > input_buffer[i] || 1 < input_buffer[i]) {
      cout << INVALID_INPUT << endl;
      exit(-1);
    }
  }
}
// void printSummary(double noIterations) {
//   cout << "Number of Iterations: " << noIterations << endl;
//   cout << "Weights: " << weights << endl;
//   cout << "Inputs: " << inputs << endl;
//   cout << "Outputs: " << outputs << endl;
// }
// double iteration() {
//   sum = (weights * inputs) + bias;
//   noIterations += 1;
//   return sum;
// }
// double activation(double sum) {
//   if (sum > 0) outputs = 1;
//   else outputs = -1;
//   return outputs;
// }

#include "main.h"

int main() {
  double ** plswork;
  plswork = readfile();
  for (int j = 0; j < TRAININGSIZE; j++) {
    for (int i = 0; i < (NOINPUTS + 1); i++) { // rows
      // getline(myfile, line);
      // plswork[i][j] = stod(line);
      cout << "line: " << plswork[i][j] << endl;
      cout << "Input [i][j] [" << i << "][" << j << "]" << endl;
      // cout << "line: " << data[i][j] << endl;
    }
  }
  // Perceptron test(j);
}

#include "main.h"
#include "perceptron.cpp"

#define TRAININGSIZE 10
#define NOINPUTS 2

void readfile() {
  double ** data;
  data = (double **) my_malloc(TRAININGSIZE*sizeof(double *)); // rows
  for (int i = 0; i < TRAININGSIZE; i++) {
    data[i] = (double *) my_malloc((NOINPUTS + 1) * sizeof(int)); // columns
  }

  string line;
  ifstream myfile ("C:/Users/Michael/Documents/ece720/Project/test/trainingdata.txt");
  if (myfile.is_open())
  {
      /* Inputs separated by columns (ie input 1 in data[0], 2 in data[1]) */
      for (int i = 0; i < NOINPUTS + 1; i++) {
        for (int j = 0; i < TRAININGSIZE; i++) {
          getline(myfile, line);
          data[i][j] = stod(line);
          cout << "data: " << data[i][j] << endl;
        }
      }
    myfile.close();
  }
  else cout << "Unable to open file";
}

int main() {
  readfile();
  double j[] = {5, -0.3, 0.6, 0.2, 0.3, 0.6};
  Perceptron test(j);
}

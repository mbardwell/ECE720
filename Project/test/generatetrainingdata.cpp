#include <iostream>
#include <ctime>
#include <random>
using namespace std;

#define TRAININGSIZE 10

int main() {
  default_random_engine eng{static_cast<long unsigned int>(time(0))};
  uniform_real_distribution<double> urd(0,1);
  double train[3*TRAININGSIZE];

  for (int i = 0; i < TRAININGSIZE*3; i = i + 3) {
    train[i] = urd(eng); // x
    train[i+1] = urd(eng); // y
    if (train[i+1] - train[i] > 0) train[i+2] = 1;
    else train[i+2] = -1;
    cout << "x: " << train[i] << " y: " << train[i+1] << " sol: " << train[i+2] << endl;
  }
}

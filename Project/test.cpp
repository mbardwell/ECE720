// Move into /Project if you want it to run

#include <iostream>
#include <string>
#include <ctime>    // For time()
#include <random>
#include "memory1.c"
#include "auxiliary.h"
#include "cmath"
using namespace std;

int main() {
  double * a;
  cout << a << endl;
  a = (double *) my_malloc(4*sizeof(double));
  double b[] = {1, 2, 3, 4};
  a = b;
  cout << a << endl;
  a = (double *) my_malloc(5*sizeof(double));
  cout << a << endl;
}

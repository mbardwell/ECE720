/**********************************************************/
/*                       MAIN.CPP                         */
/**********************************************************/

#include "main.h"

int main() {
  double ** data;
  data = readfile();
  Perceptron test(data);
}

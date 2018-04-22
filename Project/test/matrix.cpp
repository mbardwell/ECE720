#include <iostream>

using namespace std;

int main() {
  int a[] = {1, 2, 3}; // 1 row, 3 columns
  int b[] = {4, 5, 6};
  int * matrix[] = {a, b};
  cout << matrix[1][1] << endl;
  return 0;
}

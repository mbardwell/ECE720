#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

// #define MONTHS 12

// void interchange(int *u, int *v);

int main(void) {
  short *fl, *fl2, a = 5, b;
  printf("%d %d %d\n", fl,fl2, &a); fl = fl + 1;
  printf("%d\n", fl);

  // int a = 13 / 5;
  // int b = 13 % 5;
  // printf("%d %d\n", a, b);
  // return 0;

  // float fl[10] = {1, 2, [9] = 8};
  // printf("%f\n", fl[8]);

  // int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
  // int i;
  // for (i = 0; i < MONTHS; i++)
  // printf("%2d %d\n", i + 1, days[i]);
  // return 0;

  // int x = 5, y = 8;
  // interchange(&x, &y);
  // printf("%d %d\n", x, y);
  // return 0;

  // int *p;
  // p = (int *) my_malloc(sizeof(int));
  // if (p == NULL) {
  //   printf("Memory has not been allocated");
  //   exit(1);
  // }
  // *p = 10;
  // my_free(p);
  // return 0;
}

// void interchange(int *u, int *v) {
//   int a = *u;
//   *u = 9;
//   *v = 10;
// }

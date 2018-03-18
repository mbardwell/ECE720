#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main(void) {
  int *p;
  p = (int *) my_malloc(sizeof(int));
  if (p == NULL) {
    printf("Memory has not been allocated");
    exit(1);
  }
  *p = 10;
  my_free(p);
  return 0;
}

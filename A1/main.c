#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int int_value;
  float float_value;
  char str_value[10];
  printf("Enter an integer value: ");
  gets(str_value);
  int_value = atoi(str_value);
  printf("value: %i\n", int_value);
}

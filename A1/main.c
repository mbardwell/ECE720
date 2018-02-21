#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  float float_value;
  char usrin[10];
  printf("Choose Groceries, Entertainment or 'Other' Category: ");
  scanf("%s", usrin);
  if (!strcmp(usrin, "Groceries")) {
    printf("%s\n", "Groceries");
  }
  else if (!strcmp(usrin,"Entertainment")) { // Compare inputs in integer domain
    printf("%s\n", "Entertainment");
  }
  else if (!strcmp(usrin, "Other")){
    printf("%s\n", "Other");
  }
  else {
    printf("%s\n", "Bad Input");
  }
exit(1);
}

// if groceries -> fruits/vegetables, others back to main menu

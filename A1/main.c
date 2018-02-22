/* ECE 720 Assignment 1, Winter 2018, Michael Bardwell
   Automated expense manager */

// Preprocessor instructions: Include headers to use libraries
#include <stdio.h> // Example of a preprocessor directive
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaration statements
#define MAX_INPUT_LENGTH 40 // Max number of bytes (incl. null value)
char name[MAX_INPUT_LENGTH];
char usrin[MAX_INPUT_LENGTH];
int fruit_cost; // int is a C keyword. int_value is an identifier
int groc_other_cost;
int etmt_cost;
int groc_flag = 0;
int fruit_flag = 0;
int groc_other_flag = 0;
int etmt_flag = 0;
int etmt_cost_flag = 0;

int value_check(float value);

int main(void)
{
  // Name handling section
  printf("Please enter a name under %d characters: ", MAX_INPUT_LENGTH);
  scanf("%s", name);
  if (strlen(name) > MAX_INPUT_LENGTH) {
    printf("Error: You name had %d characters. You should have up to %d. Please retry", strlen(name), MAX_INPUT_LENGTH);
    exit(1);
  }
  name[0] = toupper(name[0]);

  // Initial selection of groceries or entertainment. Rejects exit call.
  printf("Hey %s! Choose GROCERIES, ENTERTAINMENT or EXIT if done: ", name);
  scanf("%s", usrin);
  while ((strcmp(usrin,"GROCERIES")) & (strcmp(usrin,"ENTERTAINMENT"))) {
    printf("Try again %s. Please enter GROCERIES, ENTERTAINMENT or EXIT if done: ", name);
    scanf("%s", usrin);
  }
  // Handles grocery/entertainment inputs
  while (1) {
    if (!strcmp(usrin, "GROCERIES")) {
      groc_flag = 1;
      printf("GROCERIES selected %s\n", name);
      while(1) {
        printf("%s, please select FRUITS/VEGETABLES, OTHERS or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "FRUITS/VEGETABLES")) {
          printf("%s, enter amount spent on FRUITS/VEGETABLES this week: ", name);
          scanf("%d", &fruit_cost);
          if (!value_check(fruit_cost)) {
          fruit_flag = 1;
          }
        }
        else if (!strcmp(usrin, "OTHERS")) {
          printf("%s, enter amount spent on other groceries this week: ", name);
          scanf("%d", &groc_other_cost);
          if (!value_check(groc_other_cost)) {
          groc_other_flag = 1;
          }
        }
        else if (!strcmp(usrin, "back to main menu")) {
          if ((fruit_flag) & (groc_other_flag)) {
            break;
          }
          else {
            printf("%s, you have not entered at least one value for each section\n", name);
          }
        }
        else {
          printf("%s, not all subcategories filled out\n", name);
        }
      }
      printf("%s, thanks for adding your weekly grocery costs. Back to main menu\n", name);
    }
    else if (!strcmp(usrin,"ENTERTAINMENT")) {
      etmt_flag = 1;
      printf("%s, ENTERTAINMENT selected\n", name);
      while (1) {
        printf("%s, please select ENTERTAINMENT COST or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "ENTERTAINMENT COST")) {
          printf("%s, enter amount spent on entertainment cost this week: ", name);
          scanf("%d", &etmt_cost);
          if (!value_check(etmt_cost)) {
          etmt_cost_flag = 1;
          }
        }
        else if (!strcmp(usrin, "back to main menu")) {
          if (etmt_cost_flag) {
            break;
          }
          else {
            printf("%s, you have not entered at least one value for ENTERTAINMENT\n", name);
          }
        }
        else {
          printf("%s, not all subcategories filled out\n", name);
        }
      }
    printf("%s, thanks for adding your weekly entertainment costs. Back to main menu\n", name);
    }
    else if (!strcmp(usrin,"EXIT")) {
      if (groc_flag & etmt_flag) {
        printf("\n\n%s\nFRUIT/VEGETABLES cost: %d\nOTHERS cost: %d\nENTERTAINMENT cost: %d\n", name, fruit_cost, groc_other_cost, etmt_cost);
        exit(1);
      }
      else {
        printf("%s, need to fill out weekly GROCERIES/ENTERTAINMENT cost before exiting\n", name);
        printf("Hey %s! Choose GROCERIES, ENTERTAINMENT or EXIT if done: ", name);
        scanf("%s", usrin);
      }
    }
    else {
      printf("Hey %s! Choose GROCERIES, ENTERTAINMENT or EXIT if done: ", name);
      scanf("%s", usrin);
    }
  }
}

// Checks inputs for allowable range
int value_check(float value) {
  // Assuming the input is not a letter
  if (value < 0) {
    printf("Please input a non-negative number\n");
    return 1;
  }
return 0;
}

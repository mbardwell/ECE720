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
  printf("Please enter a name under %d characters: ", MAX_INPUT_LENGTH); // Request user's name
  scanf("%s", name); // Read and store user's name
  if (strlen(name) > MAX_INPUT_LENGTH) { // Throw error if username is too big
    printf("Error: You name had %d characters. You should have up to %d. Please retry", strlen(name), MAX_INPUT_LENGTH);
    exit(1);
  }
  name[0] = toupper(name[0]); // Set first letter to uppercase

  printf("Hey %s! Choose GROCERIES, ENTERTAINMENT or EXIT if done: ", name);
  scanf("%s", usrin);
  while ((strcmp(usrin,"GROCERIES")) & (strcmp(usrin,"ENTERTAINMENT"))) {
    printf("Try again. Please enter GROCERIES, ENTERTAINMENT or EXIT if done: ");
    scanf("%s", usrin);
  }
  while (1) {
    if (!strcmp(usrin, "GROCERIES")) {
      groc_flag = 1;
      printf("GROCERIES selected\n");
      while(1) {
        printf("%s, please select FRUITS/VEGETABLES, OTHERS or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "FRUITS/VEGETABLES")) {
          printf("Enter amount spent on FRUITS/VEGETABLES this week: ");
          scanf("%d", &fruit_cost);
          if (!value_check(fruit_cost)) {
          fruit_flag = 1;
          }
        }
        else if (!strcmp(usrin, "OTHERS")) {
          printf("Enter amount spent on other groceries this week: ");
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
            printf("You have not entered at least one value for each section\n");
          }
        }
        else {
          printf("Not all subcategories filled out\n");
        }
      }
      printf("Thanks for adding your weekly grocery costs. Back to main menu\n");
    }
    else if (!strcmp(usrin,"ENTERTAINMENT")) { // Compare inputs in integer domain
      etmt_flag = 1;
      printf("ENTERTAINMENT selected\n");
      while (1) {
        printf("%s, please select ENTERTAINMENT COST or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "ENTERTAINMENT COST")) {
          printf("Enter amount spent on entertainment cost this week: ");
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
            printf("You have not entered at least one value for ENTERTAINMENT\n");
          }
        }
        else {
          printf("Not all subcategories filled out\n");
        }
      }
    printf("Thanks for adding your weekly entertainment costs. Back to main menu\n");
    }
    else if (!strcmp(usrin,"EXIT")) {
      if (groc_flag & etmt_flag) {
        printf("\n\nFRUIT/VEGETABLES cost: %d\nOTHERS cost: %d\nENTERTAINMENT cost: %d\n", fruit_cost, groc_other_cost, etmt_cost);
        exit(1);
      }
      else {
        printf("Need to fill out weekly GROCERIES/ENTERTAINMENT cost before exiting\n");
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

int value_check(float value) {
  // Assuming the input is not a letter
  if (value < 0) {
    printf("Please input a non-negative number\n");
    return 1;
  }
return 0;
}

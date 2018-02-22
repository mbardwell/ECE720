/* ECE 720 Assignment 1, Winter 2018, Michael Bardwell
   Automated expense manager */

// Preprocessor instructions: Include headers to use libraries
#include <stdio.h> // Example of a preprocessor directive
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaration statements
#define MAX_INPUT_LENGTH 10 // Max number of bytes (incl. null value)
char name[MAX_INPUT_LENGTH];
char usrin[MAX_INPUT_LENGTH];
float fruit_cost; // float is a C keyword. float_value is an identifier
float groc_other_cost;
float etmt_cost;

int groc_flag = 0;
int fruit_flag = 0;
int groc_other_flag = 0;
int etmt_flag = 0;

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

  printf("Hey %s! Choose Groceries or Entertainment: ", name);
  scanf("%s", usrin);
  while ((strcmp(usrin,"Groceries")) & (strcmp(usrin,"Entertainment"))) {
    printf("Try again. Please enter Groceries or Entertainment: ");
    scanf("%s", usrin);
  }
  while ((!groc_flag) | (!etmt_flag)) {
  if (!strcmp(usrin, "Groceries")) {
    groc_flag = 1;
    printf("%s", "Groceries selected\n");
    while(1) {
      printf("%s, please select Fruits, Other or Menu for item entry:", name);
      scanf("%s", usrin);
      if (!strcmp(usrin, "Fruits")) {
        printf("Enter amount spent on Fruits/Vegetables this week: ");
        scanf("%f", &fruit_cost);
        if (!value_check(fruit_cost)) {
        fruit_flag = 1;
        }
      }
      else if (!strcmp(usrin, "Other")) {
        printf("Enter amount spent on other groceries this week: ");
        scanf("%f", &groc_other_cost);
        // while(value_check(groc_other_cost)) {
        //   scanf("%f", &groc_other_cost);
        // }
        if (!value_check(groc_other_cost)) {
        groc_other_flag = 1;
        }
      }
      else if (!strcmp(usrin, "Menu")) {
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
  else if (!strcmp(usrin,"Entertainment")) { // Compare inputs in integer domain
    etmt_flag = 1;
    printf("%s\n", "Entertainment selected");
    printf("Enter amount spent on Entertainment this week: ");
    scanf("%f", &etmt_cost);
    while(value_check(etmt_cost)) {
      scanf("%f", &etmt_cost);
    }
    printf("Thanks for adding your weekly entertainment costs. Back to main menu");
  }
  else {
    printf("Exiting");
    exit(1);
  }
}
  return(0);
}

int value_check(float value) {
  // Assuming the input is not a letter
  if (value < 0) {
    printf("Please input a non-negative number\n");
    return 1;
  }
return 0;
}

// if groceries -> fruits/vegetables, others back to main menu

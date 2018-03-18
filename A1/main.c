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
int fruit_cost = -1; // int is a C keyword. int_value is an identifier
int other_cost = -1;
int etmt_cost = -1;

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
      printf("GROCERIES selected %s\n", name);
      while(1) {
        printf("%s, please select FRUITS/VEGETABLES, OTHERS or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "FRUITS/VEGETABLES")) {
          while(fruit_cost < 0) {
            printf("%s, enter amount spent on FRUITS/VEGETABLES this week: ", name);
            scanf("%d", &fruit_cost);
          }
        }
        else if (!strcmp(usrin, "OTHERS")) {
          while(other_cost < 0) {
            printf("%s, enter amount spent on other groceries this week: ", name);
            scanf("%d", &other_cost);
          }
        }
        else if (!strcmp(usrin, "back to main menu")) {
          if (!(fruit_cost < 0) & !(other_cost < 0)) {
            break;
          }
          else {
            printf("%s, not all subcategories filled out\n", name);
          }
        }
      }
      printf("%s, thanks for adding your weekly grocery costs. Back to main menu\n", name);
    }
    else if (!strcmp(usrin,"ENTERTAINMENT")) {
      printf("%s, ENTERTAINMENT selected\n", name);
      while (1) {
        printf("%s, please select ENTERTAINMENT COST or back to main menu for item entry:", name);
        fflush(stdin); gets(usrin);
        if (!strcmp(usrin, "ENTERTAINMENT COST")) {
          while(etmt_cost < 0) {
            printf("%s, enter amount spent on entertainment cost this week: ", name);
            scanf("%d", &etmt_cost);
          }
        }
        else if (!strcmp(usrin, "back to main menu")) {
          if (!(etmt_cost < 0)) {
            break;
          }
          else {
            printf("%s, not all subcategories filled out\n", name);
          }
        }
      }
    printf("%s, thanks for adding your weekly entertainment costs. Back to main menu\n", name);
    }
    else if (!strcmp(usrin,"EXIT")) {
      if (!(fruit_cost < 0) & !(other_cost < 0) & !(etmt_cost < 0)) {
        printf("\n\n%s\nFRUIT/VEGETABLES cost: %d\nOTHERS cost: %d\nENTERTAINMENT cost: %d\n", name, fruit_cost, other_cost, etmt_cost);
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

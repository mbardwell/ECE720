/* ECE 720 Assignment 2, Winter 2018, Michael Bardwell
   Automated expense manager */

// Preprocessor instructions: Include headers to use libraries
#include <stdio.h> // Example of a preprocessor directive
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaration statements
#define MAX_USR_LEN 40 // Max number of bytes (incl. null value)
#define ERR -1 // Declaring error
char name[MAX_USR_LEN];
char usrin[MAX_USR_LEN];
double fruit_cost = -1;
double other_cost = -1;
double etmt_cost = -1;
double fruit_budg, other_budg, etmt_budg;
double fruit_blnc [MAX_USR_LEN], other_blnc[MAX_USR_LEN], etmt_blnc[MAX_USR_LEN];
int no_weeks, i;
double perc;

int main(void)
{
  // Name handling section
  printf("Please enter a name under %d characters: ", MAX_USR_LEN);
  scanf("%s", name);
  if (strlen(name) > MAX_USR_LEN) {
    printf("Error: You name had %d characters. You should have up to %d. Please retry", strlen(name), MAX_USR_LEN);
    exit(1);
  }
  name[0] = toupper(name[0]);

  // Pulling budget information
  FILE *file_id;
  file_id = fopen("cost.txt","r");
  if (file_id == NULL) {
    printf("The file cannot be found\n");
    return ERR;
  }
  fscanf(file_id, "%d", &no_weeks);
  for (i=0; i < no_weeks; i++) {
    fscanf(file_id, "%lf", &fruit_blnc[i]);
    fruit_budg = fruit_budg + fruit_blnc[i];
    fscanf(file_id, "%lf", &other_blnc[i]);
    other_budg = other_budg + other_blnc[i];
    fscanf(file_id, "%lf", &etmt_blnc[i]);
    etmt_budg = etmt_budg + etmt_blnc[i];
  } fclose(file_id); i = i + 1;
  fruit_budg = fruit_budg/no_weeks;
  other_budg = other_budg/no_weeks;
  etmt_budg = etmt_budg/no_weeks;
  printf("%s, your budget for fruit is $%.2lf, other $%.2lf entertainment $%.2lf\n", name, fruit_budg, other_budg, etmt_budg);
  printf("%s, do you want to increase or decrease your budget? ", name);
  scanf("%s", usrin);
  while ((strcmp(usrin,"increase")) & (strcmp(usrin,"decrease"))) {
    printf("%s, do you want to increase or decrease your budget? ", name);
    scanf("%s", usrin);
  }
  if (!strcmp(usrin, "increase")) {
    printf("%s, What percentage do you want to increase by? ", name);
    scanf("%lf", &perc);
    fruit_budg = fruit_budg*(1+(perc/100));
    other_budg = other_budg*(1+(perc/100));
    etmt_budg = etmt_budg*(1+(perc/100));
  }
  else if (!strcmp(usrin, "decrease")) {
    printf("%s, What percentage do you want to decrease by? ", name);
    scanf("%lf", &perc);
    fruit_budg = fruit_budg*(1-(perc/100));
    other_budg = other_budg*(1-(perc/100));
    etmt_budg = etmt_budg*(1-(perc/100));
  }

  // Starting self-reporting loops
  while (1) {
    printf("Hey %s! enter expenses, show balance or exit if done: ", name);
    fflush(stdin); gets(usrin);
      if (!(strcmp(usrin,"enter expenses"))) {
        while(1) {
        if (!strcmp(usrin, "GROCERIES")) {
          printf("GROCERIES selected %s\n", name);
          while(1) {
            printf("%s, please select FRUITS/VEGETABLES, OTHERS or back to main menu for item entry:", name);
            fflush(stdin); gets(usrin);
            if (!strcmp(usrin, "FRUITS/VEGETABLES")) {
              while(fruit_cost < 0) {
                printf("%s, enter amount spent on FRUITS/VEGETABLES this week: ", name);
                scanf("%lf", &fruit_cost);
              }
              fruit_blnc[i] = fruit_cost;
            }
            else if (!strcmp(usrin, "OTHERS")) {
              while(other_cost < 0) {
                printf("%s, enter amount spent on other groceries this week: ", name);
                scanf("%lf", &other_cost);
              }
              other_blnc[i] = other_cost;
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
                scanf("%lf", &etmt_cost);
              }
              etmt_blnc[i] = etmt_cost;
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
            printf("\n\n%s\nFRUIT/VEGETABLES cost: $%.2lf\nOTHERS cost: $%.2lf\nENTERTAINMENT cost: $%.2lf\n", name, fruit_cost, other_cost, etmt_cost);
            break;
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
    else if (!(strcmp(usrin,"show balance"))) {
      while (fruit_budg - fruit_blnc[i] < 0) {
        double perc_over = -1*100*(fruit_budg-fruit_blnc[i])/fruit_budg;
        printf("%s, Fruit cost is %.0lf percent over budget. Please input percent increase: ", name, perc_over);
        scanf("%lf", &perc);
        fruit_budg = fruit_budg*(1+perc/100);
      }
      while (other_budg - other_blnc[i] < 0) {
        double perc_over = -1*100*(other_budg-other_blnc[i])/other_budg;
        printf("%s, Other cost is %.0lf percent over budget. Please input percent increase: ", name, perc_over);
        scanf("%lf", &perc);
        other_budg = other_budg*(1+perc/100);
      }
      while (etmt_budg - etmt_blnc[i] < 0) {
        double perc_over = -1*100*(etmt_budg-etmt_blnc[i])/etmt_budg;
        printf("%s, Entertainment cost is %.0lf percent over budget. Please input percent increase: ", name, perc_over);
        scanf("%lf", &perc);
        etmt_budg = etmt_budg*(1+perc/100);
      }
      printf("Fruit balance: $%.2lf\n", fruit_budg - fruit_blnc[i]);
      printf("Other balance: $%.2lf\n", other_budg - other_blnc[i]);
      printf("Entertainment balance: $%.2lf\n", etmt_budg - etmt_blnc[i]);
    }
    else if (!(strcmp(usrin, "exit"))) {
      exit(1);
    }
  }
}

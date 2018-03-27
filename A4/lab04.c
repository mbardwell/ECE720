#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "memory1.h"

#define MAX_DATA_SIZE 10
#define MAX_USR_LEN 16
int exit_flag = 1;
char name[MAX_USR_LEN];
char usrin[MAX_USR_LEN];

void processing(float local_buffer[]);

int main(void) {
  printf("Please enter a name under %d characters: ", MAX_USR_LEN);
  scanf("%s", name);

  while(exit_flag) {
    /* Data collection and processing */
    generate_data();
    float* local_buffer = reading();
    // Front load local_buffer
    processing(local_buffer);
    // Write proper values from local_buffer to output
    float* output_buffer = writing(local_buffer);
    // output display_buffer if the user doesnt indicate anything else
    display_buffer(output_buffer);

    /* Input collection and processing */
    printf("Do you want to continue or exit? ");
    scanf("%s", usrin);
    while (1) {
      if (!strcmp(usrin, "exit")) {
        exit_flag = 0;
        break;
      }
      else if (!strcmp(usrin, "continue")) {
        break;
      }
      else
      {
       printf("Please enter exit or continue\n");
       scanf("%s", usrin);
      }
    }
  }
}

void processing(float local_buffer[]) {
  printf("Processing Data: \n");
  int no_of_data_points = local_buffer[0];
  int function_ID = local_buffer[1];
  if (function_ID == 1) {
    float min = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      if (local_buffer[i] < min) {
        min = local_buffer[i];
      }
    }
    local_buffer[2] = min;
  }
  else if (function_ID == 2) {
    float max = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      if (local_buffer[i] > max) {
        max = local_buffer[i];
      }
    }
    local_buffer[2] = max;
  }
  else if (function_ID == 3) {
    float sum = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      sum = sum + local_buffer[i];
    }
    float avg = sum/no_of_data_points;
    local_buffer[2] = avg;
  }
  else if (function_ID == 4) {
    float min = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      if (local_buffer[i] < min) {
        min = local_buffer[i];
      }
    }
    float max = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      if (local_buffer[i] > max) {
        max = local_buffer[i];
      }
    }
    float sum = local_buffer[2];
    for (int i = 3; i < no_of_data_points+2; i++) {
      sum = sum + local_buffer[i];
    }
    float avg = sum/no_of_data_points;
    local_buffer[2] = min;
    local_buffer[3] = max;
    local_buffer[4] = avg;
  }
  else {
    printf("Invalid function ID");
    exit(1);
  }
  // for (int i = 0; i < no_of_data_points + 1; i++) printf("Local buffer: %f\n", local_buffer[i]);
}

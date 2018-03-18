#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* to initialize your random generator */
#define MIN_DATA_SIZE 2
#define MAX_DATA_SIZE 10
#define OUTPUT_BUFF_MAX_SIZE 4

float input_buffer[MAX_DATA_SIZE+2] = {0};
float output_buffer[OUTPUT_BUFF_MAX_SIZE] = {0};
float local_buffer[MAX_DATA_SIZE+2] = {0};
int no_of_data_points, function_ID;
// a function for generating data size, function ID and
// all data, and putting all of it into input_buffer
void generate_data(float input_buffer[]);
// a function for copying the content of input_buffer into local buffer
void reading(float input_buffer[], float local_buffer[]);
// a function for processing the content of local buffer;
// it reads function_ID and number of data points from
// local_buffer, and saves the results also into local_buffer
void processing(float local_buffer[]);
// a function for copying the content of local_buffer to the
// output_buffer (according to the pattern explained earlier)

void writing(float local_buffer[], float output_buffer[]);
// a function for clearing the buffers each iteration
void clearbuffers(float input_buffer[], float local_buffer[], float output_buffer[]);

int main(void) {
  srand(time(NULL));
  generate_data(input_buffer);
  reading(input_buffer, local_buffer);
  processing(local_buffer);
  writing(local_buffer, output_buffer);
  clearbuffers(input_buffer, local_buffer, output_buffer);
}
/* place for your definitions of functions*/
void generate_data(float input_buffer[]) {
  printf("Generating Data: \n");
  no_of_data_points = MIN_DATA_SIZE + rand() % (MAX_DATA_SIZE + 1 - MIN_DATA_SIZE);
  input_buffer[0] = no_of_data_points;
  input_buffer[1] = 1 + rand() % (4+1-1);
  for (int i = 2; i < no_of_data_points + 2; i++) {
    input_buffer[i] = (float)rand()/RAND_MAX;
  }
  for (int i = 0; i < no_of_data_points + 2; i++) printf("Input buffer: %f\n", input_buffer[i]);
}

void reading(float input_buffer[], float local_buffer[]) {
  printf("Reading Data: \n");
  local_buffer[0] = input_buffer[1];
  for (int i = 1; i < no_of_data_points+1; i++) {
    local_buffer[i] = input_buffer[i+1];
  }
  for (int i = 0; i < no_of_data_points + 2; i++) printf("Input buffer: %f\n", input_buffer[i]);
  for (int i = 0; i < no_of_data_points + 1; i++) printf("Local buffer: %f\n", local_buffer[i]);
}

void processing(float local_buffer[]) {
  printf("Processing Data: \n");
  function_ID = local_buffer[0];
  if (function_ID == 1) {
    float min = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      if (local_buffer[i] < min) {
        min = local_buffer[i];
      }
    }
    local_buffer[1] = min;
  }
  else if (function_ID == 2) {
    float max = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      if (local_buffer[i] > max) {
        max = local_buffer[i];
      }
    }
    local_buffer[1] = max;
  }
  else if (function_ID == 3) {
    float sum = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      sum = sum + local_buffer[i];
    }
    float avg = sum/no_of_data_points;
    local_buffer[1] = avg;
  }
  else if (function_ID == 4) {
    float min = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      if (local_buffer[i] < min) {
        min = local_buffer[i];
      }
    }
    float max = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      if (local_buffer[i] > max) {
        max = local_buffer[i];
      }
    }
    float sum = local_buffer[1];
    for (int i = 2; i < no_of_data_points+1; i++) {
      sum = sum + local_buffer[i];
    }
    float avg = sum/no_of_data_points;
    local_buffer[1] = min;
    local_buffer[2] = max;
    local_buffer[3] = avg;
  }
  else {
    printf("Invalid function ID");
    exit(1);
  }
  for (int i = 0; i < no_of_data_points + 1; i++) printf("Local buffer: %f\n", local_buffer[i]);
}

void writing(float local_buffer[], float output_buffer[]) {
  printf("Writing Data: \n");
  for (int i = 0; i < no_of_data_points + 1; i++) printf("Local buffer: %f\n", local_buffer[i]);
  output_buffer[0] = local_buffer[0];
  if (output_buffer[0] == 1) {
    output_buffer[1] = local_buffer[1];
    for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
    // printf("Function ID: %.0f\n", output_buffer[0]);
    // printf("Min: %f\n", output_buffer[1]);
  }
  else if (output_buffer[0] == 2) {
    output_buffer[1] = local_buffer[1];
    for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
    // printf("Function ID: %.0f\n", output_buffer[0]);
    // printf("Max: %f\n", output_buffer[1]);
  }
  else if (output_buffer[0] == 3) {
    output_buffer[1] = local_buffer[1];
    for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
    // printf("Function ID: %.0f\n", output_buffer[0]);
    // printf("Avg: %f\n", output_buffer[1]);
  }
  else if (output_buffer[0] == 4) {
    output_buffer[1] = local_buffer[1];
    output_buffer[2] = local_buffer[2];
    output_buffer[3] = local_buffer[3];
    for (int i = 0; i < 4; i++) printf("Output buffer: %f\n", output_buffer[i]);
    // printf("Function ID: %.0f\n", output_buffer[0]);
    // printf("Min: %f\n", output_buffer[1]);
    // printf("Max: %f\n", output_buffer[2]);
    // printf("Avg: %f\n", output_buffer[3]);
  }
}

void clearbuffers(float input_buffer[], float local_buffer[], float output_buffer[]) {
  printf("Clearing Data: \n");
  for (int i = 0; i < no_of_data_points + 2; i++) {
    input_buffer[i] = 0.0;
    local_buffer[i] = 0.0;
  }
  for (int i = 0; i < 4; i++) {
    output_buffer[i] = 0.0;
  }
  for (int i = 0; i < no_of_data_points + 1; i++) printf("Input buffer: %f\n", input_buffer[i]);
  for (int i = 0; i < no_of_data_points + 1; i++) printf("Local buffer: %f\n", local_buffer[i]);
  for (int i = 0; i < 4; i++) printf("Output buffer: %f\n", output_buffer[i]);
}

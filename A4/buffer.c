/**********************************************************/
/*                       BUFFER.C                         */
/**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* to initialize your random generator */
#include "buffer.h" // Put buffer in C:\MinGW\include
#include "memory1.h"

float *input_buffer;
float *output_buffer;

void generate_data() {
  printf("Generating Data: \n");
  // Init random number generator
  srand(time(NULL));
  int no_of_data_points = MIN_DATA_SIZE + rand() % (MAX_DATA_SIZE + 1 - MIN_DATA_SIZE);
  input_buffer = (float *)my_malloc((no_of_data_points+2)*sizeof(float));
  input_buffer[0] = no_of_data_points;
  input_buffer[1] = 1 + rand() % (4+1-1);
  for (int i = 2; i < no_of_data_points + 2; i++) {
    input_buffer[i] = (float)rand()/RAND_MAX;
  }
  // for (int i = 0; i < no_of_data_points + 2; i++) printf("Input buffer: %f\n", input_buffer[i]);
  // printf("memory address input %llu \n", (unsigned long long)input_buffer);
}

float *reading(){
  printf("Reading Data: \n");
  float *buffer;
  int buffersize = (input_buffer[0]+2)*sizeof(float);
  buffer = (float *)my_malloc(buffersize);
  for (int i = 0; i < input_buffer[0]+2; i++) {
    buffer[i] = input_buffer[i];
  }
  // for (int i = 0; i < input_buffer[0]+2; i++) printf("Local buffer: %f\n", buffer[i]);
  // printf("memory address local %llu \n", (unsigned long long)buffer);
  my_free(input_buffer);
  return buffer;
}
//
float *writing(float local_buffer[]) {
    printf("Writing Data: \n");
    switch ((int)local_buffer[1]) {
      case 1:
        output_buffer = (float *)my_malloc(2*sizeof(float));
        output_buffer[0] = local_buffer[1];
        printf("local buffer [1] %f\n", local_buffer[1]);
        output_buffer[1] = local_buffer[2];
        break;
      case 2:
        output_buffer = (float *)my_malloc(2*sizeof(float));
        output_buffer[0] = local_buffer[1];
        output_buffer[1] = local_buffer[2];
        break;
      case 3:
        output_buffer = (float *)my_malloc(2*sizeof(float));
        output_buffer[0] = local_buffer[1];
        output_buffer[1] = local_buffer[2];
        break;
      case 4:
        output_buffer = (float *)my_malloc(4*sizeof(float));
        output_buffer[0] = local_buffer[1];
        output_buffer[1] = local_buffer[2];
        output_buffer[2] = local_buffer[3];
        output_buffer[3] = local_buffer[4];
        break;
      default:
        printf("Invalid local buffer variable\n");
    }
    my_free(local_buffer);
    return output_buffer;
}

void display_buffer(float output_buffer[]) {
  switch ((int)output_buffer[0]) {
    case 1:
      for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
      break;
    case 2:
      for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
      break;
    case 3:
      for (int i = 0; i < 2; i++) printf("Output buffer: %f\n", output_buffer[i]);
      break;
    case 4:
      for (int i = 0; i < 4; i++) printf("Output buffer: %f\n", output_buffer[i]);
      break;
    default:
      for (int i = 0; i < 4; i++) printf("Output buffer: %f\n", output_buffer[i]);
  }
  my_free(output_buffer);
}

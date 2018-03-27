/**********************************************************/
/*                       BUFFER.H                         */
/**********************************************************/

#ifndef buffer_h
#define buffer_h

#define MIN_DATA_SIZE 2
#define MAX_DATA_SIZE 10

void generate_data();
float *reading();
float *writing(float local_buffer[]);
void display_buffer(float output_buffer[]);

#endif /* buffer_h */

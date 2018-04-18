/**********************************************************/
/*                       MEMORY.C                         */
/**********************************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "memory1.h"

static long counter=0;

void *my_malloc(int size)
{
    long *ptr;
    long amount;

    amount = (long)((long)size + sizeof(long));

    ptr = (long *)malloc(amount);
    *ptr = amount;
    ptr++;

    counter = counter + amount;
    printf("*** malloc: total #bytes taken from system: %ld\n", counter);

    return (void *)ptr;
}


void my_free(void *ptr) // void *ptr means the pointer can be of any type
{
    long amount;
    long *size_ptr;

    size_ptr = (long *)ptr;
    size_ptr--; // Backup 4 bytes in memory

    amount = *size_ptr;
    counter = counter - amount;
    printf("*** free: total #bytes own to system: %ld\n", counter);
    free((void *)size_ptr);
}


#include <stdio.h>

// #####################################
//   this part has to be put
//   at the very top of your program file
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float rand_own(long *idum);

// #####################################



int main(void)
{
    long seed;
    float random;

    // #####################################
    // an example how to use the function
    // #####################################

    // the value of variable seed
    // initializes the random number generator
    // feel free to use any negative integer value you want
    seed = -10;
    rand_own(&seed);

    // every time you use the generator
    // please use the same value of seed
    // that you used to initialize the generator
    random = rand_own(&seed);
    random = rand_own(&seed);
    random = rand_own(&seed);

    return 0;

}



// #####################################
// put the definition of the function at
// at the end of your program file
//
// the code is from Numerical Recipes in C
// Chapter 7, page 280
//
// “Minimal” random number generator of Park and Miller with Bays-Durham shuffle and added safeguards.
//  Returns a uniform random deviate between 0.0 and 1.0 (exclusive of the endpoint values).
//  Call with idum a negative integer to initialize; thereafter, do not alter idum between successive deviates in a sequence.
//  RNMX should approximate the largest floating value that is less than 1.

float rand_own(long *idum)
{
    int j;
    long k;
    static long iy=0;
    static long iv[NTAB];
    float temp;

    if (*idum <= 0 || !iy) {
        if (-(*idum) < 1) *idum=1;
        else *idum = -(*idum);
        for (j=NTAB+7;j>=0;j--) {
            k=(*idum)/IQ; *idum=IA*(*idum-k*IQ)-IR*k;
            if (*idum < 0)
                *idum += IM;
            if (j < NTAB)
                iv[j] = *idum;
        }
        iy=iv[0]; }
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;
    if (*idum < 0)
        *idum += IM;
    j=(int)(iy/NDIV);
    iy=iv[j];
    iv[j] = *idum;
    if ((temp=(float)AM*iy) > (float)RNMX)
        return (float)RNMX;
    else
        return temp;
}
// #####################################

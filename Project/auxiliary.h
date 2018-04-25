#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "memory1.h"
using namespace std;

#define TRAININGSIZE 100
#define NOINPUTS 2
#define NOOUTPUTS 1
#define LEARNINGRATE 0.1
#define VERBOSE 1

double ** readfile();

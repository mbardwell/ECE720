#include "perceptron.h"
#include "memory1.c"

Foo::Foo(double bar)
{
   cout << bar << endl;
   my_malloc(bar);
}

void Foo::test() {
}

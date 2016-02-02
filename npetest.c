#include "types.h"
#include "stat.h"
#include "user.h"

// lab2

int
main(int argc, char *argv[])
{
  printf(2, "Running Null Pointer Tests...\n");

  int a = 5;
  int *p = (void*)0;

  printf(2, "Testing valid data\n");
  printf(2, "a is: %d\n", a);
  printf(2, "Testing for NPE now...\n");
  printf(2, "p is: %d\n", &p);
  printf(2, "NPE passed\n");

  exit();
}

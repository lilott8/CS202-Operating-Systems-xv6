#include "types.h"
#include "stat.h"
#include "user.h"

// lab2

int
main(int argc, char *argv[])
{

  if(argc != 2) {
    printf(2, "npetest [even|odd number]\n");
    exit();
    return 0;
  }

  int dec = atoi(argv[1]);
  
  printf(2, "Running Null Pointer Tests...\n");

  int a = 5;
  int *p = (void*)0;


  printf(2, "Testing valid data\n");
  printf(2, "a is: %d\n", a);
  
  printf(2, "Testing for NPE now...\n");
  if(dec % 2 == 0){
    printf(2, "testing with a syscall\n");
    sleep(*p);
  } else {
    printf(2, "p is pointing to %d\n", *p);
  }
  // should never get here!
  printf(2, "NPE passed\n");

  exit();
}

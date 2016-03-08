#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"


void print537(char * five){
  printf(1, "cs %s\n", *five);
  exit();
}

  int
main(int argc, char *argv[])
{
  int pid;
  char * arg = "five";
  void ** stack = malloc(4096);
  //void ** stack2 = malloc(4096);

  printf(1, "testing...\n");
  // printf(1, "user printf stack %p, stack2 %p\n", stack, stack2);

  pid = clone((void *) &print537, (void *) &arg, (void *) *stack);
  printf(1, "user pid: %d\n", pid);

  //printf(1, "jpid %d\n", join((void **) stack));

  printf(1, "joined\n");
  exit();
  return 0;
}

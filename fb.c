#include "types.h"
#include "stat.h"
#include "user.h"

#define MAX_FORKS 10

// lab1-2

int
main(int argc, char *argv[]) {
  printf(2, "Running forkbomb\n");

  int pid;

  for(int x = 0; x <  MAX_FORKS; x++) {
    pid = fork();
    if(pid < 0) {}
  }

  exit();
}

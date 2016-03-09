#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "thread.h"
#include "mmu.h"

typedef struct __args {
  int *throws;
  int *counter;
  struct tinfo *lock;
} thread_args;

void frisbee(void * five){
  printf(1, "I'm here!!!\n");
}

  int
main(int argc, char *argv[])
{

  int pid;
  int threads = 0;
  int throws = 0;
  thread_args args;

  if(argc != 3) {
    throws = 4;
    threads = 4;
  } else {
    throws = atoi(argv[2]);
    threads = atoi(argv[1]);
  }

  printf(2, "Using %d throws with %d threads\n", throws, threads);

  struct tinfo lock;
  init_lock(&lock);

  args.throws = &throws;
  args.lock = &lock;
  args.counter = 0;

  for(int x = 0;x < threads; x++) {
    pid = thread_create((void *) &frisbee, (void *) &args);
  }

  thread_join();

  if(throws >0 || pid > 0) {

  }

  printf(1, "joined\n");
  exit();
  return 0;
}

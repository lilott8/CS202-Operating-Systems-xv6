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
  struct lock_t *lock;
} thread_args;

void frisbee(void *args){
  thread_args *arg = (thread_args*)args;

  for(int x=0; x<*arg->throws;x++){
    lock_acquire(arg->lock);
    (*arg->counter) += 1;
    printf(2, "Fly, my loving morning dove!\n");
    lock_release(arg->lock);
  }
}

  int
main(int argc, char *argv[])
{

  int pid;
  int threads = 0;
  int throws = 0;
  thread_args args;

  if(argc != 3) {
    throws = 3;
    threads = 3;
  } else {
    throws = atoi(argv[2]);
    threads = atoi(argv[1]);
  }

  printf(2, "Using %d throws with %d threads\n", throws, threads);

  struct lock_t lock;
  init_lock(&lock);

  args.throws = &throws;
  args.lock = &lock;
  args.counter = 0;

  for(int x = 0;x < threads; x++) {
    pid = thread_create((void *) &frisbee, (void *) &args);
  }

  for(int x = 0; x < threads; x++) {
    thread_join();
  }

  if(pid > 0) {

  }

  printf(1, "joined\n");
  exit();
}

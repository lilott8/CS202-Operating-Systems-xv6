#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"
#include "thread.h"
/**
 * Lab3
 */
struct lock_t lock;

/**
 * Initialize our thread lock variable
 */
void tinit(struct lock_t *locked) {
  locked->lock_hold = 0;
}

/**
 * Create the thread and tell it to start executing
 * at the function pointer "start" with a stack
 * size of "size" (typically not more than the
 * defined PGSIZE system variable
 */
int thread_create(void*(*start) (void*), void *arg) {
  // allocate the stack frame with malloc
  void *stack = malloc(PGSIZE);
  // clone the process using our new stack
  // as the address space for the thread
  // clone is function start, args, stack
  int thread = clone(arg, stack);

  // make sure we properly cloned
  // process before we start execution
  if(!thread) {
    // execute starting here!
    (*start)(arg);
  }
  return thread;
}

/**
 * Wait for the previous threads to finish
 * before we progress
 */
void thread_join() {
  wait();
}
/**
 * Wrappers for acquiring the atomic spin
 * locks that are required.  These behave
 * exactly as the specifications require
 * but leverage the simplicity of XV6
 * to handle the complexity.
 */
void init_lock(struct lock_t *locked) {
  locked->lock_hold = 0;
}

void lock_acquire(struct lock_t *locked) {
  // unfortunately, user.h and defs.h
  // have conflicting definitions of 
  // certain methods and are mutually
  // exclusive, thus, I must rip out
  // some funrtionality of the acquire()
  // method from spinlock
  while(xchg(&locked->lock_hold, 1) != 0)
    ;
}

void lock_release(struct lock_t *locked) {
  // please see note in "lock_acquire"
  xchg(&locked->lock_hold, 0);
}

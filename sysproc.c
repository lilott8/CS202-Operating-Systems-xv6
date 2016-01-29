#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "tickets.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// lab1-2
int
sys_lottery(void)
{
  struct tstat *dist[NPROC] = {};
  
  getdistribution(*dist);
 
  cprintf("ticks: %d\n", sys_uptime());
  //for(int x;x<NPROC;x++) {
  //  cprintf("%s|%d|%d|%d\n", dist[x]->name, dist[x]->pid, dist[x]->totaltickets, dist[x]->numexecuted);
  //}
 
  return 0; 
}

// lab1-2
int sys_modtickets(void)
{
  int pid;
  int quantity;

  if(argint(0, &pid) < 0) {
    return -1;
  }
  
  // if we cannot read the quantity, add the default
  argint(INCREMENT_TICKETS, &quantity);
  
  quantity = SUPER_ADD;

  if(modifytickets(pid, quantity) != -1) {
    return 1;
  } else {
    return -1;
  }
}

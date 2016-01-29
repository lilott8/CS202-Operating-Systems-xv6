#define MAX_TICKETS INT_MAX
#define SEED_TICKETS 5
#define INCREMENT_TICKETS 5
#define DECREMENT_TICKETS 1
#define SUPER_ADD 1000

struct tstat {
  int pid;
  char name[16]; 
  int numtickets;
  int numexecuted;
  int totaltickets;
};

struct tstat results[NPROC];

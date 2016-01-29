#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv []) {

  if(argc < 3) {
    printf(2, "Usage: modifytickets [pid] [quantity]\n");
    exit();
  }

  int pid = atoi(argv[1]);
  int quantity = atoi(argv[2]);

  int res = modtickets(pid, quantity);

  if(res == 1) {
    printf(2, "Successfully modified %d's tickets by %d\n", pid, quantity);
  } else {
    printf(2, "No pid by %d\n", pid);
  }

  exit();
}

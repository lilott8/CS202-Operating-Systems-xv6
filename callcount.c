#include "types.h"
#include "user.h"
#include "stat.h"

int
main(int argc, char *argv[])
{
	int pid;
	if(argc < 2) {
		printf(1, "usage: callcount pid\n");
		exit();
	}

	pid = atoi(argv[1]);

	printf(2, "Call count for pid %d is %d\n", pid, callcount(pid));
	exit();
}

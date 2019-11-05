#include "my.h"
int main()
{
	char *arg[]={"./test1","123","hello","World",NULL};
	printf("caller3 pid = %d,ppid = %d\n",getpid(),getppid());
	execv("/home/workbench/week9/code/test/test1",arg);
	printf("After callering!\n");
	return 0;
}

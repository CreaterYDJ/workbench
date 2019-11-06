#include "my.h"
int main()
{
	printf("caller3 pid = %d,ppid = %d\n",getpid(),getppid());
	execl("/home/workbench/week9/code/test/test1","./test1","123","hello","World",NULL);
	printf("After callering!\n");
	return 0;
}

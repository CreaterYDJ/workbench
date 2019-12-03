#include "my.h"

void sigfun(int signo)
{
	switch(signo)
	{
		case 1:
			printf("Catch SGIHUP!");
			break;
		case 2:
			printf("Catch SIGINT");
			break;
		case 3:
			printf("Catch QUIT");
			break;
	}
}
int main()
{
	printf("test pid:\n",getpid());
	while(1)
		;
	return 0;
}

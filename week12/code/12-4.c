#include "my.h"
int main()
{
	pid_t pid;
	int r,status;
	pid=fork();
	if(pid<0)
	{
		perror("failed fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child %d is running!\n",getpid());
		printf("child will exit!\n");
		exit(20);
	}
	else
	{
		printf("parent waiting child %d to exit!\n",pid);
		while((r=wait(&status))!=-1)
		{
			if(WIFEXITED(status))
			printf("child %d is finished with exit mode.exit code=%d\n",r,WEXITSTATUS(status));
			else if(WIFEXITED(status))
				printf("child %d is finished with signed mode.signed code=%d\n",r,WTERMSIG(status));
			else
				printf("child is finished with unkonw mode");					
		}
		
		printf("parent %d is running!\n",getpid());
		return 0;
	}
}

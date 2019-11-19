#include "my.h"

int g=10;
int main()
{
	int t = 20;
	int status;
	//pid = fork();
	static int s=30;
	pid_t pid;
	pid = vfork();
	if(pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("before child pid = %d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
		g=100;
		t=200;
		s=300;
		execl("./test.c","test","");
		printf("after child pid = %d:&g=%d,&t=%d,&s=%d\n",getpid(),g,t,s);
		//sleep(3);
		//_exit(0);
		//exit(119);
		return 0;
	}
	else
	{
		//wait(&status);					//vfork() cancel
		//printf("exit code from child is %d\n",WEXITSTATUS(status));			//vfork() cancel
		printf("after child pid = %d:&g=%d,&t=%d,&s=%d\n",getpid(),g,t,s);
		sleep(3);
		//_exit(0);
		//return 0;
	}
	else
	{
		printf("parent pid = %d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
		printf("parent pid = %d:&g=%d,&t=%d,&s=%d\n",getpid(),g,t,s);
		return 0;
	}
}

#include "my.h"

void *foo(void * arg)
{
	printf("thread is running!\n");
	return (void *)0;
}
int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,foo,NULL);
	if(ret)
	{
		perror("create failed!");
		exit(1);
	}
	//pthread_join(tid,NULL);		//foo()先行于main()
	pthread_detach(tid);			//main()先行于foo()
	printf("Master Done!");
	sleep(5);
	return 0;
}

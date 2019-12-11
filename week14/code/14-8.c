#include "my.h"
int arg=0;
void * foo(void *v)
{
	struct sl* k = (struct sl*)v;
	int n=(int)v;
	arg++;
	*(k->sum)=(int *)malloc(sizeof(int));
	printf("%d : global arg= %d\n",n,arg);
	for(arg=0;k->n<=(n+1)*100;k->n++)
		*(k->sum)+=k->n;
	int arg;
	arg=n*100;
	printf("%d : local arg= %d,sum%d\n",n,arg,*(k->sum));
	pthread_exit((void *)(k->sum));
}
int main()
{
	pthread_t tid[NUM];
	int rev[NUM],**pt;
	for(int i=0;i<NUM;i++)
	{
		rev[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
		if(rev[i]!=0)
		{
			perror("thread failed!\n");
			exit -1;
		}
		pthread_join(tid[i],(void **)&pt);
		printf("master %d: arg= %d,sum=%d \n",i,arg,*pt);
	}
}

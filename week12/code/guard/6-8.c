#include <stdio.h>
#include <time.h>
#include <unistd.h>
void init_daemon(void);
int main()
{
	FILE *fp;
	time_t t;
	init_deamon();
	while(1)
	{
		sleep(10);
		if((fp==fopen("6-8.log","a"))>=0)
		{
			t=time(0);
			fprintf(fp,"guard process still running,time is:%s",asctime(localtime(&t)));
			fclose(fp);
		}
	}
}

#include "my.h"

int main()
{
	FILE *fp;
	char ch;
	int pid1,pid2,pid3,status,rv;
	fp = fopen("file.dat","w+");
	pipe(fd);
	pid1=fork();
	if(pid1<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid1==0)
	{
		printf("child1 write in file!\n");
		writeFile(fp);
		printf("child1 pid=%d\n",getpid());
		
		exit(1);
	}
	else
	{
		printf("parent fork child2!\n");
		pid2=fork();
		if(pid2<0)
		{
			perror("fork failed!\n");
			return -1;
		}	
		else if(pid2==0)
		{			
			printf("child2 write in file!\n");
			writeFile(fp);
			printf("child2 pid=%d\n",getpid());
			sleep(3);
			exit(99);
		}
		else
		{
			printf("parent fork child3!\n");
			pid3=fork();
			if(pid3<0)
			{	
				perror("fork failed!\n");
				return -1;
			}	
			else if(pid3==0)
			{
				printf("child2 write in file!\n");
				writeFile(fp);
				printf("child3 pid=%d\n",getpid());
				sleep(2);
				exit(108);
			}
			else
			{
				pid1=wait(&s1);
				wait(pid2);
				printf("parent waiting child end!\n");
				rv=wait(&status);
				printf("1.child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
				rv=0;
				status=0;
				rv=waitpid(pid1,&status,0);
				printf("2.child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
				rv=0;
				status=0;
				rv=waitpid(pid2,&status,WNOHANG);
				printf("3.child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
				fp = fopen("file.dat","r");
				while((ch=fgetc(fp))!=EOF)
        			fputc(ch,stdout);
				fclose(fp);
				return 0;
			}
		}
	}
}
	
	

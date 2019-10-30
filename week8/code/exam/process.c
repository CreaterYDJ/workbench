#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	extern char **environ;
	int i=0;
	for(;environ[i];i++)
	{
		printf("%s\n",environ[i]);
	}
	printf("\nuse getenv/putenv:%s\n",getenv("PATH"));
	return 0;
}

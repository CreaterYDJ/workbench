#include "staticlib.h"
#include <stdio.h>
int main()
{
	int n = 10;
	int a[n];
	initarray(a,n);
	showarray(a,n);
	printf("max = %4d\n",max(a,n));
	printf("sum = %4d\n",sum(a,n));
	return 0;
}

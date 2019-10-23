#include <stdio.h>
#include "dylib.h"
int main()
{
	int n = 10;
	int a[n];
	init(a,n);
	show(a,n);
	printf("max = %4d\n",max(a,n));
	printf("sum = %4d\n",sum(a,n));
	return 0;
}

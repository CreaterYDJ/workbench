#include"uhead.h"

int main(){
    struct result ret;
    int a[NUMBER],b[NUMBER],c[NUMBER];
	
    double t1,t2;
    char str1[]="./random.dat";//用来存放随机之后的数组的文件名
    char str2[]="./syssort.dat";//用来存放系统排序之后的数组的文件名
    char str3[]="./usort.dat";//用来存放冒泡排序之后的数组的文件名
    uround(a,NUMBER);
    printf("------生成随机数开始-----\n");
    ret=uoprater(a,NUMBER);
    printf("------生成随机数结束-----\n");
    show(a,NUMBER);
    printf("\n平均数为:%f,所有随机数的和为:%ld\n",ret.average,ret.sum);
    uwrite("random.dat",a,NUMBER);
    uread("random.dat",b,NUMBER);
    printf("------开始系统内置排序------\n");
    t1=calculate_time();
    syssort(b,NUMBER);
    t1=calculate_time()-t1;
    printf("------系统内置排序结束------用时:%f secs\n",t1);
    uwrite("syssort.dat",b,NUMBER);
    uread("random.dat",c,NUMBER);
    printf("------开始自写冒泡排序------\n");
    t2=calculate_time();
    usort(c,NUMBER);
    t2=calculate_time()-t2;
    printf("------自写冒泡排序结束------用时:%f secs\n",t2);
    uwrite("usort.dat",c,NUMBER);
    printf("\n------开始查看文件中数组------\n");
    system("cat random.dat");
    system("cat syssort.dat");
    system("cat usort.dat");
    printf("\n------查看文件动作结束------\n");
    return 0;
}

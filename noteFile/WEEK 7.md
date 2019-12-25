# WEEK 7

fork()多返回值函数
父---子进程的PID（进程号）
子---0

int main()
{
  pid_t id; //pid_t数值类型为int的宏
}
---复制子进程（将父进程在执行fork（）前的数据情况和完整的代码复制给子进程）

父子进程拥有相同的代码，但可通过fork（）返回不同的值，子进程拥有不同的代码段

char *buf[]={'1','2','3','4'};
int main()
{
  ...
  write(buf->stdout);
  printf("ABCDEF");
  fork()
}

./testbuf>out.dat（输出转向）
# WEEK10

进程结束：系统
          exit()清缓存->关设备 ->退出
          _exit()退出
          用户
          return()
          
vfork()
早期fork()没有使用cow技术，由于需分配大量资源派生进度慢。
子进程运行在父进程的环境中，没有资源复制。
子进程中exec、exit时，才发生父子分家，即为子进程独立分配资源
vfork()之后一定是子进程先行，父阻塞
vfork()中子进程结束只能使用：
_exit()✔
exit✔
return❌

exit()
_exit()
atexit()
return
语言级glibc库提供
在main函数中与exit等效
非main函数中return全释放

A->B中间的过程
destructer->保存A的断点信息{系统上下文、用户上下文}
/proc/sys/kernel/
constructer为B初始化/恢复运行环境

fork()
vfork()->do_fork()
clone()

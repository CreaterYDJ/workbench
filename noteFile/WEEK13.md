# WEEK13

信号：
1）采用系统的中断机制（硬件控制）进程间通信
  由进程使用函数发送
    硬件产生消息->内核中排队转发->用户接收信息并处理进程
2）不可靠 1-31    
  32，33
  signal(signo,signfun(int))、kill(pid,signo)
    可靠34-64
  sigaction(signo,struct,void *)、raise(pid,signo)
  区别：能否被用户全部收到
  
  
PCB:
可立即处理信号集合
  1）可立即处理
  2）可阻塞
  3）可屏蔽
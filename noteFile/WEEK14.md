# WEEK14

linux只有进程、windows有进线程（2019）
线程->私有栈
可共享->代码、Text、Data、BSS、Stack

在linux中，只要存在资源共享的
进程->线程
线程(栈、PC、寄存器)
线程在相同资源环境中的不同执行轨迹

Windows->派生进程慢
Linux/Unix->派生进程快

linux:
内核线程->kthread_Create（后台、内核函数）
用户线程->pthread_Create（clone）
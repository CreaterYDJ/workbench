# WEEK 8

## Class Alpha

进程：程序（代码） 在资源集合上的一次运行过程。
程序->PC/IP
资源集合->资源表格
=code+{PCB+I/O设备+内存+CPU}

PCB：顶级表
I/O设备：用户打开设备列表(次级表)
内存：内存映射表(逻辑上连续，物理上不一定连续)
CPU：某时刻寄存器内存快照(实时内容)

ELF格式（Linux环境中二进制 PA:f(LA,t)）
用户编程仅需LA,PA内OS分配对用户不可见

系统I/O(内核级) 系统缓冲-system Buffer
标准I/O(用户级) 系统+用户-全、行、无缓冲

(1)表格->封装
(2)地址扩充->简介指引多级指针

进程->stdout、stderr->屏幕、磁盘文件(重定向)、内存(IPC匿名管道,亲缘进程)
ps aux | grep test（查看管道文件）
ps -ef（查看PID、PPID）
kill -SIGSTOP (PID)-中断进程

Bootloader(写在CMOS芯片中的BIOS)-最小基础硬件初始化-寻找系统盘的引导记录和加载记录
进程
0#-全部硬件初始化(启动)
1#-软件环境的初始化

shell->csh、bash
echo $HOME
echo $PATH

## Class Beta

类自然语言如何被计算机硬件运行
汇编->二进制语言

形式-广义二进制(所有信息二进制表示)：
内容-以硬件电路运行编码
库-可复用
内核转储文件(core dump)-调试程序运行错误
对人的思维逻辑进行编码-txt(ASCII)

编译器：gcc(Intel、MIPS)、msvc
1.词法分析：分隔符，保留关键字(区分关键字、用户自定义信息)
2.语法分析：逻辑目的(for,if) 高级语言与汇编的共同点
3.按照平台中规定的二进制文件格式分配线性地址空间

程序错误：
静态->编译器
运行->core dump(违反线性地址规则、地址耗尽)
ELF映像-map、table

进程：
code+{PCB+I/O设备+内存+CPU}
为了让PCB占用尽可能少的线性地址，对PCB中的内容分成：高频/低频
高频->用表首指针作为表的固定指针
低频->打开文件列表/地址映射表->硬盘(虚拟内存)

pagefault:
1.违反线性地址规则
OS运行->C0000000H~FFFFFFFFH
APP运行->00000000H~BFFFFFFFFH
2.堆栈握手->线性地址空间耗尽

线性地址是连续的，且功能分布区固定，逆向工程
LA=f(LA)

系统启动：

实模式-单道串行
1.cmos芯片中的BIOS程序进行自检，完成最小运行环境初始化
  ->stdin 键盘
  ->stdout 屏幕
  ->stderr 屏幕
io转向->
  (<infile)
  (>outfile)
  (>>outfile)-追加
管道在内存system区临时分配

前台模式：进程占用stdio-人机交互
后台方式：进程主动释放stdio系统 守护进程/木马

2.Bootloader
3.0#
4.1#

ELF，保护模式，多道并发，每个进程都有自己的线性地址空间
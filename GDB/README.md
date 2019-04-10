# GDB的调试记录
使用gdb xxx -tui进入调试，  
想看源码，layout src  
相看汇编，layout asm  
想看寄存器，layout regs  
想同时看汇编和源码，layout split  
想看现在打开的窗口，info win  
想要在窗口切换，可以使用focus, fs next, 或fs asm  

C/C++, 单步s(step)遇到函数跳进去，n(next)下一步，遇到函数一步跳过；  
汇编，单步si, ni
设置断点，b xxx     这里可以是函数，也可以是行数，或者是条件  
运行，r  
反汇编后面要执行的代码，set disassemble-next-line on  

简单使用：  
1、gdb xxx -tui  
2、设置break point: b main
3、run: r
4、ctrl + x, 再按2，等同layout split  (ctrl + x, 再按1; ctrl + x ，再按a)
5、如果显示混乱，ctrl + L

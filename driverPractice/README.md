# 记录Linux driver驱动的练习
## NO1_hello_driver
这个实例，列举驱动的简单编写和编译。  
编译可以有两种方式：  
1、使用cmake的方式，因为它平台无关，可以自动生成Makefile。  
源文件下编写CMakeLists.txt，新建build目录，cd build  ->  cmake ..  
这里的两点表示，使用上级目录的CMakeLists.txt。在build目录下自动生成Makefile  
已经.ko文件。
如何加载.ko?    sudo insmod hello_driver.ko
如何卸载.ko?    sudo rmmod hello_driver
如何查看已经有的module?   lsmod
如何查看kernel driver日志?  tail -f /var/log/kern.log

2、直接编写Makefile，参考hello_driver.c同级目录。


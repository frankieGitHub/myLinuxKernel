KVERS = $(shell uname -r)

obj-m += hello_driver.o
# 如果模块依赖多个文件，则使用如下
# hello_driver-objs := file1.o file2.o

build: kernel_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean

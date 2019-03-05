# ftrace介绍
https://www.cnblogs.com/arnoldlu/p/7211249.html

## 使用的注意事项：
1、需要root  
2、一般的挂载路径：
/sys/kernel/debug/tracing  
## 简单的使用步骤：
1、turn off  
echo 0 > traing_on  
2、Setting  
### trace的种类
cat available_tracers  
blk mmiotrace function_graph wakeup_dl wakeup_rt wakeup function nop  

2.1 echo function_graph > current_tracer  

### set_ftrace_filter可以查看谁调了它，也可以看它调用谁
2.2 echo sys_open:dump > set_ftrace_filter  

2.3 如果要看一个函数调用了什么，可以使用  
echo sys_open > set_graph_function  

2.4 如果要取消追踪的函数，可以使用  
echo '!sys_open' > set_ftrace_filter  

2.5 如果要追踪的不是函数，而是event，可以使用如：  
echo traceoff > events/block/block_unplug/trigger  

3、turn on  
echo 1 > traing_on  

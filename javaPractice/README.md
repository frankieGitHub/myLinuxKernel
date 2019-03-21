# 
## new的对象是如何释放的

我们经常看到这样的java函数  
```
float[] fun()
{
    float[] myTest = new float[10];

    xxxxx

    没有看到有看到有释放的地方，其实是要看这个空间指针有没有被引用，  
    如果没有被别人使用，就会被GC回收。


    有时会看到这种return，你需要看看引用的地方在什么时候被释放  
    //return myTest;
}
```

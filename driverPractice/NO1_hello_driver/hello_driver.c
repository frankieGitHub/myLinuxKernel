#include <linux/init.h>
#include <linux/module.h>

static int hello_init(void)
{
    printk(KERN_INFO "hello kernel driver!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "byebye kernel driver!\n");
}

module_init(hello_init);
module_exit(hello_exit);


#include"header.h"
#include"declarations.c"
int scullrelease(struct inode *inodep,struct file *filep)
{
printk(KERN_INFO"end:%s",__func__);
return 0;
}

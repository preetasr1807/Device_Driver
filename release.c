#include"header.h"
//#include"file_operation.h"
//int (*release) (struct inode *, struct file *);
 extern struct file_operations fops;
int scull_release(struct inode *inode, struct file *fileop)
{

printk(KERN_INFO "hello release");
return 0;
}

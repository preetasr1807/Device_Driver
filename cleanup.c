#include"header.h"
void exit_function(void)
{
	extern dev_t dev;
	extern int lv;
	extern struct SCULL_DEV *scull_dev;
	extern int nod;
	printk(KERN_INFO "Bye Kernel. But Kamal is here\n");
	for(lv=0;lv<nod;lv++)
	{
		cdev_del(&scull_dev[lv].c_dev);
	}
	unregister_chrdev_region(dev,1);
}
module_exit(exit_function);


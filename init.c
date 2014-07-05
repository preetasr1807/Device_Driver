#include"header.h"
#include"declarations.c"

int majorno,minorno;
dev_t dev;
dev_t new_dev;
int nod;
int ret,lv;
struct file_operations fops=
{
	open:scullopen,
	release:scullrelease,
	write:scullwrite,
	read:scullread,
	llseek:sculllseek
};
struct SCULL_DEV *scull_dev;
//scull_dev->rsize=0;
module_param(nod,int,S_IRUGO);
static int init_func(void)
{
	printk(KERN_INFO"hello kernel\n");
	ret=  alloc_chrdev_region(&dev,0,nod,DEV_NAME);
	if(ret<0)
	{
		printk(KERN_ERR"register char_dev failure\n");
	}
	scull_dev=(struct SCULL_DEV*)kmalloc(sizeof(struct SCULL_DEV)*nod,GFP_KERNEL);
	for(lv=0;lv<nod;lv++)
	{
		new_dev=MKDEV(dev,lv);
		cdev_init(&scull_dev[lv].c_dev,&fops);
		memset(scull_dev,'\0',sizeof(scull_dev));
		//sema_init(&scull_dev[lv].sem,1);
		init_completion(&scull_dev->comp);
		cdev_add(&scull_dev[lv].c_dev,dev,nod);
		majorno=MAJOR(scull_dev[lv].c_dev.dev);
		minorno=MINOR(new_dev);
		printk(KERN_INFO"majorno is %d ",majorno);
		printk(KERN_INFO"minorno is %d ",minorno);

	}
	return 0;

}
module_init(init_func);


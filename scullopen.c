#include"header.h"
#include"declarations.c"

/*void scull_trim(struct SCULL_DEV *lscull_dev)
{
	int flag=1,i;
	struct SCULL_QSET *prev;
	struct SCULL_QSET *lscull_qset;
	struct SCULL_QSET *start;
	printk(KERN_INFO"begin:______%s\n",__func__);
	prev=start=lscull_qset=lscull_dev->scull_qset;
	while(1)
	{
		while((lscull_qset->next) != NULL)
		{
			if(flag==1)
			{
				lscull_qset=lscull_qset->next;
				flag=0;
			}
			else
			{
				lscull_qset=lscull_qset->next;
				prev=prev->next;
			}
		}
		for(i=0;i<8;i++)
			kfree(lscull_qset->data[i]);

		kfree(lscull_qset->data);
		printk(KERN_INFO"scull_qset deleted\n");
		kfree(lscull_qset);
		prev->next=NULL;
		if(prev==start)
			break;

	}

	for(i=0;i<8;i++)
		kfree(prev->data[i]);

	kfree(prev->data);

	kfree(prev);
		kfree(lscull_dev);
		printk(KERN_INFO"scull_dev deleted\n");

}*/

int scullopen(struct inode *inodep,struct file *filep)
{
	struct SCULL_DEV *lscull_dev;
	lscull_dev=container_of(inodep->i_cdev,struct SCULL_DEV,c_dev);
	filep->private_data=lscull_dev;
	printk(KERN_INFO"begin:%s\n",__func__);
	if((filep->f_flags & O_ACCMODE)==O_WRONLY)
	{
		printk("OPEN WITH WRONLY\n");
//		scull_trim(lscull_dev);
	}
	if((filep->f_flags & O_ACCMODE)==O_RDONLY)
	{
		printk("OPEN WITH RDONLY\n");
	}
	return 0;
}

#include"header.h"
//#include"file_operation.h"
 extern struct file_operations fops;

int sculltrim(struct SCULL_DEV *);
// int (*open) (struct inode *, struct file *);
int scull_open(struct inode * inodep, struct file *filep)
{
 struct SCULL_DEV * lscull_dev;
 int ret;
 	 printk(KERN_INFO "hello open");
 
	 lscull_dev=container_of( inodep->i_cdev,struct SCULL_DEV,c_dev);

	printk(KERN_ALERT "address of lscull_dev by container of: %p\n",lscull_dev);
	 filep->private_data=lscull_dev;

	 if(  (filep->f_flags & O_ACCMODE) == O_WRONLY )
 	{
	 	 printk(KERN_INFO "module open for write only");
  
 		 ret=sculltrim(lscull_dev);
		   if(ret<0)
        		 {
			printk(KERN_ERR "errror in sculltrim()\n");
			goto OUT;

        		 }




	 }	
 return 0;

OUT: return -1;
}

int sculltrim(struct SCULL_DEV * fsculldev )
{
   struct scull_qset *lscullqset,*bptrlscullqset;
// lscullqset=bptrlscullqset;
  if(!fsculldev)
   {
    
	printk(KERN_ERR "error in fsculldev pointer");
        goto OUT;
   }

	if(!fsculldev->scullqset)
	{
	     printk(KERN_INFO "NO Scullqset");
	}

	while(bptrlscullqset->Next)
	bptrlscullqset=bptrlscullqset->Next;


return 0;

OUT: return -1;
}

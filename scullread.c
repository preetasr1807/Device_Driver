#include"header.h"
#include"declarations.c"

ssize_t scullread(struct file *filep,char __user *buff, size_t size, loff_t *loff)
{
	int noctr=0,nocsr=0,j=0,disp=0,nosqs,noq,quantum_size,qset_size;
	struct SCULL_DEV *lscull_dev;
	struct SCULL_QSET *lscull_qset;
	lscull_dev=filep->private_data;
	size=lscull_dev->data_size;
	printk(KERN_INFO"********size=%d\n",(int)size);
	/*nocsr=lscull_dev->rsize;
	printk(KERN_INFO"********nocsr=%d\n",nocsr);
	size=size+nocsr;
	printk(KERN_INFO"********size=%d\n",(int)size);*/
	lscull_qset=lscull_dev->scull_qset;
	quantum_size=8;
	qset_size=8;
	

	nosqs= size/(quantum_size * qset_size);
	if(size%(quantum_size * qset_size))
	{
		nosqs++;
	}
	printk(KERN_INFO"noqset=%d\n",nosqs);
	noq=size/quantum_size;
	if(size%quantum_size)
	{
		noq++;
	}
	printk(KERN_INFO"noq=%d\n",noq);

	noctr=size;
	printk(KERN_INFO"NOCTR=%d\n",noctr);
	j=(int)*loff/quantum_size;
	disp=(int)*loff%quantum_size;
	if((int)*loff%quantum_size)
		j++;
		noq=noq-j;
		if(j>0)
		j--;
	//	down(&lscull_dev->sem);
		wait_for_completion(&lscull_dev->comp);
	printk(KERN_INFO"kamal\n");
	if(lscull_qset)
	while(j<=quantum_size && lscull_qset->next != NULL)
	{
	printk(KERN_INFO"kamal singh\n");
		if(noq==0)
		{
			break;
		}
		if(j>7)
		{
			lscull_qset=lscull_qset->next;
			j=0;
		}
		if(noctr>quantum_size)
		{
			noctr=quantum_size;
		}
		noq--;
		
		if(lscull_qset->data[j])
		{
			copy_to_user(buff+nocsr,lscull_qset->data[j]+disp,noctr-disp);
			printk(KERN_INFO"NOCTR=%d\n",noctr-disp);
			printk(KERN_INFO"lscull_qset->data[%d]=%s\n",j,(char*)lscull_qset->data[j]+disp);

		}
		j++;

		*loff=nocsr=nocsr+noctr-disp;
		noctr=size-nocsr;

		disp=0;
		printk(KERN_INFO"buff=%s\n",buff);
	}	
	//	up(&lscull_dev->sem);
	/*lscull_dev->rsize=nocsr;
	printk(KERN_INFO"********rsize=%d\n",(int)lscull_dev->rsize);*/
	return nocsr;
}


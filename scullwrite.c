#include"header.h"
#include"declarations.c"

int creat_quantums(struct SCULL_QSET *lscullqset,int noq);
int creat_qset(struct SCULL_QSET *lscullqset,int nosqs);
struct SCULL_QSET *creat_scullqset(struct SCULL_QSET *lscullqset,int nosqs);
int quantum_size=8;
int qset_size=8;
struct SCULL_QSET *creat_scullqset(struct SCULL_QSET *lscullqset,int nosqs)

{
	int i,flag=1;
	struct SCULL_QSET *first=NULL;
	printk(KERN_INFO"begin:%s\n",__func__);
	for(i=0;i<nosqs;i++)
	{
       		lscullqset=(struct SCULL_QSET *)kmalloc(sizeof(struct SCULL_QSET),GFP_KERNEL);
		printk(KERN_INFO"lscullqset_______=%p\n",lscullqset);
		if(flag==1)
		{
			first=lscullqset;
		printk(KERN_INFO"first_______=%p\n",first);
		flag=0;
		}	
		else
		lscullqset=lscullqset->next;
		
	}
	lscullqset->next=NULL;
	return first;
}

int creat_qset(struct SCULL_QSET *lscullqset,int nosqs)
{
	int i;
	for(i=0;i<=nosqs;i++)
	{
        	lscullqset->data=kmalloc(sizeof(void *)*qset_size,GFP_KERNEL);
		lscullqset=lscullqset->next;
	}
return 0; 
}

int creat_quantums(struct SCULL_QSET *lscullqset,int noq)
{
	int i;
	for(i=0;i<=quantum_size;i++)
	{     
           if(noq==0)
		{
		break;
		}
		if(i>7)
		{
			lscullqset=lscullqset->next;
			i=0; 
		}
        	lscullqset->data[i]=kmalloc(quantum_size,GFP_KERNEL);
		printk(KERN_INFO"noq____=%d\n",noq);
		noq--;
		printk(KERN_INFO"lscullqset->data[i] = %d\n",i);
		printk(KERN_INFO"lscullqset=%p\n",lscullqset);
	}
		
return 0;	
}
ssize_t scullwrite(struct file *filep, const char __user *buffer, size_t size, loff_t *loff)
{
        int nosqs=0,noq=0,noctw=0,nocsw=0,i,n=0;
        struct SCULL_DEV *lsculldev;
 //       struct SCULL_DEV size1;
        struct SCULL_QSET *lscullqset;
	lscullqset=NULL;
//	size1.quantum_size=8;
//	size1.qset_size=8;
        lsculldev=filep->private_data;
	lsculldev->scull_qset=NULL;
	printk(KERN_INFO"size=%d\n",(int)size);
	
printk(KERN_INFO"loff=%d\n",(int)*loff);
        if(!lsculldev->scull_qset)
        {
                nosqs= size/(quantum_size * qset_size);
                if(size%(quantum_size * qset_size))
                {
                        nosqs++;
                }
		printk(KERN_INFO"noqset=%d\n",nosqs);

      		lscullqset=lsculldev->scull_qset=creat_scullqset(lscullqset,nosqs);
		creat_qset(lscullqset,nosqs);
	}
	noq=size/quantum_size;
	if(size%quantum_size)
	{
		noq++;
	}
		printk(KERN_INFO"noq=%d\n",noq);
		creat_quantums(lscullqset,noq);
	
	noctw=size;
       printk(KERN_INFO"NOCTW=%d\n",noctw);

/*while(lscullqset->next != NULL)
{
printk(KERN_INFO"lscullqset=%p\n",lscullqset);
}*/

	nocsw=0;
	n=noq;

//			down(&lsculldev->sem);
			
	for(i=0;i<=quantum_size;i++)
	{
	
		if(n==0)
		{
		break;
		}
		if(i>7 && lscullqset->next)
		{
			lscullqset=lscullqset->next;
				i=0;
		}
		if(noctw>quantum_size)
			{
			noctw=quantum_size;
			}
			printk(KERN_INFO"i++++++++++++=%d\n",i);
				n--;
			copy_from_user(lscullqset->data[i],buffer+nocsw,noctw);
			//printk(KERN_INFO"noq___in main=%d\n",n);
			printk(KERN_INFO"lscullqset->data[%d]=%s\n",i,(char*)lscullqset->data[i]);
			
			filep->f_pos=*loff=nocsw=nocsw+noctw;
			noctw=size-nocsw;
	}	
		//	up(&lsculldev->sem);
		lsculldev->data_size=nocsw;
			printk(KERN_INFO"loff=%d\n",(int)*loff);
			printk(KERN_INFO"in write fpos=%d\n",(int)filep->f_pos);
	complete(&lsculldev->comp);
return nocsw;
}


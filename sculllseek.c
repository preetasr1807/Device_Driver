#include"header.h"
#include"declarations.c"
loff_t sculllseek (struct file *filep, loff_t offset, int origin)
{
loff_t new_pos=0;

printk(KERN_INFO"begining fpos=%d\n",(int)filep->f_pos);
switch(origin)
{
case 0: printk(KERN_INFO"SEEK_SET\n");
	new_pos=offset;
	break;
case 1: printk(KERN_INFO"SEEK_CUR\n");
	new_pos=filep->f_pos+offset;
	break;
}	

filep->f_pos=new_pos;
printk(KERN_INFO"end fpos=%d\n",(int)filep->f_pos);






return new_pos;
}

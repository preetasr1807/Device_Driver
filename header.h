#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<asm-generic/uaccess.h>
#include<linux/semaphore.h>
#include<linux/wait.h>
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Module For Character Driver");
MODULE_AUTHOR ("Kamalsingh");
#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEV_NAME
#define DEV_NAME "char_drvr"
#endif
struct SCULL_QSET
{
	struct SCULL_QSET *next;
	void **data;
};

struct SCULL_DEV
{
	struct SCULL_QSET *scull_qset;
	struct cdev c_dev;
	int quantum_size;
	int qset_size;
	int data_size;
	int rsize;
//	struct semaphore sem;
	struct completion comp;
};


extern int nod,quantum_size,qset_size; 
int scullopen (struct inode *, struct file *);
int scullrelease (struct inode *, struct file *);
ssize_t scullwrite (struct file *, const char __user *, size_t, loff_t *);
ssize_t scullread (struct file *,char __user *, size_t, loff_t *);
loff_t sculllseek (struct file *, loff_t, int);
extern struct SCULL_DEV *scull_dev;

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<fcntl.h>
int fd1,rfd1;
char buffer1[]="vaily ban mitraa bde drave jarle vaily ban mitra bde drawe jarle ,sochea c o hath jorh ke gal jaan ge man yaar tere ne gaddi lelai 0001 ni vich pajero de rakh lai desi gun ni vich pajero de rakh lai desi gun.";
 char buff1[220];
void * open1(void * arg)
{
	fd1=open("kamal",O_WRONLY);
         if(fd1<0)
          {
                  perror("fd not found");
           }
	   printf("fd=%d\n",fd1);
 rfd1=open("kamal",O_RDONLY);
           if(rfd1<0)
           {
                   perror("fd not found");
           }

	   printf("rfd=%d\n",rfd1);
}
void * write1(void * arg)
{
         pthread_t thread_open;
         void * open_message;
  pthread_create(&thread_open,NULL,open1,NULL);
  pthread_join(thread_open,&open_message);
	   printf("fd=%d\n",fd1);
write(fd1,buffer1,strlen(buffer1));
}
void * read1(void * arg)
{
int new_pos;
         pthread_t thread_write;
         void * write_message;
  pthread_create(&thread_write,NULL,write1,NULL);
  pthread_join(thread_write,&write_message);
	   printf("rfd=%d\n",rfd1);
          new_pos=lseek(rfd1,0,SEEK_SET);
          printf("new_pos=%d\n",new_pos);

read(rfd1,buff1,strlen(buffer1));
printf("read data=%s\n",buff1);

}
void * close1(void * arg)
{
         pthread_t thread_read;
         void * read_message;
  pthread_create(&thread_read,NULL,read1,NULL);
  pthread_join(thread_read,&read_message);
  close(fd1);
  close(rfd1);
}

int main()
{
void *message;
pthread_t thread1;
pthread_create(&thread1,NULL,close1,NULL);
pthread_join(thread1,&message);
return 0;
}

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<fcntl.h>
int fd,rfd;
char buffer[]="hoeya ki je krne shikar chadte aje rafflaan chalaunia nai jatt bhuleyaa,kla kla vekhi gal ghut ghut mardu kamli de jhate vang farh ke khlardu,kaun khara hik taan kide doleya ch jaan ape dsuga jamin utte khun duleya,hoeya ki je krne shikar chadte aje rafflaan chalaunia nai jatt bhuleyaa.";
 char buff[290];
void * open1(void * arg)
{
	fd=open("emblogic",O_WRONLY);
         if(fd<0)
          {
                  perror("fd not found");
           }
	   printf("fd=%d\n",fd);
 rfd=open("emblogic",O_RDONLY);
           if(rfd<0)
           {
                   perror("fd not found");
           }

	   printf("rfd=%d\n",rfd);
}
void * write1(void * arg)
{
         pthread_t thread_open;
         void * open_message;
  pthread_create(&thread_open,NULL,open1,NULL);
  pthread_join(thread_open,&open_message);
	   printf("fd=%d\n",fd);
write(fd,buffer,strlen(buffer));
}
void * read1(void * arg)
{
int new_pos;
         pthread_t thread_write;
         void * write_message;
  pthread_create(&thread_write,NULL,write1,NULL);
  pthread_join(thread_write,&write_message);
	   printf("rfd=%d\n",rfd);
          new_pos=lseek(rfd,0,SEEK_SET);
          printf("new_pos=%d\n",new_pos);

read(rfd,buff,strlen(buffer));
printf("read data=%s\n",buff);

}
void * close1(void * arg)
{
         pthread_t thread_read;
         void * read_message;
  pthread_create(&thread_read,NULL,read1,NULL);
  pthread_join(thread_read,&read_message);
  close(fd);
  close(rfd);
}

int main()
{
void *message;
pthread_t thread1;
pthread_create(&thread1,NULL,close1,NULL);
pthread_join(thread1,&message);
return 0;
}

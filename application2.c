#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd,ret=1,rfd=0,new_pos,size=8;
	char *buff=malloc(300);
	rfd=open("kams",O_RDONLY);
	if(rfd<0)
	{
		perror("rfd not found");
	}
	printf("rfd=%d\n",rfd);
	
	//ret=read(rfd,buff,1);
	//printf("ret=%d\n",ret);
	//while(ret)
//	{
//	sleep(1);
//	buff=realloc(buff,size+1);
//	printf("buff=%p\n",(buff+size));
	//ret=read(rfd,buff,100);
	ret=read(rfd,buff,300);
	//printf("buff=%c\n",*(buff+size));
//	size=size+8;
	

	printf("read data=%s\n",buff);
	close(rfd);
return 0;
}

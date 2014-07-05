#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd,ret=1,rfd,new_pos;
	char buffer[]="BY KAMAL:ik kudi utte yaro aia mera dil ...pr dssna ni na ..jihdde kore nena ne churiaya ..mera dil pr dsna vi na.....goria  vi dekhian te kalia vi  dekhia kudiannnnnn...kudian bilori akhan valian vi dekhann";
	fd=open("kams",O_WRONLY);
	if(fd<0)
	{
		perror("fd not found");
		exit(-1);	
	}
	printf("fd=%d\n",fd);
	ret=write(fd,buffer,strlen(buffer));
	printf("count=%d\n",ret);
	close(fd);
return 0;
}

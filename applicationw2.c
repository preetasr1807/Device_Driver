#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd,ret=1,rfd,new_pos;
	char buffer[]="bhan nanki da veer tn mmnn da fkir ...ni oo jogian da jogi...te piraa da piir ...bhan nanki da veer....ho ho yo yo yoney ssinghhhhhh...ohde nal ne ..................bala mrdana ....rb ..";
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

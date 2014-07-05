#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd,ret,rfd,new_pos;
	char buff[177];
	char buff1[177];
	char buffer[]="Kamal preet Singh works at emblogic embedded technologies pvt ltd e-16 sector 3 Noida uutt pradesh India Asia World Earth(near about moon) Solar system Milky way galaxy Universe";
	memset(buff,'\0',177);
	fd=open("emblogic",O_WRONLY);
	if(fd<0)
	{
		perror("fd not found");
		exit(-1);	
	}
	printf("fd=%d\n",fd);
	ret=write(fd,buffer,strlen(buffer));
	printf("count=%d\n",ret);
	close(fd);
	rfd=open("emblogic",O_RDONLY);
	if(rfd<0)
	{
		perror("fd not found");
		exit(-1);	
	}
	printf("rfd=%d\n",rfd);
	new_pos=lseek(rfd,0,SEEK_SET);
	printf("new_pos=%d\n",new_pos);
	ret=read(rfd,buff,17);
	new_pos=lseek(rfd,22,SEEK_CUR);
	ret=read(rfd,buff1,177);
	printf("new_pos=%d\n",new_pos);
	printf("countr=%d\n",ret);
	printf("read data=%s\n",buff);
	printf("read data=%s\n",buff1);
	
return 0;
}

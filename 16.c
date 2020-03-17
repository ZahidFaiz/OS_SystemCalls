       #include <unistd.h>
	#include <unistd.h>

	#include<stdio.h>
	#include<string.h>
void main ()
{
	int fd1[2],fd2[2];
	char buff[50],buff1[50];
	char msg[]={"this is a message by parent"};
	char msg1[]={"this is by child"};
	pipe(fd1);
       	pipe(fd2);
	perror("");
	if (!fork())
	{
	close(fd1[0]);
	close(fd2[1]);
	write(fd1[1],msg,sizeof(msg));
	read(fd2[0],&buff1,sizeof(buff1));
	printf("%s \n",buff1);
	}
	else
	{
	close(fd1[1]);
	close(fd2[0]);
	read(fd1[0],&buff,sizeof(buff));
	write(fd2[1],msg1,sizeof(msg1));
	

	printf("%s \n",buff);
	}

}

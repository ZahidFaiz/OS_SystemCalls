       #include <unistd.h>
	#include<stdio.h>
	#include<string.h>
void main ()
{
	int fd[2];
	char buff[20];
	char msg[]={"this is a message"};
	pipe(fd); 
	perror("");
	write(fd[1],msg,sizeof(msg));
	read(fd[0],&buff,sizeof(buff));
	printf("%s",buff);
	//while(1);

}

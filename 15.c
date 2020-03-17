       #include <unistd.h>
	#include<stdio.h>
	#include<string.h>
void main ()
{
	int fd[2];
	char buff[20];
	char msg[]={"this is a message"};
	pipe(fd); 
	if(!fork())
	{

//	perror("");
	close(fd[0]);
	write(fd[1],msg,sizeof(msg));
	}
	else 
	{
	close(fd[1]);
	read(fd[0],&buff,sizeof(buff));
	printf("%s \n",buff);
//	wait (0);
	}

	getchar();
}

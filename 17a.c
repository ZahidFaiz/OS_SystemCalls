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
		close(1);
		dup(fd[1]);

		close(fd[0]);

		execlp("ls","ls","-l",NULL);
	}
	else 
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
		execlp("wc","wc",NULL);
	}

//	getchar();
}

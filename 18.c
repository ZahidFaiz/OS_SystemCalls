       #include <unistd.h>
	#include<stdio.h>
	#include<string.h>
void main ()
{
	int fd1[2],fd2[2];
	
	pipe(fd1);
       	pipe(fd2);	
	if(!fork())
	{
		close(1);
		dup2(fd1[1],1);
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);

		execlp("ls","ls","-l",NULL);
	}
	else 
	{	
		if(!fork())
		{

		close(0);
		dup2(fd1[0],0);
		close(1);
		dup2(fd2[1],1);
		close(fd1[1]);
		close(fd2[0]);
		execlp("grep","grep","^d",NULL);
		}
	

		else
		{
		close(0);
		dup2(fd2[0],0);
		close(fd2[1]);
		close(fd1[1]);
		close(fd1[0]);
		execlp("wc","wc","-l",NULL);
		}	
	}
//	getchar();
}

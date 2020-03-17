       #include <sys/types.h>
	#include <fcntl.h>
	#include <stdio.h>
	       #include <unistd.h>

       #include <sys/stat.h>
void main()
{	
	char buff[50];
	mkfifo("pipe",S_IFIFO);
	int fd2;
	
while(1)
{	
	   fd2=open("pipe",O_RDONLY);

	read(fd2,buff,sizeof(buff));

	printf("\n User1 says: %s \n",buff);
}

	
}

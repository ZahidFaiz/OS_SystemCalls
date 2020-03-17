       #include <sys/types.h>
	#include <fcntl.h>
	#include <stdio.h>
	       #include <unistd.h>
	#include<string.h>
       #include <sys/stat.h>
void main()
{	
	char buff1[50];
	int fd1;
	
	
	while(1)
{	fd1=open("pipe",O_RDONLY);
	read(fd1,buff1,sizeof(buff1));
	printf("\nUser1:%s\n",buff1);
	close(fd1);

	fd1=open("pipe",O_WRONLY);
	printf("Enter msg \n");
	scanf(" %[^\n]",buff1);
	write(fd1,buff1,sizeof(buff1));
}

	
}

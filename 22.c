	#include <sys/select.h>
	#include <sys/time.h>
        #include <sys/types.h>
        #include <unistd.h>
	#include<stdio.h>
	  #include <fcntl.h>

void main ()
{
	int retval;
	struct timeval tv;
	fd_set rfs;

	char buff[50];
	int fd1;

    	fd1=open("pipe",O_RDONLY);


	FD_ZERO(&rfs);
        FD_SET(fd1,&rfs);
	
	tv.tv_sec=10;
	tv.tv_usec=0;
	

	fd1=open("pipe",O_RDONLY);

	retval = select(fd1+1, &rfs, NULL, NULL, &tv);
	if (retval == -1)
	{   perror("select()");
	}
        else if (retval!=0)
	   {
               printf("Data is available\n");
	       read(fd1,buff,sizeof(buff));
	       printf("Other process says:%s \n",buff);
	   }
       else
	   {
	   printf("No data within ten seconds.\n");
	   }
	
}

     #include <unistd.h>
	#include <fcntl.h>

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
                fcntl(fd[1],F_DUPFD);

                close(fd[0]);

                execlp("ls","ls","-l",NULL);
        }
        else
        {
                close(0);
                fcntl(fd[0],F_DUPFD);
                close(fd[1]);
                execlp("wc","wc",NULL);
        }

//      getchar();
}


#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signum)
{
	printf("SIGTOP catched");
}

void main()
{	
	printf("pid = %d\n",getpid());
	struct sigaction sa;

	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &handler;

	sigaction(SIGSTOP,&sa,NULL);
	
	while(1);
//	printf("%d\n",t);
}

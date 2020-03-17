#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

void main ()
{
	if (!fork())
	{
		
		kill(getppid(),SIGKILL);
		printf("Orphan generated\n");
		sleep(25);
	}
	
	sleep(20);
	printf("parent generated\n");
}


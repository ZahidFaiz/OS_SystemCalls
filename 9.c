#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>



int main() {

	signal(SIGINT, SIG_IGN);
	printf("Signal is ignored for 10 seconds\nTry pressing ctrl+C to check\n");

	sleep(10);
	signal(SIGINT,SIG_DFL);

	printf("Now check again\n");
	sleep(10);

}



						

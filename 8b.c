#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void handler(int signum){
	printf("\nTry terminating ^Z then\nkill -9 <pid>:\n");
	printf("id is:\t%d\n",getpid());
}


int main() {


	signal(SIGINT, &handler);
	while (1);
}



						

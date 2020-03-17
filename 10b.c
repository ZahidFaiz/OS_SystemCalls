#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum){
	printf("\nTry terminating ^Z then\nkill -9 <pid>:\n");
	printf("id is:\t%d\n",getpid());
}

int main() {

    struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));

	action.sa_flags = SA_SIGINFO;
	action.sa_handler = handler;

	sigaction(SIGINT, &action, NULL);

	while(1)
	    sleep(1);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum){
	exit(0);
}

int main() {

    struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));

	action.sa_flags = SA_SIGINFO;
	action.sa_handler = SIG_IGN;

	sigaction(SIGINT, &action, NULL);
	printf("pressing ctrl+c has no effect for 10 seconds\n");
	
	sleep(10);
	action.sa_handler = SIG_DFL;

	sigaction(SIGINT, &action, NULL);
	printf("\nnow try pressing\n");

	sleep(200);

    return 0;
}

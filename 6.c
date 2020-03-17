#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine(int *i){
	printf("Thread no:\t%d\n",(*i+1));
}
int main() {
    pthread_t thr;
	size_t i;

	for(i=0;i<3;i++) {
	   
	   pthread_create(&thr, NULL , (void *)(&routine) , &i);
	    sleep(3);

	}
}
	//run by compiling it with -pthread

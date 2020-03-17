#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void timer_handler (int signum)
{
 static int count = 0;
 printf ("timer expired %d times\n", ++count);
}

int main ()
{

 struct itimerval timer;

 signal(SIGPROF,timer_handler);

 
 timer.it_value.tv_sec = 10;
 timer.it_value.tv_usec = 0;
 
 timer.it_interval.tv_sec = 10;
 timer.it_interval.tv_usec = 0;
 
 setitimer (ITIMER_PROF, &timer, NULL);

 
 while (1);
}

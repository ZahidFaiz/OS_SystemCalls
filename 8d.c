#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void timer_handler (int signum)
{
 printf ("alarm\n");
}

int main ()
{

 struct itimerval timer;

 signal(SIGALRM,timer_handler);
 
 alarm(10);

 sleep(15); 
}

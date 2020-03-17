#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

unsigned long long rdtsc ( )
{
unsigned long long dst;
__asm__  __volatile__ ("rdtsc":"=A" (dst));
return dst;
}

void main ()
{
	long long int start, end;
	start=rdtsc();

	for(int i=0;i<100;i++)
	{
		getppid();
	}

	end=rdtsc();
	printf("time is : \t%llu\n",end-start);
}

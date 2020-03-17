       #include <sys/time.h>
       #include <sys/resource.h>
       #include <stdio.h>

void main ()
{
	int resources[] = {RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE,
                     RLIMIT_MEMLOCK, RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_RSS,
                     RLIMIT_STACK};
	const char *names[] = {"CORE", "CPU", "DATA", "FSIZE",
                         "MEMLOCK", "NOFILE", "NPROC", "RSS",
                         "STACK"};
	int n=sizeof(resources)/4;
	struct rlimit arr[n];
	for(int i=0;i<n;i++)
	{
	getrlimit(resources[i],&arr[i]);
	printf("%s\t%lu\t%lu\n",names[i],arr[i].rlim_cur,arr[i].rlim_max);
	}
}

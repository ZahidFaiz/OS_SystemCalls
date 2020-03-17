       #include <sys/time.h>
       #include <sys/resource.h>
	#include <stdio.h>
void main ()
{
	struct rlimit arr[0];

	getrlimit(RLIMIT_FSIZE,&arr[0]);
	printf("CURRENT Maximum file size limit\t%lu\t%lu\n",arr[0].rlim_cur,arr[0].rlim_max);

	arr[0].rlim_cur=2000000;
	arr[0].rlim_max=2000000;

	setrlimit(RLIMIT_FSIZE,&arr[0]);

	getrlimit(RLIMIT_FSIZE,&arr[0]);
        printf("MODIFIED Maximum file size limit\t%lu\t%lu\n",arr[0].rlim_cur,arr[0].rlim_max);
}


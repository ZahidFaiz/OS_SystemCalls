#include<unistd.h>
#include<stdio.h>

void main()
{
	int plim,flim;
	plim=pathconf(".",_PC_PIPE_BUF);
	flim=sysconf(_SC_OPEN_MAX);


	printf("%d\n%d",plim,flim);
	
}


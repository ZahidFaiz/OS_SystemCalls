#include <unistd.h>
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

void main()
{
	long int msgid;
        
	printf("enter the message id to remove\n");
	scanf("%ld",&msgid);

	msgctl(msgid,IPC_RMID,NULL);
	printf("removed");

}

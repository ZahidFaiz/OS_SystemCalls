#include <sys/types.h>
#include <sys/ipc.h>
#include<stdio.h>
#include <sys/msg.h>

void main ()
{
	key_t key;
	int msgid;
	key=ftok(".",'b');
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0743);
	perror("");
	printf("%d",msgid);
}


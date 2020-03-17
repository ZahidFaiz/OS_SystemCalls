#include <sys/types.h>
#include <sys/ipc.h>
#include<stdio.h>
#include <sys/msg.h>
#include <string.h>

void main ()
{
	key_t key;
	int msgid;
	key=ftok(".",'b');
	struct msg
	{
	
	long int mtype;
	char msgp[80];
	}		mq;

	
	mq.mtype=1;

	printf("message:\n");
	scanf(" %[^\n]",mq.msgp);

	msgid=msgget(key,IPC_CREAT|0666);
	perror("");
	printf("\n%d\n",msgid);
	msgsnd(msgid,&mq,strlen(mq.msgp)+1,0);
}


#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 


  
int main() 
{ 
	key_t key;
	key=ftok(".",'b');

 		struct msg
	{
	long int mtype;
	char msgp[80];	
	}		mq;

	long int msgid;
	
	msgid=msgget(key,IPC_CREAT|0666);


	if((msgrcv(msgid, &mq, sizeof(mq), 1, 0))==-1);
	{	perror(""); }
	
	printf("message: %s\n", mq.msgp);
} 

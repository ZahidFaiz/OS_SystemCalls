       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
       #include <stdio.h>
       #include <time.h>	
void main()
{
	key_t key;
	int msgid;


        struct ipc_perm mid;
        struct msqid_ds mqd;


	key=ftok(".",'c');
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0744);
	msgctl(msgid,IPC_STAT, &mqd);
	perror("");

	printf("\naccess permission:%d\n",mid.mode);
	printf("\nuid:%d \ngid: %d",mid.uid,mid.gid);

	printf("\n\ntime of last message \n\nsent:%s \nreceived:%s",ctime(&mqd.msg_stime),ctime(&mqd.msg_rtime));
	printf("\n\ntime of last change in the message queue: %s",ctime(mqd.msg_ctime));

	printf("\nsize of the queue:%lu",mqd.__msg_cbytes);
	printf("\nnumber of messages in the queue:%lu",mqd.msg_qnum);

	printf("\n\nmaximum number of bytes allowed%lu",mqd.msg_qbytes);
	printf("\n\npid of the \nmsgsnd:%d\n msgrcv:%d\n",mqd.msg_lspid,mqd.msg_lrpid);

}


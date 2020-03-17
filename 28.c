       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
       #include <stdio.h>
       #include <unistd.h>


void main ()
        {
                key_t key ;
                key=ftok(".",'b');

                struct msqid_ds msqid;


                long int msgid;
                msgid=msgget(key,IPC_CREAT|0666);

                msgctl(msgid, IPC_STAT, &msqid);


                printf("New messageQ with permission: \t%d\n",msqid.msg_perm.mode);
                msqid.msg_perm.mode=0777;

                sleep(3);
                msgctl(msgid, IPC_SET, &msqid);

                msgctl(msgid, IPC_STAT, &msqid);


                printf("MessageQ permission changed to: \t%d\n",msqid.msg_perm.mode);

        }


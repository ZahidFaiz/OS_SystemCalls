#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <sys/types.h>  
int main() 
{ 
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Write Data : "); 
    gets(str); 
  
    printf("Data written in memory: %s\n",str); 
    printf("Press enter to deattach from shared memory(shared memory still exists)\n");
    
    getchar();
     shmdt(str);
  
    return 0; 
} 

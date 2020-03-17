#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
  
int main() 
{ 
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  	
    char *str = (char*) shmat(shmid,(void*)0, 0);  
    printf("Data read from shared memory put by 30a.c program: %s\n",str); 
      
    printf("press enter to deattcah\n");
    getchar();
    shmdt(str); 
    
    printf("press enter to remove\n");
	getchar();
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 

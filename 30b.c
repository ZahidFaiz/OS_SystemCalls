#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
  
int main() 
{ 
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  	
    char *str = (char*) shmat(shmid,(void*)0, SHM_RDONLY);
   printf("This will give segmentation fault as it is attached as readonly\nEnter message:\n");

	gets(str);  
    printf("Data read from memory: %s\n",str); 
      
    shmdt(str); 
    
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 

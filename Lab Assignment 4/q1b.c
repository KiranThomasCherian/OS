#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){			
pid_t pid;
pid=fork();
if(pid==0)			//zombie
{

printf("Child exiting: pid- %d ppid-%d \n",getpid(),getppid());
exit(0);
}
else if(pid>0)
{
sleep(7);
printf("Parent is exiting, : pid- %d ppid-%d \n",getpid(),getppid());
exit(0);
}
else{
printf("Fork failed\n");
}

return 0;
}

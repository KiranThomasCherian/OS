#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0)		//orphan
{

sleep(3);
printf("Child after sleep : pid- %d ppid-%d \n",getpid(),getppid());
exit(0);
}
else if(pid>0)
{
printf("Parent is exiting, : pid- %d ppid-%d \n",getpid(),getppid());
exit(0);
}
else{
printf("Fork failed\n");
}

return 0;
}

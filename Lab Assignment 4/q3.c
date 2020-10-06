#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
pid_t pid;
int count =0;

while(1)
{
pid=fork();
if(pid==0){
printf("A process with id : %d and parent : %d \n",getpid(),getppid());
sleep(3);
exit(0);
}
else if(pid<0){
int status;
pid_t wpid;
while ((wpid = wait(&status)) > 0);
printf("Total no of times fork called : %d \n",count);
exit(0);
}
else if(pid>0)
++count;
continue;
}

return 0;
}

# include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ()
{
pid_t childpid;
childpid = fork();
if (childpid == 0){
printf("inside child \n");
exit(0);
}
else
{
int returnstatus;
waitpid (childpid,&returnstatus,0);
printf("parent waited for child to die :\n") ;
if(returnstatus==0)
printf("child Process terminated normally \n");
else
printf("child Process terminated abnormally \n");
}
return 0;
}
# include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ()
{
pid_t pid;
int status;
for(int i=0;i<5;i++){
    if((pid=fork())==0)
    {
        printf("This is child %d \n",i+1);
        exit(0);
    }
}
while(wait(&status)>0);
printf("parent waited for all children to die\n") ;
return 0 ;
}
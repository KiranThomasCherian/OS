# include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ()
{
pid_t pid; 
pid = fork();
if (pid == 0)
execl("/bin/ls", "ls", NULL); 
else
{
wait (NULL); // parent waits for the child to complete execution.
printf("Parent Process gets the control \n");
printf ("Parent Has waited for Child to Complete\n");
}
return 0;
}
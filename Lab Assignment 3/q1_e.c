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
{
char *const argv[] = {"ls","-l", NULL};
execv("/bin/ls",argv);
}
else
{
wait (NULL); // parent waits for the child to complete execution.
printf("Parent Process gets the control \n");
printf ("Parent Has waited for Child to Complete\n");
}
return 0;
}
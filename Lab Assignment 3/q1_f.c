
#include <stdio.h>
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

int ret;
char *cmd[] = { "ls", "-l", (char *)0 };
char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char*)0 };
execve("/bin/ls", cmd, env);
}
else
{
wait (NULL); // parent waits for the child to complete execution.
printf("Parent Process gets the control \n");
printf ("Parent Has waited for Child to Complete\n");
}
return 0;
}

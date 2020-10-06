/*Express the following in a process tree setup and also write the C code for the same setup
1 forks 2 and 3	: 2 forks 4 5 and 6 : 3 forks 7 :4 forks 8 :5 forks 9*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
pid_t pid,pid2,pid3,pid4;
printf("Inside 1- pid : %d ppid : %d \n",getpid(),getppid());
printf(" creating 2 from 1\n");
pid=fork();	//2
if(pid>0)
{
printf(" creating 3 from 1\n");
pid2=fork();	//3
if(pid2==0)
{
printf("Inside 3- pid : %d ppid : %d \n",getpid(),getppid());
printf(" creating 7 from 3\n");
pid3=fork();		//7
if(pid3==0)
printf("Inside 7- pid : %d ppid : %d \n",getpid(),getppid());
}
}
else if(pid == 0){
printf("Inside 2- pid : %d ppid : %d \n",getpid(),getppid());
printf(" creating 4 from 2\n");
pid2=fork();	//4
if(pid2>0)
{
printf(" creating 5 from 2\n");
pid3= fork();	//5
if(pid3>0){
printf(" creating 6 from 2\n");
pid4=fork();
if(pid4==0)
printf("Inside 6- pid : %d ppid : %d \n",getpid(),getppid());
}	//6
else if(pid3 ==0){
printf(" creating 9 from 5\n");
printf("Inside 5- pid : %d ppid : %d \n",getpid(),getppid());
pid4=fork();
if(pid4==0)
printf("Inside 9- pid : %d ppid : %d \n",getpid(),getppid());
}		//9
}else if(pid2 ==0){
printf(" creating 8 from 4\n");
printf("Inside 4- pid : %d ppid : %d \n",getpid(),getppid());
pid4=fork();
if(pid4==0)
printf("Inside 8- pid : %d ppid : %d \n",getpid(),getppid());
}		//8
}
int st;
while(wait(&st)>0);
return 0;
}

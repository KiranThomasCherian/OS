/*Express the following in a process tree setup and also write the C code for the same setup
1 forks 2 and 3	: 2 forks 4 5 and 6 : 3 forks 7 :4 forks 8 :5 forks 9*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
pid_t pid;
printf("Inside 1\n");
printf(" creating 2 from 1\n");
pid=fork();	//2
if(pid>0)
{
printf(" creating 3 from 1\n");
pid=fork();	//3
if(pid==0)
{
printf(" creating 7 from 3\n");
fork();		//7
}
}
else if(pid == 0){
printf(" creating 4 from 2\n");
pid=fork();	//4
if(pid>0)
{
printf(" creating 5 from 2\n");
pid= fork();	//5
if(pid>0){
printf(" creating 6 from 2\n");
fork();	}	//6
else if(pid ==0){
printf(" creating 9 from 5\n");
fork();}		//9
}else if(pid ==0){
printf(" creating 8 from 4\n");
fork();}		//8
}
return 0;
}

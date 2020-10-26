#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
char* mysubstr(const char *src, int m, int n)
{
	int len = n - m;
	char *dest = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = m; i < n && (*(src + i) != '\0'); i++)
	{
		*dest = *(src + i);
		dest++;
	}
	*dest = '\0';
	return dest - len;
}
int main(){
int fd1[2];
//int fd2[2];
pid_t pid;
if((pipe(fd1)==-1)){
printf("Cant create pipes ");
exit(0);
}
char str[50];
char end[10];
char start[10];
int s,e;
pid=fork();
if(pid>0){
printf("Enter the string  : ");
scanf("%[^\n]s",str);
printf("Enter start(inclusive) and end index(exclusive) from zero : ");
scanf("%d%d",&s,&e);
sprintf(start, "%d",s);
sprintf(end, "%d",e);
//printf("\n%s,%s",start,end);
close(fd1[0]);
write(fd1[1],str,strlen(str)+1);
usleep(50);
write(fd1[1],start,strlen(start)+1);
usleep(50);
write(fd1[1],end,strlen(end)+1);
close(fd1[1]);
}
else if(pid==0){
close(fd1[1]);
read(fd1[0],str,sizeof(str));
usleep(50);
read(fd1[0],start,sizeof(start));
usleep(50);
read(fd1[0],end,sizeof(end));
s=atoi(start);
e=atoi(end);
if(s<0||e>strlen(str)||e<=s)
{
printf("\nEnter valid inputs (0 to strlen()) and start <end \n");
exit(0);}
//printf("\n %s,%d,%d, %s,%s",str,s,e,start,end);
printf("Answer : %s \n",mysubstr(str,s,e));
close(fd1[0]);
}else{
close(fd1[0]);
close(fd1[1]);
printf("Fork failed \n");
exit(0);
}

return 0;
}





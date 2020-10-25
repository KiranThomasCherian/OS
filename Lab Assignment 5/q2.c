#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
int fd1[2];
int fd2[2];
pid_t pid;
if((pipe(fd1)==-1)||(pipe(fd2))==-1){
printf("Cant create pipes ");
exit(0);
}
char str[50];
pid=fork();
if(pid>0){
char str2[50];
printf("Enter the string1 (in parent) : \n");
//fgets(str,sizeof(str),stdin);
scanf("%s",str);
close(fd2[1]);
read(fd2[0],str2,sizeof(str2));
strcat(str,str2);
printf("Contatinated in parent,sending to child \n");
close(fd2[0]);
close(fd1[0]);
write(fd1[1],str,strlen(str)+1);
close(fd1[1]);
}
else if(pid==0){
sleep(5);
printf("Enter the string2 (in child) : \n");
scanf("%s",str);
//fgets(str,sizeof(str),stdin);
close(fd2[0]);
write(fd2[1],str,strlen(str)+1);
close(fd2[1]);

close(fd1[1]);
read(fd1[0],str,sizeof(str));
printf("After concatination and the message received in child : %s \n",str);
close(fd1[0]);
}else{
close(fd1[0]);
close(fd1[1]);
close(fd2[0]);
close(fd2[1]);
printf("Fork failed \n");
exit(0);
}

return 0;
}

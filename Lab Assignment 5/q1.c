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
printf("Enter the string to be reversed : ");
scanf("%s",str);
close(fd1[0]);
write(fd1[1],str,strlen(str));

char newstr[70];
close(fd2[1]);
read(fd2[0],newstr,sizeof(newstr));
printf("After reversing : %s \n",newstr);
close(fd2[0]);
}
else if(pid==0){
close(fd1[1]);
//printf("%d\n",sizeof(str));
read(fd1[0],str,sizeof(str));
int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    };
close(fd2[0]);
printf("After processing in child : %s \n",str);
write(fd2[1],str,sizeof(str));

close(fd2[1]);
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

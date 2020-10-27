#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){


	int n;

    printf("Enter the range/limit : ");
    scanf("%d",&n);
	printf("Armstong numbers :\n");
    for(int i=0;i<=n;i++)
    {
	int fd1[2];
	pid_t pid;
	if((pipe(fd1)==-1)){
	printf("Cant create pipes ");
	exit(0);}
    pid=fork();
    if(pid==0){
	int j=i;
	int sum=0;
    while(j>0){
    int q=pow((j%10),3);
    sum=(sum)+q;
    j=j/10;
    }
	char s[10];
	sprintf(s,"%d",sum);
	close(fd1[0]);
	write(fd1[1],s,strlen(s)+1);
	close(fd1[1]);
	//printf("here %s %d \n",s,sum);
        exit(0);
        }
    else if(pid>0){
		wait(NULL);		
		char s1[10];
		bzero(s1,sizeof(s1));
		close(fd1[1]);
		usleep(50);
		read(fd1[0],s1,sizeof(s1));
		//printf("--%s %d \n",s,strlen(s));
		char org[10];
		sprintf(org,"%d",i);
		//printf("%s --%s \n",org,s1);
		if(strcmp(org,s1)==0){
		printf(" %d	\n",i);
        
        }
		close(fd1[0]);

    }
    else
    {
        printf("Fork failed.. exiting..");
        exit(0);
    }
    }
    return 0;
}

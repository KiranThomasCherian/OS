#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

int n;  //current no
char clist[50][150];
void history(int);

int main()
{
	pid_t pid;
	char ch[200];
	n = 0;
	printf("\t\tMy Terminal\nRules:\n1)Use 'exit' to exit\n2)use ! for full history\n3)use !followed by number for history of last specified number(don't put space in between ! and number)\n4)Try to provide valid inputs\n\n ");
    do
	{
	printf(" @ ");
    fgets(ch,200,stdin);
	//printf("s1-%d",strlen(ch));
	ch[(strlen(ch)-1)]='\0';		//as \n is also taken
	//printf("%s\n",ch);
	if(strcmp(ch,"exit") == 0)
	{
	exit(0);
	}
	else if(ch[0] == '!')
	{
    if(ch[1]=='\0')
    history(-1);
    else
    {   char le[20];
        int l=strlen(ch);
        int ll=0;
        while((ll+1)<l){
        le[ll]=ch[1+ll];
        ll++;
        }
        le[ll]='\0';
        int lim=atoi(le);
        //printf("lim%d\n",lim);
        history(lim);

    }   
    }
	else 
	{	
	//char sargs[50][100];
	char sargs[100][100];
	//printf("siz%d\n",strlen(ch));
	int ac=0,j=0;
    for(int i=0;i<=(strlen(ch));i++)
    {
        if(ch[i]==' '||ch[i]=='\0')
        {
            sargs[ac][j]='\0';
            ac++; 
            j=0;  
			if(ch[i]=='\0'){
			//printf("sla\n");
			//sargs[ac]=NULL;
			break;
			}
        }
        else
        {
            sargs[ac][j]=ch[i];
            j++;
        }
    }
    //printf("after split:\n");
    //for(int i=0;i < ac;i++)
    //  printf(" %s\n",sargs[i]);
	//	printf("a%d",ac);
		char *sa[100];
		for(int i=0;i<ac;i++){
			//printf(" - %d",i);
			sa[i]=sargs[i];
		}
		sa[ac]=NULL;


			int pid = vfork();
			
			if(pid == 0)
			{
				execvp(sargs[0],sa);
				printf("Error! - %s: invalid command/input! \n", sargs[0]);		//if exec fails.
				exit(0);
			}
			
			else 
			{
				strcpy(clist[n++],ch);
				wait(NULL);
				printf("\n");
			 }
		}
	}while(1);
}

void history(int lim){
	if(lim==-1){
		if(n==0)
		printf("Empty history\n");
		else
		{
			for(int i=n-1;i>=0;i--)
			puts(clist[i]);
			printf("\n");
		}
	}
	else{
		if(n==0)
		printf("Empty history\n");
		else{
		for(int i=n-1;((i>=(n-lim))&&i>=0);i--)
		puts(clist[i]);
		printf("\n");
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    printf("Histogram for characters -file name: text.txt\n\n");
    //FILE *fp=fopen("text.txt","r");
    for(int i=33;i<=126;i++){
        pid=fork();
        if(pid==0){
            char c;
            int count=0;
            FILE *fp=fopen("text.txt","r");
            c=fgetc(fp);
            while (c!=EOF)
            {
                if(c==i)
                count++;
                c=fgetc(fp);
            }
            printf("      %c- %3d :",i,count);
            for(int i=0;i<count;i++)
            printf("*");
            printf("\n");
            fclose(fp);
            exit(0);
        }
    }
    int status;
    while ((wait(&status)) > 0);
    char c;
    int count=0;
    FILE *fp=fopen("text.txt","r");
        c=fgetc(fp);
            while (c!=EOF)
            {
                if(c==32)
                count++;
                c=fgetc(fp);
            }
            printf("  space- %3d :",count);
            for(int i=0;i<count;i++)
            printf("*");
            printf("\n");
    fclose(fp);
    fp=fopen("text.txt","r");
    count=0;
            c=fgetc(fp);
            while (c!=EOF)
            {
                if(c==10)
                count++;
                c=fgetc(fp);
            }
            printf("newline- %3d :",count);
            for(int i=0;i<count;i++)
            printf("*");
            printf("\n");
            
    fclose(fp);
    return 0;
}
#include <stdio.h> 
#include<iostream>       
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int funselect(int ,char ,char);
int funselect(int ,float ,float);
int funselect(int ,int ,int);
// int checkfloat(char a[10],char b[10]);
int checkfloat(char** a,int s);
void sort(int temp[],int s,int op);    
void sort(float temp[],int s,int op);  
void sort(char temp[],int s,int op);
int main(int argc, char *argv[])                
{
if(argc ==2&&!strcmp(argv[1],"-help")){
		printf("Program to sort array of integers,float,characters\n(don't intermix characters and numbers) \nUsage ./executable <size> <1/2> <var1> <var2> ...\nUse 1 for ascending and 2 for descending");
		exit(0);
	}
if(argc <=3){
    printf("Not enough arguments ");
    exit(0);
}
int s=atoi(argv[1]);
if(3+s!=argc){
    printf("specified amount of numbers should be entered,exiting");
    exit(0);
}
if(atoi(argv[2])>=3||atoi(argv[2])<=0){
    printf("Use 1 for ascending ,2 for decendending, try again..");
    exit(0);
}
if(argc==4){
    printf("Only one element !!\n");
    printf("%s",argv[3]);
    exit(0);
    }
if(strlen(argv[3])==1&&!isdigit(argv[3][0])){
    printf("charecters\n");
    char temp[25];
    int k=0;
    for(int i=3;i<argc;i++){
            if(strlen(argv[i])>1){
            printf("Only single letter permitted , exiting");
            exit(0);
        }
        else if(isdigit(argv[i][0])){
            cout<<"Please use either character or numbers..exiting";
            exit(0);
        }
           temp[k++]=argv[i][0]; 
    }

    sort(temp,atoi(argv[1]),atoi(argv[2]));
}
else if(checkfloat(argv,argc)){
    printf("floating numbers\n");
    float temp[25];
    int k=0;
    for(int i=3;i<argc;i++)
    temp[k++]=atof(argv[i]);
    sort(temp,atoi(argv[1]),atoi(argv[2]));
}
else if(atoi(argv[3])!=0||(atoi(argv[3])==0&&!strcmp(argv[3],"0"))){
    printf("integers\n");
    int temp[25];
    int k=0;
    for(int i=3;i<argc;i++){
          if((atoi(argv[i])==0&&strcmp(argv[i],"0"))){
            cout<<"Please use either character or numbers..exiting";
            exit(0);
          }
          temp[k++]=atoi(argv[i]);
    }

    sort(temp,atoi(argv[1]),atoi(argv[2]));

}
else{
    printf("Error !!");
    return 0;
}
return 0;

}

int funselect(int op,char a,char b){
    if (op==1)
    return((a>b)?1:0);
    else
    return((a<b)?1:0) ;  
}
int funselect(int op,int a,int b){
    if (op==1)
    return((a>b)?1:0);
    else
    return((a<b)?1:0) ;  
}
int funselect(int op,float a,float b){
    if (op==1)
    return((a>b)?1:0);
    else
    return((a<b)?1:0) ;  
}

void sort(char temp[],int s,int op){
    char z;
    int (*ops)(int,char,char)=&funselect;
  for (int i = 0 ; i < s - 1; i++)
  {
    for (int j = 0 ; j < s - i - 1; j++)
    {
      if ((*ops)(op,temp[j],temp[j+1]))
      {
        z       = temp[j];
        temp[j]   = temp[j+1];
        temp[j+1] = z;
      }
    }
  }

   printf("After sorting :\n");
  for (int c = 0; c < s; c++)
     printf("%c ", temp[c]);
}
void sort(int temp[],int s,int op){
    int z;
    int (*ops)(int,int,int)=&funselect;
  for (int i = 0 ; i < s - 1; i++)
  {
    for (int j = 0 ; j < s - i - 1; j++)
    {
      if ((*ops)(op,temp[j],temp[j+1]))
      {
        z       = temp[j];
        temp[j]   = temp[j+1];
        temp[j+1] = z;
      }
    }
  }
   printf("After sorting :\n");
  for (int c = 0; c < s; c++)
     printf("%d ", temp[c]);
}
void sort( float temp[],int s,int op){
    float z;
    int (*ops)(int,float,float)=&funselect;
  for (int i = 0 ; i < s - 1; i++)
  {
    for (int j = 0 ; j < s - i - 1; j++)
    {
      if ((*ops)(op,temp[j],temp[j+1]))
      {
        z       = temp[j];
        temp[j]   = temp[j+1];
        temp[j+1] = z;
      }
    }
  }
   printf("After sorting :\n");
  for (int c = 0; c < s; c++)
    cout<<temp[c]<<" ";
    //  printf("%f ", temp[c]);
}

int checkfloat(char** a,int s){
    for(int k=3;k<s;k++){
    for(int i=0;i<strlen(a[k]);i++){
        if(a[k][i]=='.')
        return 1;
    }
    }
    return 0;
}

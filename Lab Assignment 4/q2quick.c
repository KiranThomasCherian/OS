#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int a[200];
void swap(int *a,int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

int qs(int a[],int lf,int rt){
  int pt = a[rt];
  int i = (lf - 1);
  for (int j = lf;j < rt;j++){
    if (a[j] <= pt) {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[rt]);
  return(i+1);
}

void qs_byfork(int a[],int lf,int rt) {
  if (lf < rt) {
	pid_t pid;
    int pi = qs(a,lf,rt);
	pid=vfork();
	if(pid==0){
	printf("A new process\n");
    qs_byfork(a,lf,pi-1);
	_exit(0);
	}
    qs_byfork(a,pi+1,rt);
  }
}

int main() 
{ 
	int n;
    printf("Enter size : ");
    scanf("%d",&n);
    printf("Enter the array :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
	qs_byfork(a,0,n-1); 

	printf("\nSorted array : \n"); 
	for(int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n");
	return 0; 
} 


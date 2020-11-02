#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
#include<limits.h>

int a[200];
int n;
struct lmr{
int l;
int r;
int retn;    //the return value is saved here ,if needed else INT_MIN
};
pthread_attr_t attr;
pthread_mutex_t lock;

void swap(int *a,int *b){
  int t = *a;
  *a = *b;
  *b = t;
}


 void *runner1(void *arg) 
{ 
struct lmr *str =(struct lmr *)arg;
int lf= str->l;
int rt= str->r; 
pthread_mutex_lock(&lock);

 int pt = a[rt];
  int i = (lf - 1);
  for (int j = lf;j < rt;j++){
    if (a[j] <= pt) {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[rt]);
  //return(i+1);
str->retn=i+1;
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

void *runner(void *arg) 
{ 
pthread_t pid,pid1,pid2;
struct lmr *str =(struct lmr *)arg;
int lf= str->l;
int rt= str->r;
  if (lf < rt) {
struct lmr *str0 =(struct lmr *)malloc(sizeof(struct lmr));
str0->l=lf;
str0->r=rt;
str0->retn=INT_MIN;
pthread_create(&pid,&attr,runner1,str0);
pthread_join(pid,NULL);
int pi= (str0->retn);
//printf("s %d \n ",pi);
free(str0); 
 //  int pi = qs(a,lf,rt);
struct lmr *str1 =(struct lmr *)malloc(sizeof(struct lmr));
str1->l=lf;
str1->r=pi-1;
str1->retn=INT_MIN;
pthread_create(&pid1,&attr,runner,str1);
struct lmr *str2 =(struct lmr *)malloc(sizeof(struct lmr));
str2->l=pi+1;
str2->r=rt;
str2->retn=INT_MIN;
pthread_create(&pid2,&attr,runner,str2);
pthread_join(pid1,NULL);
pthread_join(pid2,NULL);
free(str1);
free(str2); 
pthread_exit(NULL);

  }
}

int main() 
{ 
	pthread_t pid;
	pthread_attr_init(&attr);	
	int n;
    printf("Enter size : ");
    scanf("%d",&n);
    printf("Enter the array :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }
struct lmr *str =(struct lmr *)malloc(sizeof(struct lmr));
str->l=0;
str->r=n-1;
str->retn=INT_MIN;
pthread_create(&pid,&attr,runner,str);	
pthread_join(pid,NULL);
	printf("\nSorted array : \n"); 
	for(int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n");
pthread_mutex_destroy(&lock);
	return 0; 
} 


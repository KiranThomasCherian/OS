#include<sys/wait.h>
#include<unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include<pthread.h>

int a[200];
int n;
struct lmr{
int l;
int r;
};
pthread_attr_t attr;
pthread_mutex_t lock;

void mergearrays(int l,int mid,int r);
void *runner(void *arg) 
{ 
pthread_t pid1,pid2;
struct lmr *str =(struct lmr *)arg;
int lf= str->l;
int rt= str->r;
	if (lf < rt) { 
		pid_t pid;
		int mid = (lf+rt)/ 2;  
struct lmr *str1 =(struct lmr *)malloc(sizeof(struct lmr));
str1->l=lf;
str1->r=mid;
pthread_create(&pid1,&attr,runner,str1);
struct lmr *str2 =(struct lmr *)malloc(sizeof(struct lmr));
str2->l=mid+1;
str2->r=rt;
pthread_create(&pid2,&attr,runner,str2);
pthread_join(pid1,NULL);
pthread_join(pid2,NULL); 
pthread_mutex_lock(&lock);	
		mergearrays(lf,mid,rt);
pthread_mutex_unlock(&lock); 
		}

pthread_exit(NULL);
} 


int main() 
{ 
	pthread_t pid;
	pthread_attr_init(&attr);
	
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
struct lmr *str0 =(struct lmr *)malloc(sizeof(struct lmr));
str0->l=0;
str0->r=n-1;
pthread_create(&pid,&attr,runner,str0);	
pthread_join(pid,NULL);

	printf("\nSorted array : \n"); 
	for(int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n");
pthread_mutex_destroy(&lock);
	return 0; 
} 



void mergearrays(int l,int mid,int r)
{ 
int s1 = mid - l + 1; 
int s2 = r - mid; 
int leftarr[s1], rightarr[s2]; 

for(int i = 0; i < s1; i++) 
	leftarr[i] = a[l + i]; 
for(int j = 0; j < s2; j++) 
	rightarr[j] = a[mid + 1 + j]; 

int i =0,j=0,k=l;
while(i < s1 && j < s2){ 
	if(leftarr[i] <= rightarr[j]){ 
		a[k] = leftarr[i]; 
		i++; 
	} 
	else{ 
		a[k] = rightarr[j]; 
		j++; 
		} 
		k++; 
	} 
	while(i < s1) { 
		a[k] = leftarr[i]; 
		i++; 
		k++; 
	} 
	while(j < s2) { 
		a[k] = rightarr[j]; 
		j++; 
		k++; 
	} 
} 

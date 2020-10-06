#include<sys/wait.h>
#include<unistd.h>
#include <stdio.h> 
#include <stdlib.h> 


int a[200];
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

void mergsrt_byfork(int lf, int rt) 
{ 
	if (lf < rt) { 
		pid_t pid;
		int mid = (lf+rt)/ 2;  
		pid=vfork();
		if(pid==0){
		printf("New process\n");
		mergsrt_byfork(lf,mid);
 		_exit(0);
		}
		else{	
		mergsrt_byfork(mid + 1,rt); 	
		mergearrays(lf,mid,rt); 
		}
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
	mergsrt_byfork(0,n-1); 

	printf("\nSorted array : \n"); 
	for(int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n");
	return 0; 
} 


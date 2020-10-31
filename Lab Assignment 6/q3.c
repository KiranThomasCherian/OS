#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
void sortarr(int s,int e,int arr[]);
void *runner1(void *arg);
void *runner2(void *arg);
int arr[100],n;
int main(){
  int p;
  printf("Enter size of array : ");
  scanf("%d",&n);
  printf("Enter array : ");
  for(int i=0;i<n;i++){
  scanf("%d",&arr[i]);
  }
  printf("Enter element to be searched (No of times it is present = no of messeges printed ,none if not present)  : ");
  scanf("%d",&p);
  pthread_t ptid1,ptid2;

pthread_attr_t attr;
pthread_attr_init(&attr); 
  
int *nn=&p;
pthread_create(&ptid1,&attr,runner1,nn);
//printf("between main (id:%d)\n ",pthread_self());
pthread_create(&ptid2,&attr,runner2,nn);
pthread_join(ptid1, NULL);
pthread_join(ptid2, NULL);
printf("Ending main (id:%d)\n ",pthread_self());

return 0;
}


void *runner1(void *arg){
int *p=arg;
int beg,mid,end;
sortarr(0,(n/2)-1,arr);
printf("\nTop half thread: (id:%d)\n",pthread_self());
        beg=0;
        end=n/2-1;
        
        while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==*p)
        {
            printf("Element found !\n");
            int lef=mid-1;
            int rig=mid+1;
            while(lef>=0&&arr[lef]==arr[mid]){
                printf("Element found !\n");
                lef--;
            }
            while(rig<=((n/2)-1)&&arr[rig]==arr[mid]){
                printf("Element found !\n");
                rig++;
            }
pthread_exit(NULL);

        }else if(*p>arr[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        }
pthread_exit(NULL);
    }

void *runner2(void *arg){
int *p=arg;
int beg,mid,end;
sortarr((n/2),n-1,arr);
printf("\nbottom half thread: (id:%d)\n",pthread_self());
        beg=(n/2);
        end=n -1;
        while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==*p)
        {
            printf("Element found !\n");
            int lef=mid-1;
            int rig=mid+1;
            while(lef>=n/2&&arr[lef]==arr[mid]){
                printf("Element found !\n");
                lef--;
            }
            while(rig<n&&arr[rig]==arr[mid]){
                printf("Element found !\n");
                rig++;
            }
pthread_exit(NULL);
        }
        else if(*p>arr[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        } 
pthread_exit(NULL);
    }

void sortarr(int s,int e, int arr[100]){
    { 
   int i, j,temp; 
   for (i = s; i < e; i++)       
    for (j = s; j < (e-i)+s; j++)  
           if (arr[j] > arr[j+1]) 
           {
              temp =arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
           }
} 
}

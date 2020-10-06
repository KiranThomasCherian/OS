#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/wait.h>
#include<unistd.h>
void sortarr(int s,int e,int arr[]);

int main(){
    int n,p;
    int arr[100];
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched (No of times it is present = no of messeges printed ,none if not present)  : ");
    scanf("%d",&p);
    pid_t pid;
    int flag=0,beg,mid,end;
    pid =fork();
    if(pid==0){
        sortarr(0,(n/2)-1,arr);
    //      for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }printf("- child duty half after sort\n");
        beg=0;
        end=n/2-1;
        
        while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==p)
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

            flag=1;
            _exit(0);
        }else if(p>arr[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        }
    }
    else if(pid>0){
        sortarr((n/2),n-1,arr);
    //       for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }printf("par\n");
        beg=(n/2);
        end=n -1;
        while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==p)
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
            
            flag=1;
            _exit(0);
        }
        else if(p>arr[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        } 
    }
     else
    {
        printf("Fork failed.. exiting..");
        exit(0);
    }
    sleep(1);
    // if(flag==0){
    //     printf("No occurence of element found ,exiting\n");
    //     exit(0);
    // }
    return 0;
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
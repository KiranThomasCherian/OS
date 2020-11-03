#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<math.h>

float a[25][25],k,d;			//array,dimension,determinant
float trans[25][25];    		//transpose
float inverse[25][25];			//inverse
float fact[25][25];				//cofactor

void *runner1(void *arg);		//cofactor
void *runner2(void *arg);		//transpose
void *runner3(void *arg);		//invert and display

pthread_attr_t attr;
pthread_mutex_t lock;


float determinant(float a[25][25], float k);
int main(){
	 int i,j;
     printf("Enter the order of the Matrix : ");
     scanf("%f",&k);
     printf("Enter the elements of row wise : \n");
     for(i = 0;i < k; i++){
     for(j = 0;j < k; j++){
            scanf("%f", &a[i][j]);
            }
        }
	 pthread_t pid1,pid2,pid3;
	 pthread_attr_init(&attr);
	 if(pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
     }
     d = determinant(a, k);
     if(d == 0)
	 printf("\nInverse not possible\n");
     else{
	 pthread_create(&pid1,&attr,runner1,NULL);	
	 pthread_join(pid1,NULL);
	 pthread_create(&pid3,&attr,runner3,NULL);	
	 pthread_join(pid3,NULL);
	 }
	 pthread_mutex_destroy(&lock);
	 return 0; 	
  }


float determinant(float a[25][25], float k){
	float s = 1, det = 0, b[25][25];
	int i, j, m, n, c;
	if(k == 1)
	{
    return (a[0][0]);
    }
    else
    {
    det = 0;
    for(c = 0; c < k; c++)
    {
    m = 0;
    n = 0;
    for(i = 0;i < k; i++)
    {
    for(j = 0 ;j < k; j++)
    {
    b[i][j] = 0;
    if(i != 0 && j != c)
    {
    b[m][n] = a[i][j];
    if(n < (k - 2))
    n++;
    else
    {
    n = 0;
    m++;
    }
    }
    }
    }
    det = det + s * (a[0][c] * determinant(b, k - 1));
    s = -1 * s;
    }
    }
    return(det);
}

void *runner1(void *arg){
     float b[25][25];
     int p, q, m, n, i, j;
     for(q = 0;q < k; q++) {
     for(p = 0;p < k; p++)
     {
     m = 0;
     n = 0;
     for(i = 0;i < k; i++){
     for(j = 0;j < k; j++)
     {
     if(i != q && j != p)
     {
     b[m][n] = a[i][j];
     if(n < (k - 2))
     n++;
     else
     {
     n = 0;
     m++;
     }
     }
     }
     }
     fact[q][p] = pow(-1, q + p) * determinant(b, k - 1);
     }
     }
	pthread_t pid;
	pthread_create(&pid,&attr,runner2,NULL);	
	pthread_join(pid,NULL);
	pthread_exit(NULL);
}

void *runner2(void *arg) {
	 int i, j;
     for(i = 0;i < k; i++)
     {
     for(j = 0;j < k; j++)
     {
     trans[i][j] = fact[j][i];
     }
     }
	pthread_exit(NULL);
}
void *runner3(void *arg) {
	int i,j;
    for(i = 0;i < k; i++)
    {
    for(j = 0;j < k; j++)
    {
    inverse[i][j] = trans[i][j] / d;
    }
    }
    printf("\n\n\nThe inverse of matrix is : \n");
    for(i = 0;i < k; i++)
    {
    for(j = 0;j < k; j++)
    {
	if(inverse[i][j]==-0.000000)
	inverse[i][j]=0.000000;
    printf("\t%f", inverse[i][j]);
    }
    printf("\n");
    }
	pthread_exit(NULL);
}

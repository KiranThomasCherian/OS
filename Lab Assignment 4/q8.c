#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int msquare[100][100];
int evenmsquare[100][100];

void oddsquare(int n)
{
	memset(msquare,0,sizeof(msquare));
	int i = n / 2;
	int j = n - 1;
	for (int k = 1;k <= n * n;){
		if (i == -1 && j == n)
		{
			j = n - 2;
			i = 0;
		}
		else {
			if (j == n)
				j = 0;
			if (i < 0)
				i = n - 1;
		}
		if (msquare[i][j])
		{
			j -= 2;
			i++;
			continue;
		}
		else
			msquare[i][j] = k++;

		j++;
		i--;
	}

}
void doublyevensquare(int n) 
{  
    int i, j; 
    for(i = 0; i < n; i++) 
        for( j = 0; j < n; j++) 
            msquare[i][j] = (n*i) + j + 1; 
    for(i = 0; i < n/4; i++) 
        for(j = 0; j < n/4; j++) 
            msquare[i][j] = (n*n + 1) - msquare[i][j]; 
    for(i = 0; i < n/4; i++) 
        for(j = 3 * (n/4); j < n; j++) 
            msquare[i][j] = (n*n + 1) - msquare[i][j]; 
    for(i = 3 * n/4; i < n; i++) 
        for(j = 0; j < n/4; j++) 
            msquare[i][j] = (n*n+1) - msquare[i][j]; 
    for(i = 3 * n/4; i < n; i++) 
        for(j = 3 * n/4; j < n; j++) 
            msquare[i][j] = (n*n + 1) - msquare[i][j]; 
    for(i = n/4; i < 3 * n/4; i++) 
        for ( j = n/4; j < 3 * n/4; j++) 
            msquare[i][j] = (n*n + 1) - msquare[i][j]; 
} 


void singlyevensquare(int n) 
{
 
    int s = n * n;
    int halfs = n / 2;
    int subs = s / 4, i;
    oddsquare(halfs);
    int gridpars[] = {0, 2, 3, 1};
 
    for(int r = 0; r < n; r++){
         for(int c = 0; c < n; c++){
            int grid = (r / halfs) * 2 + (c / halfs);
            evenmsquare[r][c] = msquare[r % halfs][c % halfs];
            evenmsquare[r][c] += gridpars[grid] * subs;
            }
        }
 
    int nclf = halfs / 2;
    int ncrt = nclf - 1;
 
    for(int r = 0; r < halfs; r++)
        for(int c = 0; c < n; c++){
           if(c < nclf || c >= n - ncrt || (c == nclf && r == nclf)){
            if (c == 0 && r == nclf)
            continue;
            int temp = evenmsquare[r][c];
            evenmsquare[r][c] = evenmsquare[r + halfs][c];
            evenmsquare[r + halfs][c] = temp;
            }
            }
 
    }

int main()
{
	int n;
	int flag=0;
	printf("Enter order : ");
	scanf("%d",&n);
	if(n==2||n<=0){
	printf("Please enter 1 or >=3 ,exiting \n");
	exit(0);
	}
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
	printf("Fork failed,exiting ");
	exit(0);
	}
	else if(pid==0)  
	{	
	//printf("here\n");				//child
	if(n%2!=0)
	oddsquare(n);
	else if(n%4==0)
	doublyevensquare(n);
	else{
	singlyevensquare(n);
	flag=1;
	}
	_exit(0);
	}
	else{
	int status;
	pid_t wpid;
	while ((wpid = wait(&status)) > 0);
	printf("The Magic Square for n=%d:\nSum of each row/column (magic constant) %d:\n",n,(n*(n*n + 1))/2);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(flag==0)
			printf("%4d ", msquare[i][j]);
			else
			printf("%4d ", evenmsquare[i][j]);	
		printf("\n");
	}
	}
	return 0;
}


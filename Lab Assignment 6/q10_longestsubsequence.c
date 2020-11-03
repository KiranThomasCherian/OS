#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
void *runner(void *arg);
void *runner2(void *arg);
int i,j,m,n,matrix[50][50];
char s1[50],s2[50];



int main() {
    //printf("In main ,thread id : %d \n",pthread_self());
printf("Enter 1st sequence : ");
scanf("%s",s1);
printf("Enter 2nd sequence : ");
scanf("%s",s2);
  m = strlen(s1);
  n = strlen(s2);
      pthread_t pid,pid1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    

  for (i = 0; i <= m; i++)
    matrix[i][0] = 0;
  for (i = 0; i <= n; i++)
    matrix[0][i] = 0;
    for (i = 1; i <= m; i++){
    for (j = 1; j <= n; j++) {              //for matrix
        pthread_create(&pid,&attr,runner,NULL);
        pthread_join(pid,NULL);
    }
    }
        pthread_create(&pid1,&attr,runner2,NULL);       //for lcs
        pthread_join(pid1,NULL);
return 0;
}


void *runner(void *arg){

          if (s1[i - 1] == s2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      } else if (matrix[i - 1][j] >= matrix[i][j - 1]) {
        matrix[i][j] = matrix[i - 1][j];
      } else {
        matrix[i][j] = matrix[i][j - 1];
      }
      pthread_exit(NULL);
}


void *runner2(void *arg){

  int last = matrix[m][n];
  char lcs[last + 1];
  lcs[last] = '\0';

  int a = m, b = n;
  while (a > 0 && b  > 0) {
    if (s1[a - 1] == s2[b - 1]) {
      lcs[last - 1] = s1[a - 1];
      a--;
      b--;
      last--;
    }

    else if (matrix[a - 1][b] > matrix[a][b - 1])
      a--;
    else
      b--;
  }
  printf("Longest common subsequence : %s \n",lcs);
  pthread_exit(NULL);
}

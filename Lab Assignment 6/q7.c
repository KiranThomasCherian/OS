#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<limits.h>

int inside = 0;
int tpno;

pthread_mutex_t lock;

void *runner() {
    int insidep = 0;
	int rstate = rand()^pthread_self();		//simple rand is not thread safe
    int i;
    for (i = 0; i < tpno; i++) {
        double x = rand_r(&rstate) / ((double)INT_MAX);
        double y = rand_r(&rstate) / ((double)INT_MAX);

        if (x * x + y * y < 1) {
            insidep++;
        }
    }
    
    pthread_mutex_lock(&lock);
    inside += insidep;
    pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main()
{
	int tp,tt;
	printf("Enter total points and no of threads(<10) : ");
	scanf("%d%d",&tp,&tt);

	tpno = tp/tt;
	srand(time(NULL));
    pthread_t pid[10];
	pthread_attr_t attr;
    pthread_attr_init(&attr);
	if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }
    int i;
    for (i = 0; i < tt; i++) {
        pthread_create(&pid[i],&attr,runner,NULL);
    }

    for (i = 0; i < tt; i++) {
        pthread_join(pid[i],NULL);
    }

    pthread_mutex_destroy(&lock);
	double pi =(4. * (double)inside) / ((double)tp);
    printf("Pi	: %f  \n", pi);
    return 0;
}

#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>
#include<time.h>

const int max_elves = 15;
const int last_reindeer = 9;

int elves;
int reindeer;
sem_t sem_santa;
sem_t sem_reindeer;
sem_t sem_elf;
sem_t mutex;

void *santa_fun(void *arg)
{
	while(1)
	{
		sem_wait(&sem_santa);
		sem_wait(&mutex);
		if (reindeer == last_reindeer)
		{
			printf("[prepareSleigh] Santa Claus - preparing sleigh\n");
			for (int i = 0; i < last_reindeer; i++)
				sem_post(&sem_reindeer);
			reindeer = 0;
            if(elves>0){
                printf("Will help remaining after trip\n");

            }
           break;
		}
		else if (elves == 3)
		{
			printf("[helpElves]Santa Claus: helping elves\n");
			elves=0;

		}
		sem_post(&mutex);
	}
}

void *reindeer_fun(void *arg)
{

		//sleep(3);
		sem_wait(&mutex);
		reindeer++;
        int id =reindeer;
        printf("[arrived] reindeer - %d \n",reindeer);
		if (reindeer == last_reindeer)
			sem_post(&sem_santa);
		sem_post(&mutex);
		sem_wait(&sem_reindeer);
		//sleep(1);
		printf("[getHitched] Reindeer %d getting hitched\n", id);


}

void *elve_fun(void *arg)
{

		int help = (rand() % 100) < 40;

		if (help)
		{
;
			sem_wait(&sem_elf);
			sem_wait(&mutex);
            printf("Elf needs help\n")	;		
			elves++;
			//printf("%d\n",elves);
			sem_post(&mutex);
			if (elves == 3){
				printf("[getHelp] 3 elfs approching Santa Claus\n");
				sem_post(&sem_santa);
			}
			else
				sem_post(&sem_elf);
                //sem_wait(&sem_elf);
    

			//sleep(3);

			sem_wait(&mutex);
			//elves--;
			if(elves == 0)
				sem_post(&sem_elf);
			sem_post(&mutex);
		}


}

int main()
{
	srand(time(0));
	elves = 0;
	reindeer = 0;
	sem_init(&sem_santa, 0, 0);
	sem_init(&sem_reindeer, 0, 0);
	sem_init(&sem_elf, 0, 1);
	sem_init(&mutex, 0, 1);

	pthread_t p_santaclaus,p_reindeer[last_reindeer],p_elve[max_elves];
    pthread_create(&p_santaclaus,NULL,santa_fun,NULL);
    for(int i = 0; i < max_elves;i++)
    pthread_create(&p_elve[i],NULL,elve_fun,NULL);
	for(int i = 0; i < last_reindeer;i++)
    pthread_create(&p_reindeer[i],NULL,reindeer_fun,NULL);

    pthread_join(p_santaclaus, NULL);
    for(int i = 0; i < last_reindeer;i++)
    pthread_join(p_reindeer[i],NULL);
    return 0;

}

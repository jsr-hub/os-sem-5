/* for compilation use gcc -pthread MySimpleRW.c*/
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXTHREAD 5  /* define # readers */

int SharedData;
	
void* reader();
void* writer();

sem_t rLock,wLock;                /* establish que */

int rc = 0;     /* number of processes reading or wanting to */

int main()
{
    pthread_t rId[MAXTHREAD],wId;
    int i,k[MAXTHREAD];
    //int ids[MAXTHREAD]; /*readers and initialize mutex, q and db-set them to 1*/


    sem_init(&rLock,0,1);
    sem_init(&wLock,0,1);


    for(i=0; i<MAXTHREAD; i++)
    {
	k[i] = i+1;
        if(pthread_create(&rId[i],0,reader,&k[i])!=0)
	{
            perror("Cannot create reader!");
            exit(1);
        }
    }

    if(pthread_create(&wId,0,writer,0)!=0){
        perror("Cannot create writer");
        exit(1);
    }

    pthread_join(wId,0);
    for(i=0; i<MAXTHREAD; i++)
    {
    	pthread_join(rId[i],0);
    }
    
    sem_destroy (&rLock);
    sem_destroy (&wLock);
 
	

    return 0;
}

void* reader(void *arg)                  /* readers function to read */
{
    //sleep(1);
    int id = *(int*)arg;
    while(1)
    {

	sleep(1);
        sem_wait(&rLock);
		rc++;
		if(rc==1)
			sem_wait(&wLock);
        sem_post(&rLock);

        printf("\nReader %d Read Value:%d...",id,SharedData);
	
        sem_wait(&rLock);
            	rc--;
	 	if(rc==0)
			sem_post(&wLock);
       sem_post(&rLock);
    }

    return 0;
}

int getNext()
{	
	static int data=100;
	return data++;
}
void* writer()          /* writer's function to write */
{
    while(1)
    {
    
        sem_wait (&wLock);

            printf("\nWriter is now writing...Number of readers: %d\n",rc);
	    SharedData = getNext();
  
	sem_post (&wLock);
	sleep(1);
    }

    return 0;
}



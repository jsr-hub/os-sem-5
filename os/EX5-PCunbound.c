/* SINGLE PRODUCER CONSUMER */
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

int SharedMemory;   //Memory Going to be shared by Producer & Consumer

sem_t ProdLock,ConsLock;   //Lock Declaration

int p_tid;
int c_tid;

int produce_item();

void put(int);
int get();


void *producer()
{
        int item;

        while(1)
        {
                item=produce_item();

                sem_wait(&ProdLock);    // Lock the ProdLock
			
                put(item);

                printf("Producer Produced: %d\n", item);
                
 		sem_post(&ConsLock);	// After Producing, Unlock the ConsLock
                
        }
}
void *consumer()
{
        int item;

        while(1)
        {
                sleep(1);

                sem_wait(&ConsLock);	//Lock Cons
                
		item=get();

                printf("Consumer Consumed: %d\n",item);

                sem_post(&ProdLock);
		//sem_wait(&Lock);
        }
}

int produce_item()
{
        static int a=100;
        return a++;
}
void put(int item)
{
        SharedMemory = item;
}
int get()
{
	int item = SharedMemory;
	SharedMemory = 0;
        return item;
}
int main()
{
        

        pthread_attr_t *attr = NULL;
        pthread_t pId;
        pthread_t cId;


        sem_init(&ProdLock,0,1);
        sem_init(&ConsLock,0,0);

        
        pthread_create(&pId,attr,producer,0);
        pthread_create(&cId,attr,consumer,0);
        
	pthread_join(pId,NULL);
        pthread_join(cId,NULL);
        
	return 0;
}                                                              

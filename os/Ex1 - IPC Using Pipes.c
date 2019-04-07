
/* System Calls needed to understand are: pipe()/pipe2() and fork() */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> /* pipe(), pipe2() */

int main()
{

	int p[2];// variable is for pipe with array which specifies 0-read, 1-write, 2-both read and write
	pid_t pid;

	char inbuf[10],outbuf[10];//when parent and child are using same buffer using pipes symbols will be displayed as output of communication
 
	if(pipe(p)==-1)  /*  p[0] - Read End,         p[1] - Write End   */
	{
		printf("\nPipe Creation failed....\n");
		return 1;
		//return positive value-> successful creation, 0->Negative Value: creation of a child process was unsuccessful.
//Zero: Returned to the newly created child process.
//Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
	}
	else
		printf("\nInter-Process Communication PIPE is created...\n");

	pid=fork();// creating the child process for which parent is specified. the code will run even if we provide just fork()

	if(pid>0) /*i.e., Parent*/
	{ 
		close(p[0]);
		printf("\n\nChild Process Created Successfully with ID:%d",pid);
		printf("\n\nIn Parent Process: (Process ID: %d): \n",getpid());
		printf("\nEnter the Data to be sent to child: ");
               	scanf("%s",outbuf);
		write (p[1],outbuf,10);
		//sleep(10);
		//printf("\nAfter Sleep in Parent Process...\n");
        }
	else if(pid==0)	/*i.e., Child*/
	{
		sleep(10);
		close(p[1]);
		printf("\n\nIn Child Process: (Process ID: %d):  Waiting for Data From Parent...\n",getpid());
		read(p[0],inbuf,10);
		printf("\nThe Data received by the Child(P-%d) From Parent(P-%d) is: %s\n",getpid(),getppid(),inbuf);
		//sleep(2);
		//printf("After sleep in child\n");
	}
	else 		/*if -1, child process creation error*/
	{
		printf("\n\nNo Child Process is Created....");
		printf("\nPrcess Creation Errorrrrrr...");
		printf("\nBetter Luck Next Time....");
		return 1;
	}

	return 0;
}

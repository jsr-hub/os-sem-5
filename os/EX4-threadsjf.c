#include<stdio.h>
//Program for thread scheduling based on Load sharing (global queue) using FSmallest No of Threads First on Uniprocessor
struct Thread
{
	int st; // service time
	int ft; // finish time
	int status; // thread completed - 1, not completed - 0
};

struct Process
{	
	int at; // arraival time
	int nt; // no of threads
	int ntc; // no of threads completed
	int status; // process completed - 1, not-completed-0
	int ft;	
	struct Thread t[5];
}plist[10];

int n,cur_time=0;

void dispatch(int*,int*);
void main()
{
	int i,j,pid,tid;
	printf("\nEnter the number of processes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the details of the %d process : ",i+1);
		printf("\nEnter the arrival time : ");
		scanf("%d",&plist[i].at);		
		printf("\nEnter the no of threads : ");
		scanf("%d",&plist[i].nt);
		for(j=0;j<plist[i].nt;j++)
		{
			printf("\n-->Enter the service time of thread %d: ",j);
			scanf("%d",&plist[i].t[j].st);
			plist[i].t[j].status=0;
		}
		plist[i].status=0;
		plist[i].ntc=0;
	}
	i=0;
	
	while(i<n) // Until all the n processess completed
	{
		dispatch(&pid,&tid); // Choose the next process and the thread within that process to execute
		if(pid==-1) // If no process is available at this time
		{
			cur_time++;
		}
		else
		{
			int j;
			cur_time+=plist[pid].t[tid].st; // Update clock after the thread completed
			plist[pid].t[tid].ft=cur_time;//Update finish time of the completed thread TID
			plist[pid].ntc++; // Increment no of threads completed within the process PID
			plist[pid].t[tid].status=1; // Update the status of the thread to indicate it is completed
			if(plist[pid].ntc==plist[pid].nt)  // If all the threads of the process PID are completed 
            {
                plist[pid].ft=cur_time; // Update finish time of process PID
       			plist[pid].status=1; // Update completion status of process PID
       			i++; // Increment number of completed processes
            }
		}
	}
	for(i=0;i<n;i++)
	{
         printf("\nPID\tAT\tFT"); 
         printf("\n%d\t",i);          
         printf("%d\t",plist[i].at);
         printf("%d\t",plist[i].ft);
         printf("\nThreads of process %d\n",i);
         printf("TID\tST\t\tFT");
         for(j=0;j<plist[i].nt;j++)
         {
                 printf("\n%d \t",i+1);
		         printf("%d          \t",plist[i].t[j].st);
		         printf("%d          \t",plist[i].t[j].ft);
		         printf("\n");
         }
	}
  getch();
}

void dispatch(int *pid,int *tid)
{
    *pid=*tid=-1;
	int j,k,least=cur_time,id=-1,ntc=100,pd=-1;
	for(j=0;j<n;j++)
	{
		if(plist[j].status != 1) // Process not already completed 
		{
			if(plist[j].at<=cur_time) // Process arrived within the current time
			{
                     if((plist[j].nt-plist[j].ntc)<ntc)
                     {
                              pd=j; 
                              ntc=(plist[j].nt-plist[j].ntc);
                     }
             }
          }
   }
   *pid=pd;
   printf("PID:%d",pd);
   for(k=0;k<plist[pd].nt;k++)
   {
         if(plist[pd].t[k].status==0) // Thread not yet completed
	     {                          
              *tid=k;
                 printf("TID:%d",k);
              return;
         }
    }
}
/* Sample data
No. of processes 3
       AT        NO OF THREADS
P1     0         5            ST
                    T1        3
                    T2        2
                    T3        4
		    T4	      4
		    T5	      3
P2     3        3                 
                    T1        2
                    T2        5
		    T3	      2
p3     4        1     
                    T1        1
Gantt Chart
******************************************************************
0-3	    3-5	    5-6	    6-11	11-13	13-15	15-19	19-23	23-26	
P1T1	P2t1	P3T1	P2T2	P2T3	P1T2	P1T3	P1T4	P1T5
*/

/*
   FIFO Page Replacement Algorithm
   Created by: Pirate
*/
#include<stdio.h>
#include<conio.h>
int n,ref[100],fs,frame[100],count=0;
int f=-1,r=-1;
void input();
void show();
void cal();
void queue(int k);
void main()
{
                 printf("************ FIFO Page Replacement Algo **************\n");
                 input();
                 cal();
                 show();
                 getch();
}
void input()
{
                 int i;
                 printf("Enter the no of pages in Refrence String\t");
                 scanf("%d",&n);
                 printf("Enter Refrence string");
                 for(i=0;i<n;i++)
                 {
                                  scanf("%d",&ref[i]);
                 }
                 printf("Enter the Frame Size\t");
                 scanf("%d",&fs);
}
void cal()
{
                 int i;
                 for(i=0;i<fs;i++)
                 {
                                 frame[i]=-1;
                 }
                 for(i=0;i<n;i++)
                 {
                                  queue(ref[i]);
                 }
}
void queue(int k)
{
                 int i;
                 for(i=0;i<fs;i++)
                 {
                                  if(frame[i]==k)
                                  {
                                                   return;
                                  }
                 }
                 if(r==fs-1)
                 {
                                  r=0;
                 }
                 else if(r==-1)
                 {
                                  f=0;
                                  r=0;
                 }
                 else
                 {
                                  r=r+1;
                 }
                 frame[r]=k;
                 count++;
}
void show()
{
                 printf("Page Faults=%d",count);
}

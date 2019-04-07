#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct MainMem
{
    int start_add;
    int pn;
};

int main()
{
       int s,i,totPages,pno,offset,n,r,arr[200]={0},phy_add,fno[100];
       struct MainMem mm[100];
       srand((unsigned)time(NULL));
       printf("Logical Address To Physical Address\n");
       printf("Enter  the Size of File : ");
       scanf("%d",&n);
       printf("Enter the Page Size : ");
       scanf("%d",&s);
       totPages=n/s;
       for(i=0;i<totPages;i++)
       {
              r=rand()%totPages;
              if(arr[r] == 1)
              {
                           i--;
                           continue;
              }
              arr[r]=1;
              mm[i].pn=r;
              mm[i].start_add=i*s;
              fno[r]=i;
       }
       printf("\n*********************************\n");
       printf("The Structure of Main Memory\n");
       printf("*********************************\n");
       printf("Frame\tPage\nNumber\tNumber\n------\t------\n");
       for(i=0; i < totPages; i++)
       {
              printf("%d\t%d\n",i,mm[i].pn);
       }
       printf("*********************************\n");
       printf("Enter The Logical Address\nPage Number : ");
       scanf("%d",&pno);
       printf("Offset : ");
       scanf("%d",&offset);
       if(pno >= totPages || offset > s)
       {
              printf("Invalid Input\n");
              return 0;
       }
       phy_add = mm[fno[pno]].start_add + offset;
       printf("*********************************\n");
       printf("Physical Address : %d\n",phy_add);
       printf("*********************************\n");
       return 0;
}

/*
Logical Address To Physical Address
Enter  the Size of File : 100
Enter the Page Size : 10

*********************************
The Structure of Main Memory
*********************************
Frame   Page
Number  Number
------  ------
0       1
1       0
2       7
3       3
4       4
5       6
6       8
7       2
8       9
9       5
*********************************
Enter The Logical Address
Page Number : 7
Offset : 7
*********************************
Physical Address : 27
*********************************
*/

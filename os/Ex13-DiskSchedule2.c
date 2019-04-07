#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

main()
{
	int gd=DETECT,gm,x,y,a1,x1,y1,a,b;
	int req[30],head,i,k,move,n,ch,t1,t2,max,min,g[30],c,h;
	initgraph(&gd,&gm,"z:\tcpp\bgi");
	/*int req[30],head,i,k,move,n,ch,t1,t2,max,min,g[30],c,h;*/
	clearviewport();
	printf("(1) LOOK	(2) CLOOK	(3) FCFS	(0) EXIT
Enter your choice: 
");
	scanf("%d",&ch);

	while(ch)
	{
		printf("Enter the current head position: ");
		scanf("%d",&head); h=head;
		printf("Enter the number of requests: ");
		scanf("%d",&n); k=0; move=0;
		printf("Total number of cylinders: 200.
");
		printf("Enter the requests (1 to 200):
");
req:
		for(i=0;i<n;i++)
		{
			scanf("%d",&req[i]);
			if(req[i]>200||req[i]<1)
			{ printf("Enter requests only between 1-200."); goto req; }
		}

		switch(ch)
		{
		case 1:
		outtextxy(270,10,"SEEK PATTERN FOR LOOK");
		max=req[0]; min=req[0]; t2=1; c=0;
		for(i=1;i<n;i++)
		{
			max=max>req[i]?max:req[i];
			min=min<req[i]?min:req[i];
		}
		if(max<=head) t2=0;
		while(k<n)
		{
			t1=0;
			for(i=0;i<n;i++)
			{
				if(t2)
				{
					if(req[i]&&req[i]>=head)
					{
						if(req[i]<req[t1]) t1=i;
						if(req[i]==max)
						{ t2=0; g[c]=1; c++; }
					}
				}

				else
				{
					if(req[i]&&req[i]<=head)
					{
						if(req[i]>req[t1]) t1=i;
						if(req[i]==min)
						{ t2=1; g[c]=200; c++; }
					}
				}
			}/*for*/
			printf("%d ",req[t1]);
			g[c]=req[t1]; c++;
			move+=abs(head-req[t1]);
			req[t1]=0; k++;
			head=req[t1];
			if(head==max) t2=0;
		}/*while*/
		break;

		case 2:
		outtextxy(270,10,"SEEK PATTERN FOR CLOOK");
		max=req[0]; min=req[0]; t2=1; c=0;
		for(i=1;i<n;i++)
		{
			max=max>req[i]?max:req[i];
			min=min<req[i]?min:req[i];
		}
		while(k<n)
		{
			t1=0;
			if(!t2) head=min;
			for(i=0;i<n;i++)
			{
				if(req[i]&&req[i]>=head)
				{
					if(req[i]<req[t1]) t1=i;
					else if(req[i]==max)
					{ head=1; g[c]=1; c++; }
				}
			}/*for*/
			printf("%d ",req[t1]);
			move+=abs(head-req[t1]);
			head=req[t1];
			g[c]=req[t1]; c++;
			req[t1]=0; k++;
			if(head==max) t2=0;
		}/*while*/
		break;

		case 3:
		outtextxy(270,10,"SEEK PATTERN FOR FCFS");
		for(i=0,c=0;i<n;i++,c++)
		{
			printf("%d ",req[i]);
			move+=abs(head-req[i]);
			head=req[i];
			g[c]=req[i];
		}
		break;
		}/*switch*/
		printf("Order of servicing:
");
		printf("%d: ",h);
		for(i=0;i<n;i++)
			printf("%d ",g[i]);
		printf("
Total Head Movements: %d
",move);
		x=getmaxx();
		y=getmaxy();
		rectangle(0,20,x-5,y-5);

		a1=(x-30)/10;

		b=110; a=h+(3*a1); y1=125;
		fillellipse(a,b,2,2);


		for(i=0;i<n;i++)
		{
		int x1=g[i]+(3*a1);
		fillellipse(x1,y1,2,2);
		line(a,b,x1,y1);
		a=x1; b=y1;
		y1+=15;
		}

		getch();
		clrscr(); clearviewport();
		printf("
(1) LOOK	(2) CLOOK	(3) FCFS	(0) EXIT
Enter your choice:
");
		scanf("%d",&ch);
	}/*while*/
getch();
}/*main*/

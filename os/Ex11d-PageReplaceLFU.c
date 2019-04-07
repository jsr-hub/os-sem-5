

#include<stdio.h>

int main()
{
      int total_frames, total_pages, hit = 0;
      int pages[25], frame[10], arr[25], time[25];
      int m, n, page, flag, k, minimum_time, temp;
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &total_pages); 
      printf("Enter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frame[m] = -1;
      }
      for(m = 0; m < 25; m++)
      {
            arr[m] = 0;
      }
      printf("Enter Values of Reference String\n");
      for(m = 0; m < total_pages; m++)
      {
            printf("Enter Value No.[%d]:\t", m + 1);
            scanf("%d", &pages[m]);
      }
      printf("\n");
      for(m = 0; m < total_pages; m++)
      {
            arr[pages[m]]++;
            time[pages[m]] = m;
            flag = 1;
            k = frame[0];
            for(n = 0; n < total_frames; n++)
            {
                  if(frame[n] == -1 || frame[n] == pages[m])
                  {
                        if(frame[n] != -1)
                        {
                              hit++;
                        }
                        flag = 0;
                        frame[n] = pages[m];
                        break;
                  }
                  if(arr[k] > arr[frame[n]])
                  {
                        k = frame[n];
                  }
            }
            if(flag)
            {
                  minimum_time = 25;
                  for(n = 0; n < total_frames; n++)
                  {
                        if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
                        {
                              temp = n;
                              minimum_time = time[frame[n]];
                        }
                  }
                  arr[frame[temp]] = 0;
                  frame[temp] = pages[m];
            }
            for(n = 0; n < total_frames; n++)
            {
                  printf("%d\t", frame[n]);
            }
            printf("\n");
      }
      printf("Page Hit:\t%d\n", hit);
      return 0;
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
#include<stdio.h>
 
int main()
{
      int total_frames, total_pages, hit = 0;
      int pages[25], frame[10], arr[25], time[25];
      int m, n, page, flag, k, minimum_time, temp;
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &total_pages); 
      printf("Enter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frame[m] = -1;
      }
      for(m = 0; m < 25; m++)
      {
            arr[m] = 0;
      }
      printf("Enter Values of Reference String\n");
      for(m = 0; m < total_pages; m++)
      {
            printf("Enter Value No.[%d]:\t", m + 1);
            scanf("%d", &pages[m]);
      }
      printf("\n");
      for(m = 0; m < total_pages; m++)
      {
            arr[pages[m]]++;
            time[pages[m]] = m;
            flag = 1;
            k = frame[0];
            for(n = 0; n < total_frames; n++)
            {
                  if(frame[n] == -1 || frame[n] == pages[m])
                  {
                        if(frame[n] != -1)
                        {
                              hit++;
                        }
                        flag = 0;
                        frame[n] = pages[m];
                        break;
                  }
                  if(arr[k] > arr[frame[n]])
                  {
                        k = frame[n];
                  }
            }
            if(flag)
            {
                  minimum_time = 25;
                  for(n = 0; n < total_frames; n++)
                  {
                        if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
                        {
                              temp = n;
                              minimum_time = time[frame[n]];
                        }
                  }
                  arr[frame[temp]] = 0;
                  frame[temp] = pages[m];
            }
            for(n = 0; n < total_frames; n++)
            {
                  printf("%d\t", frame[n]);
            }
            printf("\n");
      }
      printf("Page Hit:\t%d\n", hit);
      return 0;
}
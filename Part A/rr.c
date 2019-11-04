#include<stdio.h>

void main()
{
	int count,j,n,time,remain,flag=0,time_quantum,wait_time=0,turnaround_time=0,at[20],bt[20],rt[20];
	printf("Enter the number of Processes:");
	scanf("%d",&n);
	remain=n;
	printf("\nEnter Arrival Times(in ms) for Processes:");
	for (count = 0; count < n; count++)
	{
    	printf("\nProcess %d:",count+1);
    	scanf("%d",&at[count]);
	}
	printf("\nEnter Burst Times(in ms) for Processes:");
	for (count = 0; count< n; count++)
	{
    	printf("\nProcess %d:",count+1);
    	scanf("%d",&bt[count]);
    	rt[count]=bt[count];
	}
	printf("\nEnter the Time Quantum:");
	scanf("%d",&time_quantum);
	printf("\nProcesses  Turn Around Time  Waiting Time");
	for(time=0,count=0;remain!=0;)
	{
    	if ((rt[count]<=time_quantum)&&(rt[count]>0))
    	{
        	time+=rt[count];
        	rt[count]=0;
        	flag=1;
    	}
    	else if (rt[count]>0)
    	{
        	rt[count]-=time_quantum;
        	time+=time_quantum;
    	}
    	if ((rt[count]==0)&&(flag==1))
    	{
        	remain--;
        	printf("\n%d\t\t%d\t\t%d",count+1,time-at[count],time-at[count]-bt[count]);
        	wait_time+=time-at[count]-bt[count];
        	turnaround_time+=time-at[count];
        	flag=0;
    	}
    	if (count==n-1)
    	{
        	count=0;
    	}
    	else if(at[count+1]<=time)                   	 
    	{
        	count++;
    	}
    	else
    	{
        	count=0;
    	}
	}
	printf("\nAverage Waiting Time=%f",(float)(wait_time*1.0/n));
	printf("\nAverage Turn Around Time:%f",(float)(turnaround_time*1.0/n));
}

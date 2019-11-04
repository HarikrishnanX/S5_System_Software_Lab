#include<stdio.h>

void findWaitingTime(int processes[],int n,int bt[],int wt[],int at[])
{
	int service_time[n];
	service_time[0]=0;
	wt[0]=0;
	for (int i = 1; i < n; i++)
	{
    	service_time[i]=service_time[i-1]+bt[i-1];
    	wt[i]=service_time[i]-at[i];
    	if (wt[i]<0)
    	{
        	wt[i]=0;
    	}   
	}
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
    	tat[i]=bt[i]+wt[i];
}

void findavgTime(int processes[],int n,int bt[],int at[])
{
	int wt[n],tat[n];
	findWaitingTime(processes,n,bt,wt,at);
	findTurnAroundTime(processes,n,bt,wt,tat);
	printf("\nProcesses  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time");
	int total_wt=0,total_tat=0;
	for (int i = 0; i < n; i++)
	{
    	total_wt=total_wt+wt[i];
    	total_tat=total_tat+tat[i];
    	int compl_time=tat[i]+at[i];
    	printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],at[i],wt[i],tat[i],compl_time);
	}
	printf("\nAverage waiting time=%f",(float)total_wt/(float)n);
	printf("\nAverage turn around time=%f",(float)total_tat/(float)n);
}

void main()
{
	int processes[20],n,burst_time[20],arrival_time[20],i;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	printf("\nEnter Burst Times(in ms) of Processes:");
	for (i = 0; i < n; i++)
	{
    	printf("\nProcess %d:",i+1);
    	scanf("%d",&burst_time[i]);
	}
	printf("\nEnter Arrival Times(in ms) of Processes:");
	for (i = 0; i < n; i++)
	{
    	printf("\nProcess %d:",i+1);
    	scanf("%d",&arrival_time[i]);
	}
	findavgTime(processes,n,burst_time,arrival_time);
}


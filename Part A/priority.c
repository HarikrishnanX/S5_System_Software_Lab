#include<stdio.h>

void main()
{
	int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total_wt=0,total_tat=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter the number of Processes:");
	scanf("%d",&n);
	printf("\nEnter the Burst Times(in ms) for Processes:");
	for(i=0;i<n;i++)
	{
    	printf("\nProcess %d:",i+1);
    	scanf("%d",&bt[i]);
    	p[i]=i+1;
	}
	printf("\nEnter the Priority values for Processes:");
	for(i=0;i<n;i++)
	{
    	printf("\nProcess %d:",i+1);
    	scanf("%d",&pr[i]);
	}
	for(i=0;i<n;i++)
	{
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
        	if(pr[j]<pr[pos])
        	{
            	pos=j;
        	}
    	}
    	temp=pr[i];
    	pr[i]=pr[pos];
    	pr[pos]=temp;
   	 
    	temp=bt[i];
    	bt[i]=bt[pos];
    	bt[pos]=temp;

    	temp=p[i];
    	p[i]=p[pos];
    	p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
    	wt[i]=0;
    	for(j=0;j<i;j++)
    	{
        	wt[i]+=bt[j];
    	}
    	total_wt+=wt[i];
	}
	avg_wt=total_wt/n;
	printf("\nProcesses  Burst Time  Waiting Time  Turn Around Time");
	for(i=0;i<n;i++)
	{
    	tat[i]=bt[i]+wt[i];
    	total_tat+=tat[i];
    	printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=total_tat/n;
	printf("\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turn Around Time=%f",avg_tat);
}

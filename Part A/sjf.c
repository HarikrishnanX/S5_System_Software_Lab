#include<stdio.h>
 
void main()
{
	int bt[20],p[20],wt[20],tat[20],i,j,n,total_tat=0,total_wt=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("\nEnter Burst Times(in ms) for Processes:");
	for(i=0;i<n;i++)
	{
    	printf("\nProcess %d:",i+1);
    	scanf("%d",&bt[i]);
    	p[i]=i+1;      	 
	}
	for(i=0;i<n;i++)
	{
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
        	if(bt[j]<bt[pos])
            	pos=j;
    	}
 
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
        	wt[i]+=bt[j];
 
    	total_wt+=wt[i];
	}
	avg_wt=(float)total_wt/n; 	 
	printf("\nProcess  Burst Time  Waiting Time  Turn Around Time");
	for(i=0;i<n;i++)
	{
    	tat[i]=bt[i]+wt[i];	 
    	total_tat+=tat[i];
    	printf("\n%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total_tat/n;	 
	printf("\n\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

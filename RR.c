// Round Robin Implementation

#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid, at, bt, ct, tat, wt, flag;
};

void RR(int n,int at[n],int bt[n])
{
    int tq;
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    int i,j,k=0,flag=0;
    int ct[n],tat[n],wt[n];
    int rem_bt[n];
    for(i=0;i<n;i++)
    {
        rem_bt[i]=bt[i];
    }
    int t=0;
    while(1)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(rem_bt[i]>0)
            {
                flag=1;
                if(rem_bt[i]>tq)
                {
                    t+=tq;
                    rem_bt[i]-=tq;
                }
                else
                {
                    t+=rem_bt[i];
                    rem_bt[i]=0;
                    ct[i]=t;
                }
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    float avg_tat=0,avg_wt=0;
    for(i=0;i<n;i++)
    {
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("Average TAT: %f\nAverage WT: %f\n",avg_tat,avg_wt);
}

void main()
{
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    RR(n,at,bt);
}
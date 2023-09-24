// write a c program to implement the non preemptive shortest job first scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid, at, bt, ct, tat, wt, flag;
};

void SJF(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].bt>p[j+1].bt)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

// pre-emptive SJF scheduling algorithm

void PreSJF(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].bt>p[j+1].bt)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void main()
{
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[n],temp;
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
        p[i].flag=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int time=0;
    float avg_tat=0,avg_wt=0;
    for(i=0;i<n;i++)
    {
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time: %f\n",avg_tat);
    printf("Average Waiting Time: %f\n",avg_wt);
    int cpu=(time-p[0].at)*100/time;
    printf("CPU Utilization: %d\n",cpu);
}
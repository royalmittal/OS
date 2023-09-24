// write a c program to implement the non preemptive priority scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid, at, bt, ct, tat, wt, flag, priority;
};

void prioritySeletionSort(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].priority>p[j+1].priority)
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
        printf("Enter the priority of process %d: ",i+1);
        scanf("%d",&p[i].priority);
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
        int min=9999,index=-1;
        for(j=0;j<n;j++)
        {
            if(p[j].at<=time && p[j].flag==0)
            {
                if(p[j].priority<min)
                {
                    min=p[j].priority;
                    index=j;
                }
            }
        }
        if(index==-1)
        {
            time++;
            i--;
            continue;
        }
        p[index].ct=time+p[index].bt;
        p[index].tat=p[index].ct-p[index].at;
        p[index].wt=p[index].tat-p[index].bt;
        avg_tat+=p[index].tat;
        avg_wt+=p[index].wt;
        p[index].flag=1;
        time=p[index].ct;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time: %f\n",avg_tat/n);
    printf("Average Waiting Time: %f\n",avg_wt/n);
    int cpu_utilization=(time-p[0].at)*100/time;
    printf("CPU Utilization: %d\n",cpu_utilization);
}
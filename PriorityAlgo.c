// write a c program for premptive priority scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid, at, bt, ct, tat, wt, flag, priority;
};

void PremptivePriority(struct p[],int n)
{
    int i, j, time = 0, count = 0, max = 0, index = 0;
    float avg_tat = 0, avg_wt = 0;
    printf("\n\nPremptive Priority Scheduling\n\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tPriority\n");
    for(i = 0; i < n; i++)
    {
        p[i].flag = 0;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
    }
    while(count < n)
    {
        max = 0;
        for(i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].flag == 0)
            {
                if(p[i].priority > max)
                {
                    max = p[i].priority;
                    index = i;
                }
            }
        }
        p[index].flag = 1;
        p[index].ct = time + 1;
        p[index].tat = p[index].ct - p[index].at;
        p[index].wt = p[index].tat - p[index].bt;
        avg_tat += p[index].tat;
        avg_wt += p[index].wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[index].pid, p[index].at, p[index].bt, p[index].ct, p[index].tat, p[index].wt, p[index].priority);
        count++;
        time++;
    }
    printf("\nAverage Turn Around Time: %f\n", avg_tat/n);
    printf("Average Waiting Time: %f\n", avg_wt/n);
}

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n], temp;
    for(i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &p[i].bt);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &p[i].priority);
        p[i].pid = i+1;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    PremptivePriority(p, n);
    return 0;
}
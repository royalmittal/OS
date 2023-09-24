// lab 3 & 4
//  FCFS ALGORITHIM IN C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void fcfs(int n,int at[], int bt[], int wt[], int tat[])
{
    wt[0] = 0;
    tat[0] = bt[0];
    int ct = bt[0];
    int rt = 0;
    for (int i = 1; i < n; i++){
        wt[i] = ct - at[i];
        ct += bt[i];
        tat[i] = wt[i] + bt[i];
        rt += wt[i];
    }
    int avgWT = rt / n;
    int avgTAT = (rt + ct) / n;
    printf("Average waiting time: %d\n", avgWT);
    printf("Average turn around time: %d\n", avgTAT);
}

void ganttChart(int n, int at[], int bt[])
{
    int ct = 0;
    int rt = 0;
    printf("\n");
    printf("Gantt Chart\n\n\t");
    for (int i = 0; i < n; i++){
        printf("P%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d\t", ct);
        ct += bt[i];
    }
    printf("%d\n", ct);
    printf("\n");
}

// Lab 4

void sort(int n, int at[], int bt[])
{
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (at[j] > at[j + 1]){
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
}

void fcfs2(int n,int at[], int bt[])
{
    int wt[n], tat[n];
    wt[0] = 0;
    tat[0] = bt[0];
    int ct = bt[0];
    int rt = 0;
    for (int i = 1; i < n; i++){
        wt[i] = ct - at[i];
        ct += bt[i];
        tat[i] = wt[i] + bt[i];
        rt += wt[i];
    }
    int avgWT = rt / n;
    int avgTAT = (rt + ct) / n;
    printf("Average waiting time: %d\n", avgWT);
    printf("Average turn around time: %d\n", avgTAT);
    int cpu_utl = (bt[n - 1] / ct) * 100;
    printf("CPU utilization: %d\n", cpu_utl);
}
int main()
{
    int n, *at, *bt, *wt, *tat, *ct ,*rt;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    rt = (int *)malloc(n * sizeof(int));
    printf("Enter the arrival time of the processes: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &at[i]);
    }
    printf("Enter the burst time of the processes: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }
    sort(n, at, bt);
    fcfs(n, at, bt, wt, tat);
    ganttChart(n, at, bt);
    printf("Process\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t\n", i, at[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}





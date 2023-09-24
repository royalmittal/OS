// SRTF ALGORITHIM IN C

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void srtf(int n,int bt[],int at[],int wt[],int tat[],int rt[]){
    int i,j,remain=n,smallest,complete=0,time=0;
    int check[n];
    for(i=0;i<n;i++){
        check[i]=0;
        rt[i]=bt[i];
    }
    while(remain!=0){
        smallest=9;
        for(i=0;i<n;i++){
            if(at[i]<=time && check[i]==0 && rt[i]<rt[smallest] && rt[i]>0){
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0){
            check[smallest]=1;
            remain--;
            complete=1;
            wt[smallest]=time+1-at[smallest]-bt[smallest];
            if(wt[smallest]<0){
                wt[smallest]=0;
            }
        }
        if(complete==1){
            time++;
            complete=0;
        }
    }

    
}

void ganttchart(int n,int bt[],int at[],int wt[],int tat[],int rt[]){
    int i,j;
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        printf("P[%d]\t|\t%d\t|\t%d\n",i+1,tat[i],wt[i]);
    }
    printf("\n\nGantt Chart\n\n");
    for(i=0;i<n;i++){
        printf("P[%d]\t",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d\t",tat[i]);
    }
    printf("\n");
}

int main(){
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n],at[n],wt[n],tat[n],rt[n];
    printf("Enter the burst time and arrival time of the processes: \n");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i+1);
        scanf("%d %d",&bt[i],&at[i]);
    }
    srtf(n,bt,at,wt,tat,rt);
    ganttchart(n,bt,at,wt,tat,rt);
    return 0;
}
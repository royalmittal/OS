#include<stdio.h>

int main() 
{ 
    int i, j, m, n, k = 0, count = 0; 
    int alloc[10][10], max[10][10], avail[10], need[10][10], finish[10], safe[10]; 

    printf("Enter the number of resources : ");
    scanf("%d", &m);

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("Enter Allocation Matrix : ");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Maximum Matrix : ");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources : ");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]); 
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        break;
                    }
                }

                if(j == m) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is not in safe state");
            return 0; 
        }
    }

    printf("System is in safe state.\nThe safe sequence is : ");
    for(i = 0; i < n; i++) {
        printf("%d ", safe[i]);
    }

    return 0;
}

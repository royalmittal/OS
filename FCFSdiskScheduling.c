#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk request sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("\nSequence of disk head movement:\n");
    printf("%d -> ", head);

    for(i = 0; i < n; i++) {
        total_movement += abs(requests[i] - head);
        head = requests[i];
        printf("%d -> ", head);
    }

    printf("\n\nTotal head movement: %d\n", total_movement);

    return 0;
}


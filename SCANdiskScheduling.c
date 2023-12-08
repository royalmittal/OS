#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, direction, total_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk request sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    int max_cylinder = 199; // Maximum cylinder number

    printf("\nSequence of disk head movement:\n");

    if (direction == 0) {
        // Left direction
        printf("%d -> ", head);
        for(i = head - 1; i >= 0; i--) {
            total_movement += abs(head - i);
            head = i;
            printf("%d -> ", head);
        }
        total_movement += abs(head - 0);
        head = 0;
        printf("%d -> ", head);
        for(i = 1; i <= max_cylinder; i++) {
            if (i == requests[n - 1])
                break;
            total_movement += abs(head - i);
            head = i;
            printf("%d -> ", head);
        }
    } else {
        // Right direction
        printf("%d -> ", head);
        for(i = head + 1; i <= max_cylinder; i++) {
            total_movement += abs(head - i);
            head = i;
            printf("%d -> ", head);
        }
        total_movement += abs(head - max_cylinder);
        head = max_cylinder;
        printf("%d -> ", head);
        for(i = max_cylinder - 1; i >= 0; i--) {
            if (i == requests[n - 1])
                break;
            total_movement += abs(head - i);
            head = i;
            printf("%d -> ", head);
        }
    }

    printf("\n\nTotal head movement: %d\n", total_movement);

    return 0;
}

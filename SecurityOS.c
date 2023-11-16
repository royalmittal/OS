#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool hasReadPermission(const char* user, const char* resource) {
    if (strcmp(user, "admin") == 0) {
        return true;    // Admin has read permission for all resources
    } else if (strcmp(user, "guest") == 0 && strcmp(resource, "public") == 0) {
        return true;    // Guest has read permission for the public resource
    } else if (strcmp(user, "user1") == 0 && strcmp(resource, "private") == 0) {
        return true;    // User1 has read permission for the private resource
    } else {
        return false;   // No read permission for other combinations
    }
}

int main() {
    char user[50];
    char resource[50];

    printf("Enter username: ");
    scanf("%s", user);

    printf("Enter resource: ");
    scanf("%s", resource);

    // Check if the user has read permission for the resource
    if (hasReadPermission(user, resource)) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}
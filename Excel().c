#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        execl("/bin/date", "date", NULL);
        perror("execl"); // This line will be reached only if execl fails
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Is\n");
        wait(NULL);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[256];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[0]); // Close unused read end

        char message[] = "Hello from child process!";
        write(pipefd[1], message, sizeof(message));
        close(pipefd[1]);

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(pipefd[1]); // Close unused write end

        wait(NULL); // Wait for child process to complete

        read(pipefd[0], buffer, sizeof(buffer));
        printf("Message received from child process: %s\n", buffer);
        close(pipefd[0]);

        exit(EXIT_SUCCESS);
    }

    return 0;
}

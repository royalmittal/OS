#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t child_pid;
    char message[] = "Hello, child process!";

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the write end of the pipe

        char buffer[1024];
        ssize_t num_bytes = read(pipefd[0], buffer, sizeof(buffer));
        buffer[num_bytes] = '\0';

        printf("Child received message from parent: %s\n", buffer);

        close(pipefd[0]);  // Close the read end of the pipe

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(pipefd[0]);  // Close the read end of the pipe

        ssize_t num_bytes = write(pipefd[1], message, sizeof(message));

        printf("Parent sent message to child: %s\n", message);

        close(pipefd[1]);  // Close the write end of the pipe

        wait(NULL);  // Wait for the child process to finish

        exit(EXIT_SUCCESS);
    }
}
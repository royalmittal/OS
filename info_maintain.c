#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2]; // File descriptors for the pipe
    pid_t child_pid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) { // Child process
        close(pipe_fd[1]); // Close the write end of the pipe in the child

        char message[100];
        ssize_t bytes_read = read(pipe_fd[0], message, sizeof(message));
        if (bytes_read == -1) {
            perror("read");
            return 1;
        }

        printf("Child received: %.*s", (int)bytes_read, message);

        close(pipe_fd[0]);
        return 0;
    } else { // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe in the parent

        const char *message = "Hello from Parent!";
        ssize_t bytes_written = write(pipe_fd[1], message, strlen(message));
        if (bytes_written == -1) {
            perror("write");
            return 1;
        }

        close(pipe_fd[1]);

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    // Specify the file path
    const char *file_path = "example.txt";

    // Create or open a file for writing
    int fd = open(file_path, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write data to the file
    const char *data = "Hello, World!\n";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Open the file for reading
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read data from the file
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Print the data read from the file
    printf("Data read from file: %.*s", (int)bytes_read, buffer);

    // Delete the file
    if (remove(file_path) == -1) {
        perror("remove");
        return 1;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the device file (/dev/random) for reading
    int fd = open("/dev/random", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read random data from the device file
    unsigned char buffer[128]; // Buffer to store random data
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Close the device file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Print the random data
    printf("Random Data:\n");
    for (ssize_t i = 0; i < bytes_read; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    return 0;
}

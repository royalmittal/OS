// device manipulation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    int fd, len;
    char buf[MAX_SIZE];
    char *nodename = "/dev/MyCharDevice";
    if(argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return -1;
    }
    fd = open(nodename, O_RDWR);
    if(fd < 0)
    {
        printf("Cannot open device file...\n");
        return -1;
    }
    strcpy(buf, argv[1]);
    len = strlen(buf);
    write(fd, buf, len);
    read(fd, buf, len);
    printf("Read from device: %s\n", buf);
    close(fd);
    return 0;
}
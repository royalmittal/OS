#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_COUNT 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
    int is_deleted;
} File;

File file_system[MAX_FILE_COUNT];
int file_count = 0;

void create_file(const char* name) {
    if (file_count >= MAX_FILE_COUNT) {
        printf("File system is full\n");
        return;
    }

    if (strlen(name) >= MAX_FILE_NAME_LENGTH) {
        printf("File name is too long\n");
        return;
    }

    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, name) == 0 && !file_system[i].is_deleted) {
            printf("File already exists\n");
            return;
        }
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = 0;
    new_file.is_deleted = 0;

    file_system[file_count] = new_file;
    file_count++;

    printf("File created successfully\n");
}

void write_file(const char* name, const char* data) {
    int file_index = -1;

    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, name) == 0 && !file_system[i].is_deleted) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found\n");
        return;
    }

    File* file = &file_system[file_index];
    strncpy(file->data, data, MAX_FILE_SIZE);
    file->size = strlen(data);

    printf("Data written to file successfully\n");
}

void read_file(const char* name) {
    int file_index = -1;

    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, name) == 0 && !file_system[i].is_deleted) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found\n");
        return;
    }

    File* file = &file_system[file_index];
    printf("File content: %s\n", file->data);
}

void delete_file(const char* name) {
    int file_index = -1;

    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, name) == 0 && !file_system[i].is_deleted) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found\n");
        return;
    }

    file_system[file_index].is_deleted = 1;

    printf("File deleted successfully\n");
}

int main() {
    create_file("file1.txt");
    write_file("file1.txt", "This is some data");
    read_file("file1.txt");
    delete_file("file1.txt");

    return 0;
}
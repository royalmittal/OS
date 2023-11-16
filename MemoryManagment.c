#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define TOTAL_MEMORY_SIZE 65536
#define MAX_PROCESS_SIZE 16384

typedef struct {
    int page_number;
    int process_id;
} PageTableEntry;

PageTableEntry page_table[TOTAL_MEMORY_SIZE / PAGE_SIZE];

void initialize_memory_manager() {
    for (int i = 0; i < TOTAL_MEMORY_SIZE / PAGE_SIZE; i++) {
        page_table[i].page_number = -1;
        page_table[i].process_id = -1;
    }
}

int allocate_memory(int process_id, int memory_size) {
    if (memory_size % PAGE_SIZE != 0) {
        printf("Memory size must be a multiple of page size\n");
        return -1;
    }

    int num_pages = memory_size / PAGE_SIZE;
    int allocated_pages = 0;

    for (int i = 0; i < TOTAL_MEMORY_SIZE / PAGE_SIZE; i++) {
        if (page_table[i].page_number == -1 && page_table[i].process_id == -1) {
            page_table[i].page_number = allocated_pages;
            page_table[i].process_id = process_id;
            allocated_pages++;

            if (allocated_pages == num_pages) {
                return num_pages;
            }
        }
    }

    printf("Not enough free memory\n");
    return -1;
}

void deallocate_memory(int process_id) {
    for (int i = 0; i < TOTAL_MEMORY_SIZE / PAGE_SIZE; i++) {
        if (page_table[i].process_id == process_id) {
            page_table[i].page_number = -1;
            page_table[i].process_id = -1;
        }
    }
}

int access_memory(int process_id, int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;

    if (page_table[page_number].process_id != process_id) {
        printf("Invalid memory access\n");
        return -1;
    }

    int physical_address = page_table[page_number].page_number * PAGE_SIZE + (virtual_address % PAGE_SIZE);
    return physical_address;
}

int main() {
    initialize_memory_manager();

    int process_id = 1;
    int memory_size = MAX_PROCESS_SIZE;

    int allocated_pages = allocate_memory(process_id, memory_size);
    if (allocated_pages != -1) {
        printf("%d pages allocated to process %d\n", allocated_pages, process_id);

        int virtual_address = 8192;
        int physical_address = access_memory(process_id, virtual_address);
        if (physical_address != -1) {
            printf("Process %d accessed virtual address %d, physical address: %d\n", process_id, virtual_address, physical_address);
        }
    }

    deallocate_memory(process_id);
    printf("Memory deallocated for process %d\n", process_id);

    return 0;
}
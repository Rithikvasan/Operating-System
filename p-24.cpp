#include <stdio.h>
#include <stdint.h>

#define DISK_BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // bytes
#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE)
#define TRIPLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE)

uint64_t calculate_max_file_size() {
    uint64_t max_file_size = 0;

    // Calculate the maximum file size based on the number of direct, single indirect, double indirect, and triple indirect blocks
    max_file_size += DIRECT_BLOCKS * DISK_BLOCK_SIZE; // Direct blocks
    max_file_size += SINGLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE; // Single indirect blocks
    max_file_size += DOUBLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE * POINTER_SIZE; // Double indirect blocks
    max_file_size += TRIPLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE * POINTER_SIZE * POINTER_SIZE; // Triple indirect blocks

    return max_file_size;
}

int main() {
    uint64_t max_file_size = calculate_max_file_size();
    printf("Maximum file size that can be stored in the file system: %llu bytes\n", max_file_size);

    return 0;
}


#include <stdio.h>

typedef struct {
    int size;
    int allocated; // 0 --> not allocated. 1 --> allocated
    int num_block; 
} MemoryBlock;

typedef struct {
    int pid;
    int size;
    int allocated; // 0 --> not allocated. 1 --> allocated
    int block_index;
} Process;

int main() {
    int numblock;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numblock);

    MemoryBlock MemoryBlocks[numblock];
    Process Processes[numblock];

    int i, j;
    printf("\nEnter the size of  each memory block :\n");
    for (i = 0; i < numblock; i++) {
        printf("Enter the size of the memory block %d: ", i + 1);
        scanf("%d", &MemoryBlocks[i].size);
        MemoryBlocks[i].allocated = 0;
        MemoryBlocks[i].num_block = i + 1;
    }
    printf("\nEnter the size of each process :\n");
    for (i = 0; i < numblock; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &Processes[i].size);
        Processes[i].pid = i + 1;
        Processes[i].allocated = 0;
        Processes[i].block_index = -1;
    }

   // first fit generating
    for (i = 0; i < numblock; i++) {
        for (j = 0; j < numblock; j++) {
        if (MemoryBlocks[j].allocated == 0 && Processes[i].size <= MemoryBlocks[j].size) {
            MemoryBlocks[j].allocated = 1;
            Processes[i].allocated = 1;
            Processes[i].block_index = j; // Assign the block index
            MemoryBlocks[j].size = MemoryBlocks[j].size - Processes[i].size; // Update remaining block size
            break; // Move to the next process after allocation
        }
    }
}

    for (i = 0; i < numblock; i++) {
        printf("\nProcess PID: %d\n",Processes[i].pid);
        printf("Process size: %d\n",Processes[i].size);
        if (Processes[i].allocated == 1) {
            printf("Status: Allocated\n");
            printf("Block number: %d\n", MemoryBlocks[Processes[i].block_index].num_block);
            printf("Remaining Size of block: %d\n", MemoryBlocks[Processes[i].block_index].size);
        } else {
            printf("Status: Not allocated\n");
        }
    }
    return 0;
}

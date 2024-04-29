#include <stdio.h>
#include <stdlib.h>
// Creating MEMORY BLOCK CONTAINS : SIZE,STATUS,PID
typedef struct {
    int size_Memory; // Memory block size
    char status;     // Status: F for Free and A for Allocated
    int processID;   // Process ID if allocated. if not return -1
} Memory_block;
//Creating PROCESS BLOCK CONTAINS : PID,SIZE
typedef struct {
    int id;           // Process ID
    int size_Process; // Process size
} Process_block;
	void display_head() {
            printf(" *****   *****  *****   *****       *****  ***  *****\n");
    		printf("*    *  *      **         *        **       *     *\n");
    		printf("*****   ****    *****     *        ****     *     *\n");
    		printf("*    *  *           **    *        **       *     *\n");
            printf("*****   *****  *****      *        **      ***    *\n");
}
int main() {
    Memory_block Memory_blocks[100]; //array of MEMORY BLOCKS
    Process_block Process_blocks[100]; //array of PROCESS BLOCKS
    int n,i,j,remainMemorySize;
    display_head();
    // Input the number of memory blocks
    do {
        printf("Enter the number of memory blocks you want (1-100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    // Input memory block sizes
    printf("Enter the size of each memory block:\n");
    for ( i = 0; i < n; i++) {
        printf("Memory block N%d: ", i + 1);
        scanf("%d", &Memory_blocks[i].size_Memory);
        Memory_blocks[i].status = 'F'; // Initializing status as F(free)
        Memory_blocks[i].processID = -1; // Initialize process id as -1 (not allocated)
    }

    // Display memory blocks before allocation
    printf("\n------------ MEMORY BLOCKS ------------\n");
    printf("---------------------------------------\n");
    printf(" Memory block    Size    Status\n");
    for ( i = 0; i < n; i++) {
        printf(" %d               %-10d %c\n", i + 1, Memory_blocks[i].size_Memory, Memory_blocks[i].status);
    }
    printf("---------------------------------------\n\n");

    // Input process sizes
    printf("Enter the size of each process:\n");
    for ( i = 0; i < n; i++) {
        printf("Process N%d: ", i + 1);
        scanf("%d", &Process_blocks[i].size_Process);
        Process_blocks[i].id = i + 1; // Assign process ID
    }

    // Display process blocks
    printf("------------ PROCESS BLOCKS -----------\n");
    printf("---------------------------------------\n");
    printf(" PID                   Process size\n");
    for ( i = 0; i < n; i++) {
        printf(" %-10d             %d\n", Process_blocks[i].id, Process_blocks[i].size_Process);
    }
    printf("---------------------------------------\n");

    // Perform memory allocation using best fit algorithm
    printf("\nMemory Allocation Results:\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf(" PID     Process size    Memory block                 Status           Remain Memory\n");
    for ( i = 0; i < n; i++) {
        int bestFitIndex = -1;
        int min = Memory_blocks[0].size_Memory;

        // Best fit manipulation
        for (j = 0; j < n; j++) {
            if (Memory_blocks[j].status == 'F' && Memory_blocks[j].size_Memory >= Process_blocks[i].size_Process) {
                int fragmentation = Memory_blocks[j].size_Memory - Process_blocks[i].size_Process;
                if (fragmentation < min) {
                    min = fragmentation;
                    bestFitIndex = j;
                }
            }
        }

        // Allocate memory if a suitable block is found
        if (bestFitIndex != -1) {
            Memory_blocks[bestFitIndex].status = 'A'; // Mark memory block as allocated
            Memory_blocks[bestFitIndex].processID = Process_blocks[i].id; // Assign process ID to memory block
            remainMemorySize = Memory_blocks[bestFitIndex].size_Memory - Process_blocks[i].size_Process;
            printf(" %-7d %-15d %d                              %c              %-20d\n",Process_blocks[i].id, Process_blocks[i].size_Process, bestFitIndex + 1,Memory_blocks[bestFitIndex].status, remainMemorySize);
        } else {
           printf(" %-7d %-15d No suitable block        %-10s        %-10d\n", Process_blocks[i].id, Process_blocks[i].size_Process, "Not allocated",remainMemorySize);
        }
    }
    printf("-------------------------------------------------------------------------------------\n");

    return 0;
}

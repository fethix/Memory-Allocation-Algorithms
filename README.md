# Memory Management Algorithms

This project implements two memory management algorithms, namely **First Fit** and **Best Fit**, in C.

## Algorithms Implemented

### 1. First Fit

The First Fit algorithm allocates memory by searching for the first available block of memory that is large enough to accommodate the requested size. It allocates the memory in the first suitable block it encounters. For more informations [click here](https://www.geeksforgeeks.org/first-fit-allocation-in-operating-systems/).

### 2. Best Fit

The Best Fit algorithm allocates memory by searching for the smallest available block of memory that is large enough to accommodate the requested size. It selects the block that minimizes internal fragmentation. For more infromations [click here](https://www.geeksforgeeks.org/best-fit-allocation-in-operating-system/).

## Getting Started

Follow these instructions to compile and run the programs:

### Prerequisites

- **GCC Compiler**: Make sure you have GCC installed to compile the C programs.

### Compilation

To compile the programs, use the following commands in your terminal:

```bash
gcc -o first_fit first_fit.c
gcc -o best_fit best_fit.c
```
## Usage

After compiling, run the programs as follows:

#### First Fit

```bash
./first_fit
```
#### Best Fit
```bash
./best_fit
```
# Author
- Harchaoui fethi

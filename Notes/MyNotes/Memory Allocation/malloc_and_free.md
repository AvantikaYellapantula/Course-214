***The ```malloc``` and ```free``` functions***

Programs allocate blocks from the heap by calling the ```malloc``` function

```C
#include<stdio.h>

void *malloc(size_t size);

//Returns: pointer to allocated block if OK.
//if on error, return NULL
```

Recall: malloc's return type is "void star"

The ```malloc``` function returns a pointer to a block of memory of at least ```size``` bytes that is suitably aligned for any kind of data object that might be contained in the block.

In practice, the alignment would depend on the system

- If the code is compiled to run in 32-bit mode (```gcc -m32```), malloc always returns a block whose adress is a multiple of 8
- If the code is compiled to run in 64-bit mode (the default), the address is always a multiple of 16

If ```malloc``` encounters a problem

- the program requests a block of memory larger than the available virtual memory

Then it returns NULL and sets ```errno```. 

Malloc does not initialize the memory it returns. If you want an initialized memory allocation, use ```calloc```. Calloc initializes the allocated memory to 0. Also note that applications that want to alter the size of a previously allocated block can use the ```realloc``` function.

The ```ptr``` argument must point to the beginning of an allocated block that was obtained from ```malloc```, ```calloc```, ```realloc```. If not, then the behavior of ```free``` is undefined.

[Look here:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/malloc_visualization.jpg)

Steps to Understand:

1. The program asks for a 4 word block. Malloc responds by carving out a 4 word block from the front of the gree block and returning a pointer to the 1st word of the block
2. Requests a 5 word block. Malloc responds by allocating a 6 word block, with malloc padding the block with an extra word in order to keep the free block aligned on a double-word boundary
3. The program requests a 6 word block and malloc responds by carving out a 6 word block
4. The program frees the 6 word block from Step 2. Note that after the call to free returns, the pointer p2 still points to the freed block. It is the responsibility of the application not to use p2 again until it is reinitialized by a new call to malloc
5. The program requests a 2 word block. In this case malloc allocates a portion of the block that was freed in the previous step and returns a pointer to this new block.

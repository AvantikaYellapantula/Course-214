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

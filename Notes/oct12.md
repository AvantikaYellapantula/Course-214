Notes for October 12, 2017

Malloc Strategy:

first fit:

  - 1st block free and at least as large as allocation
    - could be larger
    - would allow you to stop as soon as possible
    - traverse your list of memory as little as possible
    - might allocate too much, but wouldn't waste time traversing
  - TLDR; good time efficiency, bad space

best fit:

  - best block free as close as possible as size of allocation
    - might have to scan all of memory
    - what is this good for?
      - good space efficiency, bad time efficiency

worst fit:

  - pick the biggest possible block freeand allocate it no matter what
    
Buddy System:
  - Basic Idea:
    - Uses powers of 2
    - Everyone has a "buddy"
    - split successive chunks into halves
      - recursively until you get a 'best-fit' available based on:
        - minimal block size chosen
        - minimal power of 2 chosen
  - You have n bytes. In order to allocate the "right" amount of memory, you keep halving it until the block in question is smaller than the allocation.
    - Then you would allocate the next largest block.
    - You should really need nlogn calculations for best fit
    - BST traversal
    - [Buddy Memory Allocator](https://en.wikipedia.org/wiki/Buddy_memory_allocation)

[Fragmentation](https://en.wikipedia.org/wiki/Fragmentation_(computing)) - In computer storage, fragmentation is a phenomenon in which storage space is used inefficiently, reducing capacity or performance and often both. The exact consequences of fragmentation depend on the specific system of storage allocation in use and the particular form of fragmentation. In many cases, fragmentation leads to storage space being "wasted", and in that case the term also refers to the wasted space itself.

  - Internal fragmentation is the wasted space within each allocated block because of rounding up from the actual requested allocation to the allocation granularity. 
    - Fransisco's Defn - free or wasted space within an allocation until external
  - External fragmentation is the various free spaced holes that are generated in either your memory or disk space.
    - Fransisco's Defn - free or wasted space between allocation units

realloc(void * ptr, size_t size)
  - "takes memory that was there and adds more to it
  
  	1. malloc(size)
		
  	2. memcpy()
    	- know [strncpy](https://linux.die.net/man/3/strncpy), [memcpy](https://linux.die.net/man/3/memcpy), [memmove](https://linux.die.net/man/3/memmove)
	
	
  	3. free(ptr)
		
  - you can reduce as  well as add
    - if you have 40 bytes, and you need only 20, you can realloc that
    ```C
    ptr= (type*)realloc(ptr...) 
    ```
    - This is dangerous. So you do:
    ```C
    ptr*
    ```
    - You can prevent "stuff" with the following
    ```C
    newptr = NULL;
    newptr = (type*)realloc(ptr...)
    if (newptr != NULL){
      ...ptr=newptr;}
    ```
    
    ```C
    write(fd, buff, 10);
    ```
    
You're writing to a file descriptor of a certain num of bytes
      
Know [open](https://linux.die.net/man/3/open), [close](https://linux.die.net/man/3/close), [read](https://linux.die.net/man/3/read), [write](https://linux.die.net/man/3/write)

```C
char * buff = (char*)malloc(10);
...
int written = 0;
int amountToWrite = 10;
int offset = 0;

int fd = open("./somefile", flags);

while(amountToWrite > 0){
	written = write(fd, buff+offset, amountToWrite);
	if(written==-1){
		//PANIC
	}else{
	//blah
	//we hopefully got some non-zero value
	amountToWrite -= written;
	offset += written;
	}
}
```

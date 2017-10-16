***Explicit Free lists***

Implicit ```free``` list provides us with a relatively simple way to introduce some basic allocator concepts

Because block allocation time is linear in the total number of heap blocks, the implicit free list is not appropriate for a general purpose allocator

- It might be fine for a special purpose allocator where the number of heap blocks is known beforehand to be small

A better approach is to organize the free blocks into some form of explicit data structure.

Since by definition, the body of a free block is not needed by the program, the pointers that implement the data structured can be stored within the bodies of the free blocks.

- the heap can be organized as a doubly linked free list by including a ```pred``` and ```succ``` (predecessor/successor) pointer in each free block as shown [here](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/doubly_linked_free_lists.jpg).
	- This reduces the first fit allocation time from linear in the total number of blocks to linear in the number of *free* blocks
	- However, the time to free a block can either be linear/constant depending on the policy we choose for ordering the blocks in the free list
	
Options:

- LIFO 

	- With a LIFO ordering and a first fit placement policy, the allocator insepcts the most recently used blocks first
	- In this case, freeing a block can be performed in constant time
	- If boundary tags are used, then coalescing can also be performed in constant time
	
- Address Order

	- the address of each block in the list is less than the address of its successor.
	- In this case, freeing a block requires a linear-time search to locate the appropriate predecessor
	- The trade off is that address-ordered first fit enjoys better memory utilization than LIFO ordered first bit
		- approaching utilization of best fit
		
A disadvantage of explicit lists in general is that free blocks must be large neough to contain all of the necessary pointers, as well as header and possibly footer

This results in a larger minimum block size, which increases potential internal fragmentation


***Segregated Free Lists***

An allocator that uses a single linked list of free blocks requires time linear in the number of free blocks to allocate a block

A popular approach for reducing the allocation time, known generally as segregated storage is to maintain multiple free lists, where each list holds blocks that are about the same size

The general idea is to partition the set of all possible block sizes into equivalence classes called size classes.

There are many wasys to define the size classes: For e.g: Powers of 2

```C
{1}, {2}, {3,4}, {5-8}, {9-16},...,{1025-2048}, {2049-4096}, {4097-...}
```

- The allocator maintains an array of free lists, with one free list per size class, ordered by increasing size.
- When the allocator needs a block of size n, it searches the appropriate free list.
- If it cannot find a block that fits, it searches the next list and so on

There are 2 basic Approaches:

**Simple Segregated Storage**

The free list for each size class contains same-sized blocks, each the size of the largest element of the size class.

To allocate a block of sime given size:

- check the appropriate free list
- If the list is not empty
	- simply allocate the furst block in its entirety
	- Free blocks are never split to satisfy allocation requests
- If the list is empty
	- the allocator requests a fixed size chunk of additional memory from the operating system
	- divides the chunk into equal-sized blocks and links the blocks together to form the new free list

To free a block

	- the allocator simply inserts the block at the front of the appropriate list

Advantages to this scheme:

- Allocating/Freeing BOTH fast constant time operationg
- Combination of the same sized blocks in each chunk, no splitting, no coalescing means that there is very little per block memory overhead
- Since each chunk has only same-sized blocks, the size of an allocated block can be inferred from its address.
- Since there is no coalescing, allocated blocks do not need an allocated/free flag in the header
- Thus, allocated blocks require no headers, since no coalescing, they do not require any footers either

Disadvantage:

- Simple segregated storage is suceptible to internal and external fragmentation
	- Internal frag is possible because free blocks are never split
	- Worse, certain reference patterns can cause extreme external frag because free blcoks are never coalesced
	
**Segregated Fits**

The allocator maintains an array of free lists. Each free list is associated with a size class and is organized as some kind of explicit or implicit list

Each list contains potentially different sized blocks whose sizes are members of the size class

To Allocate a Block:

- determine the size class of the request
- do a first fit search of the appropriate free list for a block that fits.
- If found
	- split it and insert the fragment in the appropriate free list
- If not found
	- search the free list for the next larger size class
- repeat until we find a block that fits
- If none work
	- request additional heap memory from the operating system, allocate the block out of this new heap memory and place the remaineder in the appropriate free list
	
With this:

- Search times are reduced because searches are limited to particular parts of the heap instead of the entire heap
- Memory utilization can improve because of the interesting fact that a simple first fit search approximates a best fit search of the entire heap

**Buddy Systems**

Special Case of Segregated Fits where each size class is a power of 2.

Basic Idea:

- Given a heap of 2^m words, maintain a separate free list for each block size 2^k, where 0<=k<=m
- Requested block sizes are rounded up to the nearest power of 2
- Originally there is 1 free block of size 2^m words

To allocate a block of size 2^k:

- find the first abailable block of size 2^j, s.t k<=j<=m.
- If j==k,
	- we're done
- Else
	- recursively split the block in half until j==k
- After this, each remaining half (known as a buddy) is placed on the appropriate free list

To Free a Block

- continue coalescing with the free
- When we wncounter an allocated buddy, we stop the coalescing

**Note:** The addresses of a block and its buddy differ in exactly one bit position

Advantage:

- fast searching and coalescing

Disadvantage:

- The power of 2 requirement on the block size can cause significant internal fragmentation. For this reason, buddy system allocators are not appropriate for general-purpose workloads
- But, where the block sizes are known in advance to be powers of 2, the buddy system has an appeal
	

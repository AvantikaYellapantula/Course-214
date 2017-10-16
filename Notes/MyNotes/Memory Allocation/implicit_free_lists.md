***Implicit Free Lists***

Any practical allocator needs some data structure that allows it to distinguish block boundaries and to distinguish between allocated and free blocks.

Most allocators embed this information in the blocks themselves.

[See example here:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/simple_heap_block.jpg)

In this case, a block consists of one-word header, the payload, and possibly some additional padding.

The header encodes the block size as well as whether the block is allocated or free

Suppose we implement a double word contstraint:

- Block size is always a multiple of 8
- 3 low-order bits of the block  are always 0
- Store only 29 of the bits, freeing the last remaining 3 bits to encode other information
- Using the Least Significance of those bits to indicate whether the block is allocated or free

Suppose we have an allocated block with size 24 (0x18). Then the header would be:

```C
0x00000018 | 0x1 = 0x00000019
```

- The header is followed by the payload that the application requested when it called ```malloc```.
- The payload is followed by a chunk of unused padding that can be any size.
	- Why pad?
	- Might be part of the allocator's strategy for combating external fragmentation
	- Might be needed to satisfy the alignment requirement
	
[Using the above model, one can organize the heap as asequence of contiguous allocated/free blocks](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/implicit_free_heap_organization.jpg)

- This organization is called "implicit free list" because the free blocks are linked implicitly by the size fields in the headers.
- The allocator can indirectly traverse the entire set of free blocks by traversing all of the blocks in the heap.
- To do this, note that we would need some kind of specially marked end block
- For instance, in this example, a terminating header with the allocated bit set and a size of 0

Advantages:

- The advantage of an implicit free list is implicity

Disadvantage:

- The cost of any operation, such as placing allocated blocks, that requires a search of the free list will be linear in the total number of allocatedand free blocks in the heap:

It is crucial to realize that the system's alignment requirement and the allocator's choice of block format impose a minimum block size on the allocator.

No allocated or free block may be smaller than this minimum

- For example: If we assume a double-word alignment requirement, then the size of each block must be a multiple of two words, which is 8 bytes.
- Thus the block format induces a minimum block size of 2 owrds
	- One word for the header
	- Another to maintain the alignment requirement
- Even the application were to request a single byte, the allocator would create a 2 word block

***Implementation issues***

The simplest imaginable allocator would organize the heap as a large array of bytes and a pointer p that initially points to the 1st byte of the array.

To allocate ```size``` bytes, ```malloc``` would save the current value of ```p``` on the stack, increment it by ```size``` and return the old value of ```p``` to the caller.

```Free``` would simply return to the caller without doing anything

A practical allocator that strikes a better balance between throughput and utilization must consider the following issues:

- **Free block organization** - How do we keep track of free blocks?
- **Placement** - How do we choose an appropriate free block in which to place a newly allocated block
- **Splitting** - After we place a newly allocated block in some free block, what do we do with the remainder of the free block?
- **Coalescing** - What do we do with a block that has just been freed?

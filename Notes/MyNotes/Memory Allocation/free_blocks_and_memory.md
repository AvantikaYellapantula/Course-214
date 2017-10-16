***Split Free Blocks***

Once the allocator has located a free blok that fits, it must make another policy decision about how much of the free block to allocate.

One option: -> Use the entire free block

- Advantage: Simple and fast
- Disadvantage: introduces internal fragmentation

If the placement policy tends to produce food fits, then some additional internal fragmentation might be acceptable

***Getting Additional Heap Memory***

What happens if the allocator is unable to find a fit for the requested block?

- Option: create some larger free blocks by merging (coalescing) free blocks that are physically adjacent in memory
- This may not yield a sufficiently large block OR the free blocks are already maximally coalesced
	- The allocator asks the kernel for additional heap mem by calling the ```sbrk``` function.
	- The allocator transforms the additional memory into one large free block, inserts the block into the free list, and then places the requested block in this new free block
	
[Image to aid understanding:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/split_free_block.jpg)

***Coalescing Free Blocks***

When the allocator frees an allocated block, there might be other free blocks that are adjacent to the newly freed block. Such adjacent free blocks can cause a phenomenon known as *false fragmentation*

False Fragmentation - where there is a lot of available free memory chopped up into small, unusable, free blocks. [This image](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/false_fragmentation.jpg) shows the result of freeing the block that was allocated in the previous image.

The result of this is that now we have two adjacent free blocks with payloads of 3 words each. Ramifications of this include:

- subsequent request for a payload of 4 words would fail, even though the aggregate size of the two free blocks is large enough to satisfy the request

To combat this false fragmentation, any practical allocator must merge adjacent free blocks in a process known as coalescing

This raises an important decision to make about when to coalesce.

- The allocator can opt for immediate coalescing by merging any adjacent blocks each time a block is freed.
- Opt for deferred coalescing, by waiting to coalesce free blocks at some later time.
	- For instance, the allocator might defer coalescing until some allocation request fails, and then scan the entire heap, coalescing all free blocks
	
Immediate coalescing is straight forward and can be performed in constant time, but with some request patterns, it can introduce a form of thrashing where a block is repeatedly coalesced, then split soon thereafter.
	
- Note that in [this image](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/false_fragmentation.jpg) a repeated pattern of allocating and freeing a three-word block would introduce a lot of unneeded splitting and coalescing.
	
Assume immediate coalescing for this course

***Coalescing with Boundary Tags***

How does an allocator implement coalescing?

Refer to the block that we want to free as 'current block'

- Coalescing of next free block in memory is straightforward and efficient
- The header of the current block points to the header of the next block wwhich can be checked to determine if the next block is free.
- If it is, its size is added to the size of the current header and the blocks are coalesced in constant time

How to Coalesce the previous block?

- Given an implicit free ilst of blocks with headers, the only option would be to search the entire list, remembering the location of the previous block until we reached the current block
- With an implicit free list, this means that each call to ```free``` wouuld reuire time linear in the size of the heap
	- the search time would not be constant

Knuth developed boundary tags

- allows for constant time coalescing of the previous block
- Idea:
	- add a 'footer', which is the boundary tag, at the end of each block, where the footer is a replica of the header.
	- if each block includes such a footer, then the allocator can determine the starting location and status of the previous block by inspecting its footer
		- which is always one word away from the start of the current block
		
Consider the following cases that can exist when the allocator frees the current block:

1. Both blocks are allocated
2. Previous block is allocated and next is free
3. Previous block is free and the next is allocated
4. Both blocks are free

[This image](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Memory%20Allocation/boundary_tag_coalescing.jpg) shows how we would coalesce each of the four cases

- Case 1: Both adjacent blocks are allocated and thus no coalescing is possible
- Case 2: Current block is merged with the next block
	- The header of the current block and the footer of the current block are updated with the combined sizes of the two blocks (current and next)
- Case 3: The previous block is merged with the current block
	- The header of the previous block and the footer of the current block are updated with the combined sizes of the two blocks
- Case 4: All three blocks merge to form a single free block with the header of the previous block and the footer of the next block.
	- The header of the previous block and the footer of the current block are updated with the combined sizes of the three blocks
	
In each case, the coalescing is performed in constant time;

The idea of boundary tags is a simple one that generalizes to many different types of allocators and free list organizations.

- Disadvantage (Potentially): Requiring each block to contain a header and a footer may cause significant memory overhead if an application manipulates many small blocks
- Counter to the disadvantage - There is a clever optmization that eliminates the need for a footer in allocated blocks.
	- Recall the size field in the footer of the previous block is only needed if the previous block is free.
	- If we were to store  the allocated/free bit of the previous block in one of the excess low-order bits of the current block, then allocated blocks would not need footers and we could use the extra space for payload
	- *Note* free blocks *still need* footers

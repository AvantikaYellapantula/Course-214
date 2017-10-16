***Placing Allocated Blocks***

When an application requests a block of k bytes, the allocator searches the free list for a free block that is large enough to hold the requested block

The manner in which the allocator performs this search is determined by the placement policy:

- **first fit**
	- searches the free list from the beginning and chooses the first free block that fits
	- *advantage* -> tends to retain large free block with the smallest size that fits
	- *disadvantage* -> tends to leave "splinters" of small free blocks toward the beginning of the list, which will increase the search time for larger blocks
- **next fit**
	- starts each search where the previous search left off
	- Studies suggest that next fit suffers from worse memory utilization than first fit
- **best fit**
	- examines every free block and chooses the free block with the smallest size that fits
	- *advantage* -> Studies have found that best fit has better memory utilization than either first or next fit
	- *disadvantage* -> Using it with a simple free list organizations such as the implicit free list, is that is requires an exhaustive search of the heap

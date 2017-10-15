***Dynamic Memory Allocation***

A dynamic memory allocator maintains an area of a process's virtual memory known as the *heap*

Details vary from system to system, but WLOG, one can assume that the heap is an area of demand-zero memory that begins immediately after the uninitialized data area and grows upward, i.e., toward higher addresses

For each process, the kernel maintains a variable ```brk``` that points to the top of the heap. An allocator maintains the heap as a collection of various-sized *blocks*, where each block is a contiguous chunk of memory (virtual), either *allocated* or *free*.

An allocated has been explicitly reserved by the application for use and will be allocated until it is freed. A free block will remain free until it is explicitly allocated by the allocation.

There are two types of allocators:

- Explicit allocators - require the application to explicitly free any alloctated blocks.
	- The C standard lib provides ```malloc``` which allow programs to allocate a block by calling the ```malloc``` function and free a block by calling the ```free``` function.
- Implicit allocators - require the allocator to detect when an allocated block is no longer being used by the program and then free the block.
	- AKA garbage collector
	- The process of automatically freeing unused allocated blocks is known as garbage collection
	- e.g:Lisp, ML, Java rely on garbage collection to free allocated blocks
	

***Fragmentation***

The primary cause of poor heap utilization is called fragmentation, which occurs when otherwise unused memory is not availale to satisfy allocate requests.

Defn of Payload: Suppose we are given some sequence of n allocate and free requests:

R_0, R_1,...,R_k,...,R_(n-1)

If an application requests a block of p bytes, then the resulting allocated block has a *payload* of p bytes. After request R_k has completed, let the *aggregate payload*, denoted p_k, be the sum of the payloads of the currently allocated blocks

Types of fragmentation:

- internal fragmentation - occurs when an allocated block is larger than the payload.
- external fragmentation - occurs when there *is* enough aggregate free memory to satisfy an allocate request, but no **single** free block is large enough to handle the request.
	- If the request is for 8 words, then even though there are 8 free words remaining in the heap, its spread over 2 blocks, so this brings out external fragmentation (Basically request additional virtual memory from the kernel)
	- External gragmentation is more difficult to quantify because not only is it based on the pattern of the past requests, but also on future requests
		- Suppose that after k requests, all of the free blocks are exactly 4 words in size. If all the future allocate requests are looking for blocks that are smaller than or equal to 4 words, then there is no external frag
		- Else, if >=1 requests asl for blocks larger than 4 words, external frag!!
		

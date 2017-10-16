***Allocator Requirements and Goals***

Explicit allocators must operate within some rather stringent constraints

- Handling arbitrary request sequences - An app can make a random sequence of allocate and free requests, subject to the constraint that each free request must correspond to a currently allocatedblock obtained from a previous allocate request.
	- Thus, the allocator can't make assumptions about the order of the allocate requests
	- So, it cannot assumed that the allocate and free requests are matching or nested
- Making immediate responses to requests - The allocator must respond immediately to requests. So no reording or buffering of requests in order to improve performance
- Using only the heap - In order for the allocator to be acalable, any non-scalar data structures used by the allocator must be stored in the heap itself
- Aligning blocks - The allocator must align blocks in such a way that they can hold any type of data objects
- Not modifying allocated blocks - Allocators can only manipulate or change free blocks. In particular, they are not allowed to modify or move blocks once they are allocated. So, compaction of allocated blocks are not allowed

*Goal 1:* Maximizing Throughput - Given some sequence of n allocate and free requests, one would like to max an allocator's "throughput" (number of requests that it completes per unit time, for e.g: if an allocator completes 500 allocate requests and 500 free requests in 1 second, then its throughput is 1,000 operations per second)

- One can max throughput by minimizing the average time to satisfy allocate/free requests.

*Goal 2:* Maxing memory utilization

- Don't assume virtual memory is an unlimited resource
- The total amount of virtual memory allocated by all of the processes in a system is limited by the amount of swap space on disk.
- Know that virtual mem is a finite resource that should be used efficiently


Note that peak utilization over the first k+1 requests, denoted by U_k is given by (in latex form):

U_k = \frac{max_(i\leq k)P_i}{H_k}

U_k = [max_(i=<k) P_i]/[H_k]

where H_k denotes the current montonically nondecreasing size of the heap and P_k be the sum of the payloads of the currently allocated blocks.

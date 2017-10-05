Notes for October 5, 2017

Exam on Oct16 2017 9:40-11:00 PM

Review: Schedule of Topics (In Future)

Francisco does ask conceptual questions and questions about code, but not really that many questions about code, i.e: given, code, analyze code.
```C
int a = 2;
int * p = &a;

p = p + 1;
printf("%d\n", p);
```
What does this print out?

``` &a = 0x100201AF ```

Why wouldn't it print out: 

``` 0x100201B0 ```?
 - Because it would mean that p is being incremented by 1 byte when it is being incremented by the length of the type it points to. So it would increase by 4 bytes (since ints on this machine are 4 bytes long So ``` 0x100201B3 ```)
 
 There are different ways to format this question:
 
 Under what conditions is this true?
 
 Given this code, and *this* list of types, what type is printed out?
 
  ---------------------------------------------------------------------------------------------------
 ```C
 long c = 2;
 //int * p = &c; (gives warnings, but still compiles)
 int * p = (int*)&c;
 char * q = (char*)&c;
 ```
 
 ==>Why is this a union?
 
 -----------------------------------------------------------------------------------------------------
 creating malloc
 
 Process Birth:
 
 ```C
 fork()
 ```
 What does fork() do?
 
 parent/child
 
 When you say fork, your entire process is being duplicated
 
 When you call fork once, it returns twice (1. parent, 2. child)
 
 When you call exec and it works, it'll return nothing because it replaces itself with new code.
 
 If you're a parent process, you get a child identifier
 
 If you're a child process, you get a 0
 
 Most calls to fork look like:
 ```C
 int pid = for();
 if(pid==0){
 //you are the child process 
 exec("./newcode");
 }
 ```
 When you say exec, it loads the file into the binary file...????
 
 play around with fork() and exec
 
 multiple processes ==> multiple fork statements
 
 put them in an array
 
 malloc->free as is open->close
 
 So fork()->wait(pid t pid, int *stat loc, int options)
 
 The stat is optional. If you want to know the status, then put it in
 
 wait() ...wait for child process to be done running
 
  - When you wait, you 'block'
  
Zombie process - process that is done running, no executable code, whose parent has not yet  waited on it

Orphan process - a process whose parent no longer is in the system
 
Zombie orphan - process that is done running, no executable code who has no parent to wait on it
 
  - Every process knows its pid and it's parent's pid (ppid)
  - Reassign a parent to be the initial process
  - Init -> pid=0
    - pid=0 might be the scheduler
  - Could pid 0 ever be created by fork?
    - unforked
    
Exceptional Computation
  - Exception - instructions that cannot be run
  - Interrupts - stops computation for something important (resizing a window?)
    - hardware events/software events
  - both exceptions and interrupts are involuntary losses of control
  - Trap - voluntary loss of control
    - runtime
    - and have the OS run some of its code on your behalf
      - e.g: "system call"
 
Signals - exception abstraction:
  - software interrupts that may be caused by either software or hardware events
    - resizing your terminal window causes a signal
    - mouse moving (with mouse driver only) gives an interrupt -> creates a signal
  - types of signals
    - look at man pages
     
 ```C
 signal(SIGSEV, segment_fault_handler);
 r2 = *( (int 0) )
 
 

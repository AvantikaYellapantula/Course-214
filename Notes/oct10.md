Notes for October 10, 2017

Exceptional Computation

interrupts  \

traps ------- > signals

exceptions  /

F-D-E loop

**Fetch** - load instruction at PC (Program Counter)

**Decode** - discover operation type -> fetch operands -> latch into ALU 

**Execute** - do the thing with the stuff (do the program) (and then ++PC)

[Anatomy of a Program in Memory:] (http://static.duartes.org/img/blogPosts/linuxFlexibleAddressSpaceLayout.png)

All the binary data is loaded in the text segment

Static variables/Global Variables in the Data segment

Uninitialized...

Stack pointer (SP) by definition points to the top of the stack

    
 Stack
|-------------|
|  printf     |
|  heap       |
|  main       |

SP --> heap (for e.g)

Compiling (Stages):

preprocessor
  - goes through and executes your code
  - goes through .h files and creates the environment for your code
  - defines, macros,...performed on code (text replacement)
  - typedefs, enums, struct defs, prototypes,...loaded into environment
  
compiler
  - typechecking and scanning (enforce grammar rules)
  - make code ready to convert to assembly (pick locations for vars)
assembler

linker

 //check out CS211 - bk
 ```

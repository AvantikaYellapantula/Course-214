Notes for Lecture September 12

types:
structs - what is a struct?
- one new named type that consists of multiple other types
- size? - at least the size of the sum of its components
  - use sizeof to determine size of var type
  - char = 1 byte always
  - size of short <= int <= long
- know difference between unions and structs

Command: 
```C
sept12.out a.out | wc
```
instead of doing struct jeff dave
we want to do:
```C
bossJeff dave = {1, 'a', 45};
typedef:"typedef struct jeff bossJeff;"
```
Can also do:

```C
typedef struct jeff{
	int littleJeff;
	char smallJeff;
	long bigJeff;
} bossJeff;
```
defining a header file
```C
#ifndef STUFF_H --> ifndef means if not defined, its true
#define STUFF_H

#define THING 3

#endif
```
remember that for headers that are:

 - user defined: - "xx.h"
 - system defined (std c lib) - <xx.h>
 - When you create a header file, it's as if you're doing Cntrl+H in notepad and replacing every instance of the var you defined with the value that follows. So becareful to use defined var names like int  or char or float or whatever


talking about ```#define SQUARE(x) x*x```

what happens if you do SQUARE(3+3)
 - it doesn't do: (3+3)*(3+3)
 - it does: 3+3*3+3 = 3+9+3 = 15
 - So the value you would get is 15 instead of 36


Sometimes we want to represent something textual
CUP
PINT
QUART
GALLON

If I want these to be the value of my types:
```
enum volumes = {CUP, PINT, QUART, GALLON};
enum volumes jug = CUP;
```
building boolean
```
enum BOOLEAN = {TRUE=1, FALSE=0};
```


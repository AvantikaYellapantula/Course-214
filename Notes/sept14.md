Notes for Class September 14

enums don't take an equal sign
```C
enum_boolean {FALSE, TRUE}
typedef enum_boolean boolean;
```
By default, the compiler assigns values to these names and values:
so ``` FALSE = 0, TRUE = 1 ```

so we could do:``` enum_boolean {FALSE=1, TRUE=0} ```

(remember the original values are F=1 and T=0)
capital letters  by convention
the values also ***MUST*** be integers

remember different ways to do typedef

print value of enum see:[setp14.c](https://github.com/AvantikaYellapantula/Course-214/blob/master/Code/sept14.c)

If we had the following:

``` enum _boolean {FALSE=12, TRUE} ```

	-> The value of TRUE is 13
  
``` enum _boolean {FALSE, TRUE=12} ```

	-> The value of FALSE is 0
  
``` enum _boolean {FALSE=13, TRUE=12, FARCE} ```

	-> The value of FARCE is 13

Pointers (type star)
These are the memory addresses
```C
0 10010101
1 00100101
2
3
4
5
```
if the following happenned, we'd have to copy the whole thing into
the local function space

```C
function(struct memoryHog reallyBig){}
```

So instead we pass a reference through it
``` function(struct memoryHog * reallyBig){} ```

	-> it holds the memory location:
	   it's something that points to a struct memory hog
type: (This is what a type contains)
 length
 method of parsing bits

int ~ 4 bytes
char == 1 bytes

int a = 12;
char b = 'c';

```C
0 1011001
1 1010010
2 101001
3 101001
4 10101
```
Pointers referencing
See [sept14_pointer.c](https://github.com/AvantikaYellapantula/Course-214/blob/master/Code/sept14_pointers.c)

``` & ``` means give the address
NOTE: ``` int * c = b; ``` is wrong.
The compiler will point to memory location 12;
What is mem loc 12?
So you use ``` & ```

*Pointer size is 8 on this system
*Note: Char will always be 1 byte. Every other type is up for grabs

All pointers are the same size

* note that even though we said ``` float * d; ```, we printed out with %d, because
it doesn't matter how we view the number as long as we can view it. So we can
use ``` %d ``` if we want to view the memory location.

Dereferencing a pointer => making it "actual"
so if we ``` printf *c ```, then we're printing the actual value of c, which is 12

What is legal with spaces and pointers?
```C
float *d;
float* d;
float * d; 
```
//Fransisco uses this because he likes to put spaces on both sides
**NOT** do: float*d;

You can point to anything you got
-> use ``` &var ```
-> use ``` *var ```

set a pointer to a function!

why can we use ``` char * argv[] vs char ** argv ```
-> this should only work if arrays and pointers are interchangeable

incrementing a pointer
```C
printf("?: %c\n", *(test+1) );
```

This will incrememnt by the size of the type it points to
Since char is 1 byte, it went from h to e

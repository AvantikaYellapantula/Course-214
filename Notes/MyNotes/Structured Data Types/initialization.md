***Initialization***

C allows the following to be given initial values in their definitions:

- ordinary variables
- structures
- unions
- arrays

There are two sorts of initialization:

- compile time
- run time

Which one you get depends on the storage duration of the thing being initialized:

- static duration: Objects with static duration are declared either outside functions or inside them with the keyword ```extern``` or ```static``` as part of the declaration. These can *only* be initialized at compile time
- automatic duration - Any other object has automatic duration and can only be initialized at run time.
- Note: The two categories are mutually exclusive

**Constant Expressions**

A constant expression is evaluated by the compiler, not at run-time. It may be used anywhere that a constant may be used. Unless it is part of the operand ```sizeof```, it may not contain any assignment/increment/decrement operations/function calls/comma operators since ```sizeof``` needs to only evaluate the type of an expression, not its value

If real numbers are evaluated at compile-time, then the standard insists that they are evaluated with at least as much precision and range as will be used at run-time


One could build a string literal in this way:

```C
char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
```

But its so often necccessary to do that, so we have instead:

```C
char str[] = "hello";
```

Make sure to keep space for the null element:

```C
char str[6] = "hello";
```

**NOT:**

```C
char str[5] = "hello";
```

Example for initializing with structs:

```C
#include<stdio.h>
#include<stdlib.h>

struct s{
	int a;
	char b;
	char *cp;
}ex_s{
	1, 'a', "hello"
	}
	
main(){
	
	struct s first = ex_s;
	struct s second = {
		2, 'b', "byebye"
	};
	
	exit(EXIT_SUCCESS);
}
```

Note that only the first member of a union can be initialized.

- If a structure/union contains unnamed members whether unnamed bitfields/padding for alignment, they are *ignored* in the initialization process
- they don't have to be counted when you provide the initializers for the real members of the structure



General Notes:

- Unless they have an explicit initializer, all objects with static duration are given implicit initializers 
	- The effect is as if the constant ```0``` had been assigned to their components
- This is widely used as an assumption made by most C programs that external objects and internal static objects start with the value 0
- Initialization of objects with automatic duration is only guarunteed if their compound statement is entered 'at the top'
	- Jumping into the middle of one may result inthe initialization not happening
	- Undesirable, avoid it
	
```C
int x;			//external linkage
main(){
	extern int x = 5;		//forbidden!!
}
```

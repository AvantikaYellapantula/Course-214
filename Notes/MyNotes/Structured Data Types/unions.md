***Unions***

Unions are very similar to structures except for some key differences:

|Structures|Unions|
|-----------------------------------------------------|---------------------------------------------------|
|the members are allocated separate chunks of storage |every member is allocated the same piece of storage

Why use a union?
- If you want a structure to contain different values of different types at different times (like a struct) but to conserve space amap.
- With a union, it's up to the user to keep track of whatever type you put into it and make sure that you retrieve the right type at the right time:

```C
#include<stdio.h>
#include<stdlib.h>

main(){
	
	union{
		float u_f;
		int u_i;
	}var;
	
	var.u_f = 23.5;
	printf("value is %f\n", var.u_f);
	var.u_i = 5;
	printf("value is %d\n", var.u_i);
	exit(EXIT_SUCCESS);
}
```
**Q:** What's the size of the union?

**A:** It's the size of your largest data type



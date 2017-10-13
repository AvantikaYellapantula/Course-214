***Pointer Arithmetic***

*Relatively Simple, more complex pointer arithmetic dealt with later

One can add an integral value to a pointer. One can also compare two pointers with each other, i.e., subtract them

Conditions:

	- They must point to the same array
		- else the result be undefined
		
Basic Idea: The difference of the pointers is the number of array elements separating them. The type of this difference is implementation defined and will be either:
	- short
	- int
	- long

**Note:** In an expression, the name of the array will convert to a pointer which accesses the first element of the array

```C
int fp1*, fp2*;
float fa[AARAY];
fp1 = fp2 = fa;
//addresses first element

int diff=0;

while(fp2!=&fa[AARAY]){
	diff = (int)(fp2-fp1);	//using a cast
	printf("%d\n", diff);
	fp2++;
}

```



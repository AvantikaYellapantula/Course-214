Arrays and Pointers

***Arrays:****

They are declared as

```C
double array[100];
```

where one would visualize it as [such](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/array_visualization.jpg):

*Note:* Arrays don't permit use of varying subscripts

```C
void f(int x){
	char a[x];
}
```

**Multidimensional Arrays**

They are declared as

```C
int ar[3][2];
```

This array is a 3 element array of which each element is an array of 2 elements as [such](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/multi_dim_array_visualization.jpg):

Incrementing a 2-D array would involve accessing the last member of the array:

```C
b[4][3][1]+=2;
```

***Pointers:***

```C
int ar[5], *ip;
ip = &ar[3]
```
[Visualization:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/pointer_visualization.jpg)

*Note:* ```&``` is a unary operator which is the "address of" operator

A pointer is only useful if there's spme way of getting at the thing it points to:
	- So you would use ```*```
	- If ```p``` is type pointer, then ```*p``` refers to the thing being pointed to:
	- Suppose you wanted to access int x via pointer p:
```C
int x, *p;
p = &x;	//initialized pointer
*p = 0;	//set x to 0
(*p)++;	//increments what p points to (x)
```
**Summarizing Notes:**

	- Arrays always index from zero—end of story.
	- There are no multidimensional arrays; you use arrays of arrays instead.
	- Pointers point to things; pointers to different types are themselves different types.
		- They have nothing in common with each other or any other types in C; there are no automatic conversions between pointers and other types.
	- Pointers can be used to simulate ‘call by reference’ to functions, but it takes a little work to do it.
	- Incrementing or adding something to a pointer can be used to step along arrays.
	- To facilitate array access by incrementing pointers, the Standard guarantees that in an n element array, although element n does not exist, use of its address is not an error—the valid range of addresses for an array declared as int ar[N] is &ar[0] through to &ar[N]. 
		- You must not try to access this last pseudo-element.

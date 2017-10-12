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


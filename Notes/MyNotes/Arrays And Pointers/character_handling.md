***Character Handling***

C is widely used for char and string handling even though C doesn't have built-in string handling functions

Character handling in C is done by declaring arrays or allocating them dynamically and moving characters in and out of them 'by hand'

**Pointers and increment operators**

We revisit expressions like ```(*p)++;```

```C
#define ARLEN 10

int ar[ARLEN], *ip;

ip = ar;
while(ip < &ar[ARLEN]){
	*(ip++) = 0;
}
```

The pointer ```*ip``` is set to the start of the array. While it remains inside the array, the place that it points to has 0 written into it, then the increment takes effect and the pointer is stepped one element along the array.

|Increment	|Meaning						   			  			 |
|-------------|------------------------------------------------------|
|```++(*p)``` | pre-increment thing pointed to  		  			 |
|```(*p)++``` | post-increment thing pointed to			   			 |
|```*(p++)``` |	access via pointer, post-increment pointer			 |
|```*(++p)``` | access via pointer which has already been incremented|

Equivalence:

|With Parenthesis |Without Parenthesis (si c'est possible)|
|-----------------|-------------------|
|```++(*p)```|```++*p```|
|```(*p)++```|```(*p)++```|
|```*(p++)```|```*p++```|
|```*(++p)```|```*++p```|

**Untyped Pointers**

In certain cases it's essential to be able to convert pointers from one type to another. This is done by casting, as shown:

```C
(type *) expression
```

The expression here is converted into 'pointer to type' regardless of the expression's previous type.

*Using Malloc*

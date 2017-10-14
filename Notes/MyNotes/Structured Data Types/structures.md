***Structures***

Arrays allow for a named collection of identical objects. This is suitable for a number of tasks, but isn't the most *flexible* option.

**Extendable Example:** Suppose that you have to do something with a type-setting package. In this system, the individual characters have not only their character values, but also some additional attributes, such as font and point size.

So how do we represent them in a single object? Assume that you can still store the character in a char.

1. Store the font into a short -> (1, regular; 2, italics; 3, bold)
2. Point size will also work with a short

```C
struct wp_char{
	char wp_cval;
	short wp_font;
	short wp_psize;
};
```

The tag can be used as follows:

```C
struct wp_char x, y;
```

That defines two variables called x and y just as it would have done if the definition had been:

```C
int x, y;
```

Note that variables can be defined immediately following a structure declaration.

```C
struct wp_char{
	char wp_cval;
	short wp_font;
	short wp_psize;
}v1;

struct wp_char v2;
```

Now, note that we have indeed 2 vars, ```v1``` and ```v2```. Now how do we use these structured objects (variables). Note that these structured objects each contain 3 separate individual members of the structures and the 'dot' operator is used:

```C
v1.wp_cval = 'x';
v1.wp_font = 1;
v1.wp_psize = 10;

v2 = v1;
```

In the above example, the individual members of v1 are initialized to suitable values, then the whole of ```v1``` is copied into ```v2``` in an assignment.

The only operation permitted on whole structures is assignment

- they can be assigned to each other
- they can be passed as arguments to functions and returned by functions

But this is not efficient practice. It is smarter to manipulate pointers to structures instead

In fact, look at this [example](http://publications.gbdirect.co.uk/c_book/chapter6/structures.html) from the "C-Book": 


**What would a structure look like in terms of storage layout?**

wp_char is allocated as [follows:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Structured%20Data%20Types/struct_storage_visualization.jpg)

The Standard makes some guaruntees about the layout of structures and unions:

- Members of a structure are allocated within the structure in the order of their appearance in the declaration and have ascending addresses.
- There must not be any padding in front of the first member
- The address of a structure is the same as the address of its first member, provided that the appropriate cast is used (similar to arrays)
	- Given the previous declaration of ```struct wp_char```, if item is of type ```struct wp_char``` then ```(char *)item == &item.wp_cval```
- Bit fields don't actually have addresses, but are conceptually packed into *units* which obey all rules above

**Using Structs for Linked Lists and Other structures**

**Linked Lists**

[Visualization of Linked List](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Structured%20Data%20Types/ll_visualization.jpg)

```C
struct list_ele{
	int data;
	struct list_ele *ele_p; //note the pointer to itself
}
```

*Incomplete Declaractions*

```C
struct list_ele;
```

A declaration like that declares an incomplete type. This will allow the declaration of pointers before the full declaration is seen.
Incomplete types may only be used where the size of the structure isn't needed yet. A full declaration must be given by the time that the size is used. *Note:* The later full declaration mustn't be an inner block because then it becomes a new declaration of different structure.

```C
struct x;	//incomplete type
struct x, *p, func(void);	//valid uses of the tag

void f1(void){
	struct x{int i;};	//redeclaration!!!
}

struct x{		//full declaration
	float f;
}s_x;

void f2(void){
	p = &s_x;
	*p = func();
	s_x = func();
}

struct x
func(void){
	struct x tmp;
	tmp.f = 0;
	return (tmp);
}
````

***DANGER***
Suppose you have the following:

```C
struct abc{struct xyz *p;};
	//incomplete type 'struct xyz' now declared
struct xyz{struct abc *p;}
	//incomplete type now declared
```

What's wrong with this example. Look at it this way:

```C
struct xyz{float x;}var1;

main(){
	struct abc{struct xyz *p;}var2;
	//struct xyz redeclared!!!!
	
	struct xyz{struct abc *p;}var3;

}
```

Note that var2.p can hold the address of var1, but ***not*** the address of var3, which is of a different type. Now let's fix this:

```C
struct xyz{float x;}var1;

main(){
	struct xyz;	//new incomplete type 'struct xyz'
	struct abc{struct xyz *p;} var2;
	struct xyz{struct abc *p;} var3;
}
```

Linked List general idea:

```C
#include<stdio.h>
#include<stdlib.h>

struct list_ele{
	int data;
	struct list_ele *ptr;
}ar[3];

main(){
	struct list_ele *lp;
	
	ar[0].data = 5;
	ar[0].ptr = &ar[1];
	ar[1].data = 99;
	ar[1].ptr = &ar[2];
	ar[2].data = -7;
	ar[2].ptr = 0;	//end of list_ele
	
	//follow ptrs
	lp = ar;
	while(lp){
		printf("contents %d\n", lp->ptr);
		lp = lp->ptr;
	}
	exit(EXIT_SUCCESS);
}

```

Algorithm to sort the linked list:

- Repeatedly scan list
- If two items are out of order, link them in the other way around
- Stop if a full pass is made and no exchanges are required

```C
struct list_ele *
sortfun(struct list_ele *list)
{
	int exchange;
	struct list_ele *nextp, *thisp, dummy;
	
	dummy.ptr = list;
	do{
		exchange = 0;
		thisp = &dummy;
		while((nextp = thisp->ptr) && nextp->ptr){
			if(nextp->data < nextp->ptr->data){
				//exchange
				exchange = 1;
				thisp->pointer = nextp->ptr;
				nextp->ptr = thisp->ptr->ptr;
				thisp->ptr->ptr = nextp;
			}
			thisp = thisp->ptr;
		}
	}while(exchange);
	
	return (dummy.ptr);
}
```

**Trees**

**Q:** What is a tree?
**A:** A linked list with branches; a common type is the *binary* tree which has nodes like this:

```C
struct tree_node{
	int data;
	struct tree_node *left_p, *right_p;
	};
```

Note and recall that trees in CS have their roots at the top and the branches spread out [downwards:](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Structured%20Data%20Types/tree_visualization.jpg)

The algorithm for the tree:

Start at the root of the tree:
- if the tree is empty (no nodes)
	- then return 'failure'
- else if the data in the current node is equal
	- to the value being searched for
	- then return success
- else if the data in the current node is greater than the value being searched for
- else search the tree indicated by the right pointer

```C
#include<stdio.h>
#include<stdlib.h>

struct tree_node{
	int data;
	struct tree_node *left_p, *right_p;
}tree[7]
/*
Tree search algorithm:
	Searches for value 'v' in tree
	returns ptr to first node containing the val, else 0
*/

struct tree_node *
t_search(struct tree_node *root, int v){
	
	while(root){
		if(root->data == v)	return(root);
		if(root->data > v) root = root->left_p;
		else root = root->right_p;
	}
	/*val not found, no tree left*/
	return (0);
}

main(){
	struct tree_node *tp, root_p;
	int i;
	for(i=0;i<7;i++){
		int j;
		j = i+1;
		
		tree[i].data = j;
		if(j == 2 || j == 7){
			tree[i].left_p = &tree[i-1];
			tree[i].right_p = &tree[i+1];
		}
	}
	
	/*root*/
	root_p = &tree[3];
	root_p->left_p = &tree[1];
	root_p->>right_p = &tree[5];
	
	/*try the search*/
	tp = t_search(root_p, 9);
	
	if(tp)
		printf("found at position %d\n", tp-tree);
	else
		printf("value not found\n");
	exit(EXIT_SUCCESS);
	}
```

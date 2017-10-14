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

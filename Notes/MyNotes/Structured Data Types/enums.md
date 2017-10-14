***ENUMS***

[See](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/sept14.md) for class notes

Enums aren't properly enumerated types, but they serve to reduce the number of ```#define``` statements in your program.

```C
enum e_tag{
	a, b, c, d=20, e, f, g=20, h
}var;
```

Note that ```e_tag``` is the tag and ```var``` is the defn of a var

The names declared inside the enumeration are constants with ```int``` type. They have the following values:

```C
a==0
b==1
c==2
d==20
e==21
f==22
g==20
h==21
```

One can clearly see that in the absence of anything to the contrary, the values assigned start at 0 and increase. A specific value can be given if you want, when the increase will continue one at a time afterwards.

It is possible for more than one name to have the same value

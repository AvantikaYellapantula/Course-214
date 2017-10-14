***How the Preprocessor Works**

One can think of the preprocessor as a separate program which transforms the C code containing preprocessor directives into source code with the directives removed

[Link To Visualization](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/MyNotes/Preprocessor/processor_visualization.jpg)

*Note:* The preprocessor is not working to the same rules as the rest of C. It works on a line-by-line basis
	- The end of a line means something special to it
	- The rest of C thinks that the end-of-line is not that much different from a space/tab character
		- Think ```\t``` or ```\n```
Preprocessor directives like ```#define``` take effect as soon as they are seen and remain in effect until the end of the file that contains them. The block structure of the C-program itself is irrelevant.
		
**Directives**

Directives are always introduced by a line that starts with a ```#``` character, optionally preceded by white space characters

*List of Directives:*

|Directive|		Meaning  									|
|---------|---------------------------------------------|
|#include | include a source file						|
|#define  | define a macro								|
|#undef   | undefine a macro							|
|#if      | conditional compilation						|
|#ifdef   | conditional compilation						|
|#ifndef  | conditional compilation						|
|#elif    | conditional compilation						|
|#else    | conditional compilation						|
|#endif   | conditional compilation						|
|#line    | control error reporting						|
|#error   | force an error message						|
|#pragma  | used for implementation-dependent control	|
|#		  | null directive; no effect					|
	
***Defining Macros**
There are 2 ways of defining macros

One looks like a function 
	
```C
#define FMAC(a,b) a here, then b
```
One does not look like a function
	
```C
#define FNMAC some text here
```
	
Both definitions define a macro and some replacement text, which will be used to replace later occurrences of the macro name in the rest of the program. After those definitions, they can be used as follows, with the effect of the macro replacement shown in comments:

```C
FNMAC
	/*some text here*/

FMAC(first text, second text)
	/*first text here, then some more*/
```

Remember for the non-func macro, it's name is simply replaced by its replacement text. So the func macro is also replaced by its replacement text:

- Wherever the replacement text contains an identifier which is the name of one of the macro's formal parameters, the actual text given is the arg is used in place of the identifier in the replacement text.
- The scope of the names of the formal parameters is limited to the body of the ```#define``` derivative
- [Notes from Class about Header Files and #define](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/sept12.md)


*Other Notes:*

**Q:** How do you define a non-func macro whose replacement text happens to start with the opening parenthesis character '('?

**Ans:** If the defn of the macro has space in front of the '(', then it isn't the definition of a function macro, but a simple replacement macro instead.
	
**Note:** *When you use function-like macros, there's no equivalent restriction*

The Standard allows either type of macro to be redefined at any time, using another ```#define``` provided that there isn't any attempt 
to change the type of macro and that the tokens making up the original defn and the new defn are identical in number

**When a function macro is being processed **

1. All of its arguments are identified
2. Except in cases listed in (3) below, if any of the tokens in an argument are themselves cadidates for macro replacement, the replacement is done until no further replacement is possible.
	a. If this introduces commas into the argument list, there is no danger of the macro suddenly seeming to have a different number of arguments
	b. The arguments are *only* determined in the step above (1)
3. In the macro replacement text, identifiers naming one of the macro formal args are replaced by the (now expanded) token sequence supplied as the actual arg.
	a. The replacement is suppressed only if the identifier is preceded by one of ```#```, ```##```, or followed by ```##```

***#undef**

The name of any ```#defined``` identifier can be forcibly forgotten by saying

```C
#undef	NAME
```
*Note: It isn't an error to undef a name which hasn't yet been defined*

***#include***

Refer to [Notes from Class about Header Files and #include](https://github.com/AvantikaYellapantula/Course-214/blob/master/Notes/sept12.md)

***Predefined Names***

```C
_LINE_
```

The current soruce file line number
	- A decimal integer constant

```C
_FILE_
```

The 'name' of the current source code file, a string literal

```C
_DATE_
```

The current date, a string literal, where the form is Apr 21 1990
	- The month name is as defined in the lib func asctime and the first digit of the date is a space if the date is less than 10
	
```C
_TIME_
```

The time of the translation: again a string literal in the form produced by asctime, which has the form ```hh:mm:ss```

**How to use the predefined names**

```C
#define TEST(x)	if(!(x))\
	printf("test failed, line %d file %s\n", \_LINE_, _FILE_)
	
	/**/
	TEST(a != 23);
	/**/
```

In the above program, if the arg to TEST gives a false result, the message is printed, including the filename and line number in the message

*Note:* None of the predefined names may be used with ```#define``` or ```#undef```


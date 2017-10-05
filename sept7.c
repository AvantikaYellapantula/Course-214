#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//always include this

int main(int argc, char * argv[]){
/*
 - star issue with having something between char and argv with space or not space
 - argc=argument count
 - nothing would happen if you changed argc to argstuff
 - "string" - null-terminated array of chars
 - boolean type is N/A
	 - you could make your own

 - while(1){is always true}
*/

printf("hello world!\n");
/*
int someTruth=5;
while(someTruth){
}
This code had to be commented because it would run forever
*/
/*struct - group of vars given one name

stuct<name>{
<type0><var0>
...
<type0><var0>
}*/

/*
struct point{
int x;
int y;
};

struct point Alocation = {2, 3};
/*you need not paramaterize y technically. What would happen is that c would just automatically parametrize x. Let's parametrize y singularly*/

/*struct point AutreLocation = null;
AutreLocation.y=12;

/*You can create a struct that contains other structs
*/
/*
struct rectangle{
	struct point upperLeftCorner;
	struct point lowerRightCorner;
};

struct rectangle someRectangle = {{2,3}, {1,5} };

union somestuff(){
	float thing0;
	int stuff0;
	char metoo;
};

//Union uses the same chunk of memory for all the types within the structure

/*struct's memory is at least the size of the sum of its types
union's memory is at least the size of it's largest data type*/


/*typedef <new type name> <new type defn/type>*/
/*
typedef jeff
struct point{
int x;
int y;
};
*/
int mumble;
printf("the size of this integer is: %d\n", sizeof(mumble));

return 0;}

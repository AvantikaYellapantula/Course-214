#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[]){

	int b = 12;
	int * c = &b;
	float * d;
//& means give the address
	printf("b: %d\n&b %d\nc %d\n", b, &b, c);
	printf("size of int ptr! %d\n", sizeof(c));
	printf("size of float ptr! %d\n", sizeof(d));

	printf("b val: %d\n", *(&b));
	printf("c: %d\nc val: %d\n", c, *c);

	char message[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char messageALSO[] = {'H', 'E', 'L', 'O', '\0'};
	
	char * test = message;
	
	printf("test: %d\n", test);
	printf("mesg: %d\n", message);
	printf("??: %c\n", *message);

	printf("?: %c\n", *(test+1) );

	int i;
	for(i=0; i<=4; ++i){
		printf("i: %c, *i: %c\n", message[i], *(test+i) );
	}


return 0;}

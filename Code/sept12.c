#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include"sept12.h"

int main(int argc, char * argv[]){

struct jeff
{
	int littleJeff;
	char smallJeff;
	long bigJeff;
};

//instance of struct

typedef struct jeff bossJeff;
bossJeff dave = {1, 'a', 45};

typedef int volume;

volume cylinder = THING;
	printf(": %d\n", cylinder);


if(3 NOT0){

printf("not 0!\n");

}


int checking = SQUARE(4);
printf("checking: %d\n", checking);

int param = 51;
printf("Check again: %d\n", SQUARE(param));

int sum = SQUARE(3+3);
printf("Check once more: %d\n", sum);

float stuff = DIVIDE(2, 3);
printf("float checker: %d\n", stuff);

printf("float second check: %f\n", stuff);




return 0;}

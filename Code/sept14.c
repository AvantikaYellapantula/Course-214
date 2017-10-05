#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[]){

enum _boolean {FALSE,TRUE};
typedef enum _boolean boolean;

boolean teststuff = FALSE;

if(teststuff){
	printf("w00t!\n");

}else{
	printf("Aww!\n");
}

printf("FALSE\t TRUE\n %d\t %d\n", FALSE, TRUE);

return 0;}

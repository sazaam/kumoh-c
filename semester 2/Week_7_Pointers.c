
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project covers While Declarations

@mission:		A Simple Recursive A and B Addition Calculation Example

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Scheduler Minproject Example
Writing/Reading Arrays of structs

*/


int Program(void) {
	Exercises();
	return 0;
}

void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
	// Here value is rightfully changed
	printf("\t inside swap (x : %d , y : %d)\n", x, y);

}

void swap2(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	// Here value is rightfully changed
	printf("\t inside swap 2 (x : %d , y : %d)\n", *x, *y);

}


int Exercises() {


	int a;
	double b;
	unsigned long c;
	long d;
	float e;
	char f;

	printf("int a:  %u\n", &a);
	printf("double b:  %u\n", &b);
	printf("unsigned long c:  %u\n", &c);
	printf("long d:  %u\n", &d);
	printf("float e:  %u\n", &e);
	printf("char f:  %u\n", &f);

	int* pa = &a;
	// This will assign pointer to a variable, changing '&a' will change also 'a';
	*pa = 10;
	
	// writing pa = 10 ; // will set pa to another address and program will not be able to find value, -> will not respond 
	
	// Case of SCANF : But when pa has already an address set as in *pa = ... then we shall use scanf on the actual 'pa' value;
	printf("Please Enter value to memorise: ");
	scanf("%d", pa);

	printf("\t -> int a value of pointer : %d\n", *pa);
	printf("\t -> int a value of variable : %d\n", a);


	// swap example

	puts("\n");

	int aa = 10, bb = 20;

	swap(aa, bb);
	// But here value is not going to change
	puts("swap->");
	printf("\taa : %d , bb : %d \n", aa, bb);


	swap2(&aa, &bb);
	puts("swap 2 ->");
	printf("\taa : %d , bb : %d \n", aa, bb);









	return 0;
}


int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}

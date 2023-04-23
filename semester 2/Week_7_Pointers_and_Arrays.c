
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

void swap2(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	// Here value is rightfully changed
	printf("\t inside swap 2 (x : %d , y : %d)\n", *x, *y);

}

int getRes(int *x, int *y) {
	
	int res = *x * *y;

	if (!res) return 0;

	puts("Start of Function");
	printf("Multiplying %d by %d gets %d.\n", *x, *y, res);
	puts("End of Function");
	
	return res;
}

void printArr(int* arr, char** names, int l) {
	for (int i = 0; i < l; i++) {
		printf("The month of %s contains %d days\n", names[i], arr[i]);
	}
}

int Exercises() {


	/* ARRAYS */

	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31 };
	char *names[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	printArr(months, names, 12);




	/* EXERCISE 1*/

	/*

	int a = 0;
	int d = 10;

	int* x = &a;


start:

	
	printf("Please input a number that you want to divide/fraction (0 to close program) :");
	scanf("%d", x);
	
	if (*x == 0) {
		puts("Program will terminate now");
		return;
	}
	
	printf("By dividing %d by %d, the dividend is %d and the remainer is %d\n\n", *x, d, *x / d, *x % d);
	

	goto start;

	*/




	/*
	int a = 0, b = 0;
	
start:

	printf("Please input two numbers that you want to multiply :");
	scanf("%d %d", &a, &b);

	int res = getRes(&a, &b);
	if (!res) {
		puts("Program will terminate now");
		return;
	}

	goto start;


	*/

	return 0;
}


int main(void) {
	printf("Pointers !!! \n\n\n");
	Program();

	return 0;
}

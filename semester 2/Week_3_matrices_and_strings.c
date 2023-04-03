
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

Matrices => it's all about fine-tuning the logic behind the order of inputted data

y & x (respectively row and columns data) coordinates
and in what order WE need to loop in order to make our calculations,
i-e in respect of what coordinate we want our data processed and displayed.


*** BONUS ***
Strings in C are char arrays.
so arrays of strings logically become arrays of arrays of chars.

Similar order applies here as well,
char[NUM_OF_STRINGS][LENGTH_OF_STRINGS] = {"str_1", "str_2"}


---- ALSO ------
remember to assign array variables (dynamically) through scan_f() with the &myarr[y][x] pointer assignment.
as in here :
// scanf_s("%d", &grades[j][i]);

*/

int strEx() {

	/*
	char str1[15];
	strcpy(str1, "so cool !");

	puts(str1);
	*/

	/*
	char hello[150];
	puts("GIVEME STRING: ");
	gets_s(hello, sizeof(hello));
	puts(hello);
	*/

	return 0;
}

int Program(void) {


	/* Matrices */

	// Problem1();

	// Problem2();

	// Problem3();

	return 0;
}


#define LEN 10
#define LX 9
#define LY 4

int msg(char* str) { // msg("log") is going to be used for quality of life when return msg("Program Terminated") instead of annoying { printf("...\n"); return 0;}

	return puts(str);
}


/*

This Solution works for Exercise #2 & #3 (Array displaying in reverse) =>> 'Vertically' and 'Horizontally' as a choice offered by prompting user.

*/




struct Person {

	char name[40];
	char gender;
	int age;

};

int Problem1() {

	int arr[LY][LX] = { 0 };

	int i = 0, j = 0;

	int lY = LY, lX = LX;


	for (j = 0; j < lY; j++) {
		int* arrX = &arr[j];

		printf("\n");

		for (i = 0; i < lX; i++) {
			arrX[i] = (j + 1) * (i + 1);
			printf("%d\t", arrX[i]);
		}

	}
	printf("\n");


	int x, y;
	int pass = 0;

start:

	puts("Please Enter Desired Column and Row: \t");
	scanf_s("%d %d", &x, &y);

	int cur = x * y;
	if (cur < 1) return msg("Program will close now.");
	if (x >= lX || y >= lY) {
		msg(x >= lX ? "Column is out of range" : "Row is out of range");
	}
	else {
		printf("%d \n", arr[y - 1][x - 1]);
	}

	goto start;

	return 0;
}

int Problem2() {

	int arr[LEN][LEN] = { 0 };

	int inp;
	int hor;

start:
	puts("Please Enter a Digit (1~10): \t");
	scanf_s("%d", &inp);

	if (!inp || inp > 10) return msg("Program will close now.");

	puts("Do you want the in horizontal(ex 1) or vertical(ex 2) display?:");
	scanf_s("%d", &hor);

	int i = 0, j = 0;
	int l = inp * inp;

	/*
		We are here going to achieve this by mathematics, requiring one single loop instead of two.
	*/

	for (i = 0; i < l; i++) {
		int X = i % inp, Y = (int)i / inp;

		int isVert = hor % 2;
		int odd = Y % 2;

		int row = isVert ? Y : X, col = isVert ? X : Y;

		arr[row][col] = odd ? (Y * inp) + (inp - X) : (Y * inp) + X + 1;
	}

	// Logging the array
	for (i = 0; i < inp; i++) {
		printf("\n");
		for (j = 0; j < inp; j++) {
			printf("%d \t", arr[i][j]);
		}
	}

	printf("\n");

	goto start;

	return 0;
}






int main(void) {
	printf("Matrices !!! \n\n\n");
	Program();

	return 0;
}

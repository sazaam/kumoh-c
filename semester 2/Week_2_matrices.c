
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project covers While Declarations

@mission:		A Simple Recursive A and B Addition Calculation Example

*/



#include <stdlib.h>
#include <stdio.h>



#define ROWS 4
#define COLS 5
/*

In this case I used a While Loop but
also tried to re-visit the conditions for less total checks, and it happened to become more concise

*/


int Program(void) {


	/* Matrices */

	Problem_4();

	return 0;
}



/* MATRICES */


int Problem_4() {

	int mat[ROWS][COLS] = { 
		{5,10,15,20,25}, 
		{30, 35 ,40 ,45 ,50}, 
		{55 ,60 ,65 ,70 ,75}, 
		{80 ,85 ,90 ,95 ,100}
	};
	int results[COLS] = {0};
	int row = 0, col = 0, rows = 0;

	printf("========================= Rows and Columns of Matrix ========================");
	printf("\n\n");
	for (int j = 0; j < ROWS; j++) {
		rows = 0;
		printf("\t\t");
		for (int i = 0; i < COLS; i++) {
			printf("%d \t", mat[j][i]);
			row = mat[j][i];
			rows += row;
			results[i] += row;
		}
		printf("\t By Row = %d \n", rows);
	}
	printf("By Column :\t");
	for (int j = 0; j < ROWS; j++) {
		printf("%d \t", results[j]);
	}
	printf("\n\n");
	return 0;

}


int main(void) {
	printf("Matrices !!! \n\n\n");
	Program();

	return 0;
}

/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #11 Project 1 -- This is the '2-Dimension Array' project

@mission:		Create a 4 * 5 Matrix of numbers from 1 - 20, and make a function that picks all numbers of the side of a matrix,
				and returns the sum of all of them 

*/

#include <stdlib.h>
#include <stdio.h>


/*

This program will print out the highest number out of a randomized 10-Array entries

*/



/*

In this Exercise we make a program that returns greatest value between a set of 10 numbers,
each generated randomly from 1 - 100, populating a 10-sized array.

- Mission : Print out the highest generated value along with its position (index) in the array.

*/



int isBordered(int i, int j);


/*

	Main Function

*/

#define ROWS 4
#define COLS 5


int main(void) {

	printf("\n\n\n");
	printf("\t이차원 배열 미션\n");

	// initialize necessary variables
	int i, j;
	int matrix[ROWS][COLS];
	int val, result = 0;

	int space = 32;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			matrix[i][j] = (i * COLS) + j + 1;
		}
	}

	printf("\n\t테두리 요소는 다음과 같습니다.\n");
	
	for (i = 0; i < ROWS; i++) {
		printf("\n\t");
		for (j = 0; j < COLS; j++) {
			val = matrix[i][j];
			if (isBordered(i, j)) {
				result += val;
				printf("%*c%d", val > 9 ? 0 : 2, space, val);
			} else {
				printf("%*c", 3, space);
			}
		}
	}

	
	printf("\n\n\t테두리 요소들의 합은 %d입니다.", result);

	printf("\n\n\n");


	return 0;

}


int isBordered(int i, int j) {
	return (i == 0 || i == ROWS - 1) || (j == 0 || j == COLS - 1);
}
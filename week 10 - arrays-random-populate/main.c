
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #11 Project 1 -- This is the 'Array of Random Values' project

@mission:		Array of Random Values

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



/*

This program will print out the highest number out of a randomized 10-Array entries

*/



/*

In this Exercise we make a program that returns greatest value between a set of 10 numbers,
each generated randomly from 1 - 100, populating a 10-sized array.

- Mission : Print out the highest generated value along with its position (index) in the array.

*/




int populate(int arr[], int max);
int isGreaterThan(int, int);



/*

	Main Function

*/

#define MAX_LENGTH 10
#define MAX_NUMBER 100

int main(void) {

	printf("\n\n\n");

	// initialize necessary variables
	
	int highest = 0, index = -1; // our future variables containing highest number and its index in array
	int arr[MAX_LENGTH]; // Our array of length 10

	
	printf("1 부터 100까지의 범위에서 랜덤 수를 10개 생성하며 배열에 저장한다!\n\n"); // input three numbers (3 561 89)
	
	// Populate existing array Arr with random numbers
	populate(arr, MAX_NUMBER);

	
	// Parse Array while looking for highest number in it
	for (int i = 0; i < 10; i++) {
		// if a higher number is found
		if (isGreaterThan(arr[i], highest)) {
			highest = arr[i];
			index = i;
		}
	}

	printf("\n\n\tHighest number found is : %d , at index :%d\n", highest, index);
	
	return 0;

}


int populate(int arr[], int max) {
	srand((unsigned)time(NULL)); // Set Random Seed
	for (int i = 0; i < 10; i++) printf("\n\t arr[%d] = %d", i, arr[i] = 1 + (rand() % max)); // Assign Random number and print it out
	return 1;
}



/*

	Helper Functions

*/


int isGreaterThan(int m, int n) {
	return  m > n; // if 'm' is less than 'n' return 'm' if not return 'n' ;
}

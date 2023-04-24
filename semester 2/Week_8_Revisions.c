
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

#include <time.h>

/*

Scheduler Minproject Example
Writing/Reading Arrays of structs

*/


int Program(void) {
	
	
	// Exercise #1
	// RandomArrayFindHighestFindEvens();


	// Exercise #2
	// myAccountsArrayOfStructs();

	// Exercise #3
	// ArrayShiftLeftRight();

	return 0;
}



struct Account {
	char name[20];
	double amount, income, rate, interest;
};


#define ACCOUNTS 5

int myAccountsArrayOfStructs() {

	puts("\t====== My Accounts ========== \n");

	struct Account accounts[ACCOUNTS] = {
		{"free", 100, 10, 3.20},
		{"house", 240, 20, 4.40},
		{"travel", 50, 25, 3.50},
		{"hospital", 30, 10, 3.00},
		{"wedding", 40, 15, 4.00}
	};

	int i = 0, l = ACCOUNTS;
	double total =0 ;

	printf("[ %s \t\t %s \t%s \t %s \t%s    ]\n", "name", "amount", "income", "rate", "1-Yr interest");
	printf("----------------------------------------------------------------------------\n");
	for (i = 0; i < l; i++) {
		struct Account* acc = &accounts[i];

		double interest = acc->income*12;
		acc->interest = acc->amount + interest + ((acc->amount + interest)/100*acc->rate);
		//acc->interest = acc->amount + (acc->amount / 100 * acc->rate);
		total += acc->interest;

		printf("  %s  \t %1.0f \t\t %1.2f \t%1.2f \t%1.3f \\\n", acc->name, acc->amount, acc->income, acc->rate, acc->interest * 10000);
	}
	puts("");
	printf("Total Value of Savings : %1.3f \\. \n ", total * 10000);

}




#define MAX_LENGTH 30
#define MAX_NUMBER 100


int populate(int arr[], int len, int max) {
	srand((unsigned)time(NULL)); // Set Random Seed
	for (int i = 0; i < len; i++) printf("\n\t %d : %d", i, arr[i] = 1 + (rand() % max)); // Assign Random number and print it out
	puts("\n");
	return 1;
}


int isLessThan(int m, int n) {
	return  m < n; // if 'm' is less than 'n' return 'm' if not return 'n' ;
}

int isGreaterThan(int m, int n) {
	return  m > n; // if 'm' is less than 'n' return 'm' if not return 'n' ;
}

int isEven(int n) {
	return n % 2 == 0;
}

int findHighest(int arr[], int len) {
	int index = 0, hi = 0;

	for (int i = 0; i < len; i++) {
		
		if (isGreaterThan(arr[i], hi)) {
			index = i;
			hi = arr[i];
		}
	}
	return index;
}


int findHighestLowest(int arr[], int len, int way) {

	int index = 0, n = 0;
	n = way ? 0 : 500;

	for (int i = 0; i < len; i++) {
		int cond = way ? isGreaterThan(arr[i], n) : isLessThan(arr[i], n);
		if (cond) {
			index = i;
			n = arr[i];
		}
	}
	return index;
}

void findEvensOdds(int arr[], int evens[], int odds[], int len) {
	
	for (int i = 0; i < len; i++) {
		int cond = isEven(arr[i]);
		evens[i] = cond ? arr[i] : -1;
		odds[i] = (!cond) ? arr[i] : -1;
	}
}

int RandomArrayFindHighestFindEvens() {

	printf("\n\n\n");

	// initialize necessary variables

	int hi = 0,lo = 0; // our future variables containing highest number and its index in array

	int arr[MAX_LENGTH]; // Our array of length 10


	printf("populating 30-length array with 0~99 integers!\n\n"); // input three numbers (3 561 89)

	// Populate existing array Arr with random numbers
	populate(arr, MAX_LENGTH, MAX_NUMBER);
	

	// Find Highest
	hi = findHighestLowest(arr, MAX_LENGTH, 1);
	printf("\tHighest number found is : %d , at index :%d\n", arr[hi], hi);

	lo = findHighestLowest(arr, MAX_LENGTH, 0);
	printf("\tLowest number found is : %d , at index :%d\n", arr[lo], lo);
	// Find Evens
	// Create New Empty Array of size MAX_LENGHTH
	int evens[MAX_LENGTH] = { 0 }, odds[MAX_LENGTH] = {0};
	// Fetch for Evens
	findEvensOdds(arr, evens, odds, MAX_LENGTH);

	// Print the results out, as EVENS array is now saved
	puts("");
	puts("searching for even numbers :\t");

	for (int i = 0; i < MAX_LENGTH; i++) {
		if (evens[i] !=-1) printf(" %d", evens[i]);
	}
	puts("");
	puts("searching for odd numbers :\t");
	for (int i = 0; i < MAX_LENGTH; i++) {
		if (odds[i] != -1) printf(" %d", odds[i]);
	}

	puts("");

	return 0;
}




#define ARR_MAX 5



int getNextIndex(int n) {
	return n >= ARR_MAX ? 0 : n < 0 ? ARR_MAX - 1 : n ;
}

void array_shift(int* origin, int* shifted, int left_right) {
	for (int i = 0; i < ARR_MAX; i++) {
		int n = getNextIndex(left_right ? i + 1 : i - 1);
		shifted[i] = origin[n];
	}
}

enum MyEnum{RIGHT, LEFT};

int ArrayShiftLeftRight() {
	

	int origin[ARR_MAX], shifted[ARR_MAX];

	populate(origin, ARR_MAX, 100 - 1);
	printf("\t resulting Array :");
	for (int i = 0; i < ARR_MAX; i++) printf(" %d", origin[i]);
	
	puts("\n");


	puts("Shifting Left >>");
	array_shift(origin, shifted, LEFT);
	for (int i = 0; i < ARR_MAX; i++) printf(" %d", shifted[i]);
	puts("");

	puts("Shifting Right <<");
	array_shift(origin, shifted, RIGHT);
	for (int i = 0; i < ARR_MAX; i++) printf(" %d", shifted[i]);
	puts("");


	return 1;
}







int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}
















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




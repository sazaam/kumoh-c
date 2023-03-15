
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project covers While Declarations

@mission:		A Simple Recursive A and B Addition Calculation Example

*/



#include <stdlib.h>
#include <stdio.h>


/*

In this case I used a While Loop but
also tried to re-visit the conditions for less total checks, and it happened to become more concise

*/


int Program(void) {


	/* Arrays */

	//Problem_1();
	//Problem_2();
	Problem_3();


	return 0;
}



/* ARRAYS */


int Problem_1() {
	int total = 0,
		scores[5] = { 89,  99, 97, 100, 98 };

	int l = sizeof(scores) / sizeof(scores[0]);

	for (int i = 0; i < l; i++) {
		int sc = scores[i];
		total += sc;
		printf("Score #%d => %d\n", i, sc);
	}
	double av = (double)total / l;

	printf("Your average score => %1.5f\n", av);

	return 0;
}



int Problem_2() {

	int number = 0, def = -1, n,
		numbers[] = { 8,7,3,6,9,6,8,7,0,4,1,2 };

	printf("Enter Your desired number :\t");
	scanf_s("%d", &number);

	int l = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < l; i++)	if ((n = numbers[i]) == number)
		printf("found @ %d \n => %d \n", i, def = number);

	if (def == -1) printf("not found any index for value : %d\n", number);

	return 0;

}



int Problem_3() {

	int hi = 0, lo = 100,
		scores[] = { 88,97,53,62,92,68,82 };


	int l = sizeof(scores) / sizeof(scores[0]);
	for (int i = 0; i < l; i++) {
		int n = scores[i];
		(hi = n > hi ? n : hi) && (lo = n < lo ? n : lo);
	}

	printf("Highest score \t: %d\nLowest score \t: %d\n", hi, lo);

	return 0;

}



int main(void) {
	printf("Arrays !!! \n\n\n");
	Program();

	return 0;
}
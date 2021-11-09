
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 1 -- This project covers the use of Numerical For-In / While Loops

@mission:		A Simple For-In Loop / While Example

*/




/*

This program can provide multiplication tables of any given number N up to 10 times
	Primary Mission :
		- Provide Multiplication Tables of N times 1~9

	Bonus Missions :
		- Provide Power Tables
		- Use a While Loop as well
*/

#include <stdlib.h>
#include <stdio.h>


/// MAX TIMES AS A CONSTANT
#define MAX_TIMES 9
#define MAX_POWER 10




/*

	In this example, For-In Loop seems appropriated, but just for fun 'while' can also be used...
	since while(condition) {...} will execute only if condition is true,
	if incremetation is done DESCENDING
	when it reaches ZERO it will convert to false 
	and jump out of while statement.

*/


int multiply(void) {

	// initialize
	int n, m = MAX_TIMES, p = 0; // iterating variable set to MAX, and multiplier set to ZERO

	// Require N-times Input from User
	printf("\t몇 단을 출력할까요 : \n");
	printf("\n\n");

	scanf_s("%d", &n);

	while (m--) {
		p = MAX_TIMES - m; // As M descends, P should reflect our desired multiplier (i-e : 9 - m)
		printf("\t %d * %d >> %d\n", n, p, p * n); // Here I chose p*n instead of adding n+=n each time to avoid another variable declaration
	}
	


	/*
		Same results, but with For-In Loop, 
		we can see why For-In is more practical when looping on numbers (and not logically)
	*/
	
	/*
	printf("\n\n\n");

	for (int i = 1; i < MAX_TIMES + 1 ; i++) {
		printf("\t %d * %d >> %d\n", n , i, i * n);
	}
	*/


	return 0;
}



/*

	In this example, For-In Loop is still a favorite,
	and here a nested loop is handy for a safe -multiply by itself- control
	
	// Special cases of Zero and One, since
		- Power by Exponent 0 always returns 1
		- Power by Exponent 1 always returns n
*/

int power(void) {

	// initialize
	int n, p;
	// Require N-times Input from User
	printf("\n\n");
	printf("\t(1~%d) 몇 단을 출력할까요 : \n", MAX_POWER);

	scanf_s("%d", &n);

	if (n > MAX_POWER) {
		n = MAX_POWER;

		printf("\tnumber is too high, %d will be taken instead\n", n);
	}

	p = n;
	for (int i = 0; i < MAX_TIMES + 1; i ++) { // Max Times + 1 since we also would like the loop to go up to n^9
		n = (i == 0) ? 1 : p;	// Handle case of n^0 with a custom 'set to 1' approach.
		for (int j = 1; j < i; j++) { // Handle case n^1 just by skipping loop if 'i == 0' ==>> 'j' starting at 1 but also needs to be less than 'i' to enter the j-loop
			// here j is declared inside the loop to contain the variable scope, thus be rewritten every new 'i'-loop.
			// 'j' cannot be greater than or equal to 'i' to handle the n^1 case, which leaves 'n' untouched
			n *= p;	// --> perform self-multiplication each 'j'-loop
		}
		printf("\t %d^%d >> %d\n", p , i, n);
	}

	return 0;
}


int main(void) {

	// Multiply
	printf("\n\n\n");
	
	printf("\t구구단 프리트하기\n");
	printf("\t(Printing Multiplication Tables)\n");
	
	multiply();


	// Power
	printf("\n\n\n");
	
	printf("\t상승단 프리트하기\n");
	printf("\t(Printing Exponentiation Tables)\n");
	
	power();

	printf("\n\n\n");




	return 0;
}

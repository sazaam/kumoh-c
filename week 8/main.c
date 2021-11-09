
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #9 Project 1 -- These Are the Multiples Calculating Recursive Function project

@mission:		Recursive Closure examples

*/

#include <stdlib.h>
#include <stdio.h>



/*

This program will print the Multiples of any number with multiplier base 1 ~ 9
within a recursive closure.

*/



/*

In this Exercise are given the mission of listing 1 ~ 9 multiples of any given integer 'n'

- Primary Mission : Use a Self Recursive Function, No loop allowed for the output
- Secundary Mission : Write the simpliest / shortest possible Function 

ex : when (n == 19) =>

	19 * 1 = 19
	19 * 2 = 38
	19 * 3 = 57
	19 * 4 = 76
	19 * 5 = 95
	19 * 6 = 114
	19 * 7 = 133
	19 * 8 = 152
	19 * 9 = 171

	when (n == 0)  --> exit the program
*/


	#define MAX_COUNTS 9 // Maximum as a Constant


	/* 교수님 감사합니다 ^^ 
		Ahead-Declaring is a much nicer system, so that *main* could remain on top
	*/

	int multiples(void);
	int GuGuDan(int, int);
	int GuGuDanShort(int, int);
	int print(int, int);
	int mul(int, int);

	




	/*

		Main Function

	*/
	int main(void) {
		printf("\n\n\n");
		return multiples();
	}




	/*
	
		Handling Function for Multiple Inputs
	
	*/


	int multiples(void) {
		// initialize necessary variables
		int n = 1, s;
		printf("구구단 프로그램\n\n");

		while (n) { // As long as N is not equal to Zero (NEGATIVE NUMBERS ALLOWED !!!)
			printf("하나의 숫자를 입력하세요 (0 입력하는 경우에는 종료됩니다)  : ");
			scanf_s("%d", &n);
			// retrieve 'n' as input
			printf("\n");

			n && GuGuDanShort(n, MAX_COUNTS); // entering ZERO will quit the program
			printf("\n");
		}
		
		printf("\t프로그램은 종료합니다.\n");

		return 0;
	}



	/*
	
	First Example, Traditionnal yet simple
	
	The trick to use less code and variables is to have DESCENDING resursivity 
	since we are going downwards in recursion, we don't need to keep trace of MAX since we will already know ZERO,
	
	and only AFTER the check + recursivity => 
	THEN print the result :

	> so that the print order will remain ASCENDING like we want (1 ~ 9)

	*/

	int GuGuDan(int n, int max) {

		if (max) { // of course, when max equals zero this is considered false
			GuGuDan(n, max - 1); // call itself recursively
			print(n, max); // then print
		}
		
		return max;

	}

	/*

	Second Example, Short and somewhat more advanced, one single declaration but more checks.
	Although, if any condition fails no further actions and checks would be made, so it still seems correct,
	since here the Boolean check comes for free with the Function call as it returns something.

	*/
	int GuGuDanShort(int n, int max) {
		return (max && GuGuDanShort(n, max - 1) && print(n, max)) + 1; // Need to trick the checking with a +1 though...
	}


	/*
		
		Helper Functions
			- print : Print out formatted string
			- mul : Calculates Multiplication of two integers

	*/

	int print(int a, int b) {
		return printf("\t%d * %d = %d\n", a, b, mul(a, b)) && b; // here printf(...) should always return a positive int ( > 0 ) as long as the string length is not ZERO
	}

	int mul(int a, int b) {
		return a * b; // simple multiplication
	}

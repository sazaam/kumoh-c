
/*

@author		> sazaam (sazaam@gmail.com)
			> github.com/sazaam/
@version	> 0.0.1

@desc		> My Second Project - 2nd Week / 'printf' Mission

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Simple printf() example
		
		Using Math.pow function for better visual track of our exponents.
		And using %nc form, where n is desired number of spaces.

*/
int main(void) {
	
	printf("*** printf() Mission ***\n\n\n\n");

	int space = 32;		// Our spacebar keycode
	
	printf("%4c%d\n", space, (int)(pow(10, 1))); 
	printf("%3c%d\n", space, (int)(pow(10, 2)));
	printf("%2c%d\n", space, (int)(pow(10, 3)));
	printf("%c%d\n", space, (int)(pow(10, 4)));
	printf("%d\n", (int)(pow(10, 5)));

	printf("%8c%d\n", space, (int)(pow(10, 1))); 
	printf("%8c%d\n", space, (int)(pow(10, 2)));
	printf("%8c%d\n", space, (int)(pow(10, 3)));
	printf("%8c%d\n", space, (int)(pow(10, 4)));
	printf("%8c%d\n", space, (int)(pow(10, 5)));

	printf("\n\n\n*** Mission Complete ! ***\n");

	/*
	*
		GOAL :::
	Should print >>

		10
	   100
	  1000
	 10000
	100000
			10
			100
			1000
			10000
			100000

	*
	*/
	return 0;

	




	int input;			// Will serve as a holder of user input
	char* s;			// Our reply message
	int i;				// The main iterator






	/*
		Part 1. Prompt User
		User inputs here a 10^n exponent as for how many zeroes this game should go.
	*/
	printf("How many Zeroes do you want ? \n");
	scanf_s("%d", &input);
	
	if (input > 10) { // Max Int Number in C = 2147483647, so max = 10^9
		input = 9;
		s = "This would be silly... let us clamp that to";
	}else {
		s = "Your requested multiple of 10";
	}
	/*
		Let us inform the User that his entry was taken into account.
	*/
	printf("%s : %d ...\n\n", s, input = (int)(pow(10, input)));  // Power Function very useful for dynamic exponentiation

	/*
		Part 2. 
		Now the game....
		- first sequence, growing by 10^n + 1
	*/
	int min = 10;			// we want a min value
	int max = input;		// ... and a max

	for (i = min; i <= max ; i *= 10) {		// loop with x10 incrementations, min < i <= max
		
		int j = max;		// set second iterable 'j' to max, in order to write spaces in front

		while (j > i) {		// loop back to where 'i' exponent is, compared to max
			printf("%c", space);
			j /= 10;		// ...dividing by ten
		}

		printf("%d\n", i);	// print our number

	}

	/*
		- second sequence, doing it again...
	*/
	for (i = min; i <= max; i *= 10) {
		
		int j = max;		// 'j' will be used similarily here
		
		while (j > 0) {		// loop back to where 'i' exponent is, compared to max
			printf("%c", space);
			j /= 10;
		}
		
		printf("%2c", space); // Looks like there are two empty spaces in the example
		
		printf("%d\n", i);	// print our number after 'space' sequence

	}


	printf("\n\n\n*** Mission Complete ! ***\n");


	/*
	* 
		GOAL :::
	Should print >>
	
	    10
	   100
	  1000
	 10000
	100000  
	        10
	        100
	        1000
	        10000
	        100000

	* 
	*/


	return 0;
}

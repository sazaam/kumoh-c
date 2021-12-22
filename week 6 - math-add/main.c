
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project covers While Declarations

@mission:		A Simple Recursive A and B Addition Calculation Example

*/




/*

This program will print the result of the addition of Integers A and B
	- ex  : A = 5 ; B = 6

	--> 5 + 6 = 11
	--> 4 + 9 = 13
	--> ...

	- conditions :
		#0 : A and B inputs should be entered within one scanf (with one space in between)
		#1 : if the two numbers are the same, don't print out the result
		#2 : if the two numbers are bot ZEROs, exit the program.




*/
#include <stdlib.h>
#include <stdio.h>


/*

In this example I thought making the A and B calculations recursively would be a good try of
taking advantage of the goto (Label) possibilities, 
and figured out any While or For loop declarations were not even required.


*/

int AddProgram(void) {

	// initialize our two Integers
	int a, b, areSame, areZeros;
	
start:
	
	// Require A and B inputs from the user
	printf("\tA 와 B 숫자 입력해 주십시오 : \n");
	scanf_s("%d %d", &a, &b);
	
	areSame = a == b; // Check for inputs equality, and store as it will be in use to know if these are zeros
	areZeros = areSame && !a; // (!a is equivalent to check if a == 0) and since we know they are same only need to check on one input

	if (areZeros) {
		goto end; // quit the program
	}
	if (!areSame) {
		printf("\t\t%d + %d = %d \n\n", a, b, a + b); // only print out if A and B are not the same number
	}
	goto start; // re-route to top in order to loop
	
end:
	return 0;

}

/*

In this case I used a While Loop but 
also tried to re-visit the conditions for less total checks, and it happened to become more concise

*/


int AddProgramWhile(void) {

	int loop = 1, a, b;

	while (loop) {
		
		printf("\tA 와 B 숫자 입력해 주십시오 : \n");
		scanf_s("%d %d", &a, &b);

		if (a != b)			// only print if A is different to B
			printf("\t\t%d + %d = %d \n\n", a, b, a + b); 
		else if (!a)		// but if they are the same and at least one of them (A) is ZERO then exit the program
			loop = 0; // (break; would also work here.)
	}

	return 0;
}


int main(void) {

	printf("\n\n\n\t입력된 A + B 계산하기\n\t(Returning A + B calculation)\n");

	AddProgramWhile();

	printf("\t프로그램은 종료합니다.\n\n");
	printf("\n\n\n");

	return 0;
}

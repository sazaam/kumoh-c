
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project contnues to cover the use of Numerical For-In Loops + Nested Loops

@mission:		A Simple Nested For-In Loop Example

*/




/*

This program will print blank spaces and stars as much as requested in 'scanf' prompt
	Primary Mission :
		- print out a star pattern of "N" rows and "N columns", the stars replacing the blanks in line progressively

		- ex  : N = 5

			[    *]
			[   **]
			[  ***]
			[ ****]
			[*****]





*/
#include <stdlib.h>
#include <stdio.h>


/// MAX TIMES AS A CONSTANT
#define MAX_STARS 15




/*

	In this example, two Nested For-In Loops are the way to go,
	as variable 'i' will track line index and position within one line
	and 'j' will track character index and constantly check on 'i' for what to character print

	Choice :
	It makes sense to have i set to ONE (not to ZERO) and go to N (included)
	as it will be easier (and less confusing) to have 'j' track its progress 
	since we are printing stars on the right side, which means if 'j' is getting higher than 'n-i'.
	But for 'j' it would be easier to just start at ZERO and have a more common Array-like index.

*/


int drawStars(void) {

	// initialize
	
	// 입력 숫자, 로컬 숫자
	int n, p; 

	// 별 "*" 과 빈칸 " " ASCII
	int star = 42, space = 32;
	// 특별 ASCII '[', ']' 빈칸을 명확하게 보이게
	int brack_in = 91;
	int brack_out = 93;

	// Require N-times Input from User
	
	printf("\n\n");
	
	printf("\t(1~%d) 몇 줄을 출력할까요 : \n", MAX_STARS);

	scanf_s("%d", &n);

	// If entered ZERO or under... no need to continue
	if (n < 1) {
		printf("\t%d을 입력하면 종류하겠어요 .\n", n);
		return 0;
	}
	// If entered too high of a number set it to some Maximum... Loops are somehow dangerous when out of control
	if (n > MAX_STARS) {
		n = MAX_STARS;
		printf("\t너무 많게 입력 하셔서, 대신에 %d 개로 하겠어요.\n", n);
	}
	

	// One Line - loop
	for (int i = 1; i <= n; i++) {
		
		printf("\n\t%c", brack_in);
		
		// One Character - loop
		for (int j = 0; j < n; j++) { 
			printf("%c", (j >= n - i) ? star : space);
	
		}
		
		printf("%c\n", brack_out);
	}

	return 0;
}


int main(void) {

	printf("\n\n\n\t별 여러 개를 그리는 것\n\t(Drawing Stars)\n");

	drawStars();

	printf("\n\n\n");

	return 0;
}


/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- These Are the Result of coding Lesson Week 7

@mission:		Multiple examples

*/

#include <stdlib.h>
#include <stdio.h>



/*

This program will print the number of Days in the user-inputted Month.

In this example I thoughtof taking advantage of the array to reduce code.

*/



int findMonth(void) {

	// initialize our two Integers
	int m, mm, d;
	int arr[] = {1, 2, 1, 0, 1, 0 , 1, 1, 0, 1, 0, 1};


	// Require A and B inputs from the user
	printf("\t월 선택해 주십시오 : \n");
	scanf_s("%d", &m);

	mm = arr[m-1];

	switch (mm) { // only three cases here, long month, short month, and 'february' special case
		case 0:
			d = 30;
			break;
		case 1:
			d = 31;
			break;
		case 2:
			d = 28;
			break;
	}

	printf("\n\t%d월은 %d일까지 있습니다", m, d);
	

	return 0;

}

/*

In this Example a While loop is used to check remaining gas in the Tank, as we use and refill it.

*/

int remainingGas(void) {

	// initialize our two Integers
	int current_fuel = 500, usage = 0;

	int limit = current_fuel * .01;

	while (current_fuel > limit) { // the condition check should decide whereas we should execute program
		printf("\n\t현제 연류량 : %d\n", current_fuel);
		printf("\n\t연류량 사용량 입력해 주십시오: (충전이면 +, 사용이면 -)\n");
		scanf_s("%d", &usage);
		current_fuel += usage;
	}

	printf("\n\t연류가 10% 이하로 떨어져서 중료합니다.");

	return 0;

}


/*

In this Example we check how many times the character 'a' is inputted.

*/
int countLetters(void) {

	char c = 0;
	int n = 0;
	while (c!= '.') { // as long as '.' is not the entered character, execute the following...
		printf("문자를 입력하세요 : ");
		scanf_s("%c", &c);
		while (getchar() != '\n'); // special getchar() case.
		if (c == 'a') {
			n++;
		}
	}
	printf("a의 개수는 %d입니다", n);
	return 0;


}

/*

In this Example we try to find geometric series of 'n' multiples of given base 'b'.

*/
int getMultiples(void) {

	int n = 0, 
		max = 0,
		i = 0,
		base = 0;

	printf("몇개의 배수와 몇까지 입력해 주십시오 : ex(3 100)");
	scanf_s("%d %d", &base, &max);

	base = !base ? 3 : base;
	max = !max ? 100 : max;


	while (i < max) {
		if (i % base == 0) n += i;
		i++;
	}
	printf("1부터 100까지 모두 3의 배수의 합은 %d입니다.", n);
	return 0;


}



/*

In this Exercise are given the mission of building a pyramid of Multiples
so that for all 'i' (from 1 to any given number 'n'), we should print out the successive list of 'i'-multiples of 'i'

Since we are dealing with numerical loops, the use of two nested 'for' loops seems practical.

ex : when (n == 5) =>

	1
    2 4
    3 6 9
    4 8 12 16
    5 10 15 20 25

*/
int drawPyramidalMultiples(void) {
	
	printf("다중 피라미드\n\n");
	// initialize necessary variables
	int v = 0,
		max = 0,
		i = 1,
		j = 0;

	
	printf("몇까지 입력해 주십시오 : ");
	scanf_s("%d", &max);
	// retrieve Max 'n' as input
	
	printf("\n");
	max = !max ? 5 : max; // prevent entering ZERO

	// First Main Loop -> Loop through increments 'i' of 'n' until reaches 'max'
	for (; i <= max; i++) {
		// Here i is already equal to one at start, which means should loop until (i <= max)

		printf("\t"); // print a tab to look nicer

		v = 0; // reset value

		// Secundary Loop -> Loop within the multiples suite
		for (j = 0; j < i; j++) {
			// in this loop j shoud start at value ZERO, so should loop until (j < i)
			v += i;
			printf("%d ", v);
		}
		
		printf("\n");
	}

	return 0;


}

/*

	Main Function 
		*** Calls to all smaller projects ***

*/


int main(void) {

	printf("\n\n\n");

	//findMonth();
	
	//remainingGas();

	//countLetters();
	
	//getMultiples();
	
	drawPyramidalMultiples();
	
	printf("\n\n\n");
	return 0;
}

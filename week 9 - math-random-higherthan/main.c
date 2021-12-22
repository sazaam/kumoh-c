
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #10 Project 1 -- This is the 'Returns highest number out of three' Function project

@mission:		Chained Returning Closures

*/

#include <stdlib.h>
#include <stdio.h>



/*

This program will print out the highest number out of any set of three integers.

*/



/*

In this Exercise we make a program that returns greatest value between 3 given integers 'm', 'n' and 'o'

- Primary Mission : Use nested function calls that each pass back the returned value
- Secundary Mission : do the same but for finding Min value instead of Max value

- Bonus Mission : Write the functions WITHOUT a single BOOLEAN CHECK (solve only mathematically or else)


ex : when (m == 12 , n == 196, and o == -987) =>

	--> should return 196    (since -987 < 12 < 196)

	when (m == 0 , n == 0, and o == 0)  --> exit the program
*/



//int multiple_inputs(void);

// technique 1
int findMax(int, int, int);
int findMin(int, int, int);

int greaterThan(int, int);
int lessThan(int, int);


// technique 2
int findMaxWithMath(int, int, int);
int findMinWithMath(int, int, int);

int greaterThanWithMath(int, int);
int lessThanWithMath(int, int);

int m_abs(int);





/*

	Main Function

*/

int main(void) {

	printf("\n\n\n");
	
	// initialize necessary variables
	int a = 1, b = 1, c = 1, s;

	printf("가장 큰 수를 판단합니다!\n\n"); // input three numbers (3 561 89)


	while (a || b || c) { // we want to exit the program when ALL are zeroes

		printf("\t3개의 정수를 입력하세요 (0만 입력하는 경우에는 종료됩니다)  : ");
		scanf_s("%d %d %d", &a, &b, &c);
		// retrieve 'n' as input
		printf("\n");

		s = findMaxWithMath(a, b, c); // entering ZEROES (0 0 0) will quit the program
		printf("\t\t3개의 정수 중에 가장 큰 수는 %d 입니다.\n\n", s);
	}

	printf("\t프로그램은 종료합니다.\n");

	return 0;

}




/*

	Handling Function for Multiple Inputs

*/





/*

First Example, Traditionnal and of course, very simple

It is easy since we know the number of max sets of values which is 3.
If not we would have needed an array and a loop that would check the whole array.

*/

int findMax(int m, int n, int o) {
	return greaterThan(greaterThan(m, n), o); // first compare 'm' to 'n', and compare the result to the value of 'o'. 
}

int findMin(int m, int n, int o) {
	return lessThan(lessThan(m, n), o); // first compare 'm' to 'n', and compare the result to the value of 'o'. 
}

int greaterThan(int m, int n) {
	return  m > n ? m : n; // if 'm' is greater than 'n' return 'm' if not return 'n' ;
}

int lessThan(int m, int n) {
	return  m < n ? m : n; // if 'm' is less than 'n' return 'm' if not return 'n' ;
}

/*

Bonus Example, more complex, but not a single boolean checks.

*/

int findMaxWithMath(int m, int n, int o) {
	return greaterThanWithMath(greaterThanWithMath(m, n), o);
}

int findMinWithMath(int m, int n, int o) {
	return lessThanWithMath(lessThanWithMath(m, n), o);
}

int greaterThanWithMath(int m, int n) {
	return  (m + n + m_abs(m - n)) >> 1; // always find greatest value by calculation ((a + b + |a - b|) /2)
}

int lessThanWithMath(int m, int n) {
	return  (m + n - m_abs(m - n)) >> 1; // always find greatest value by calculation ((a + b - |a - b|) /2)
}

int m_abs(int x) {
	
	// ORIGINAL METHOD
	/*
	int s = (x >> 31); // gets positiveness of value (0 if positive, -1 if negative)
	int d = x + s; // adds positiveness to magnitude
	int r = (d ^ s); // shifts it back to our number with always positive sign, since now if negative integer is not correct
	printf("\noriginal: %d \t%d   -> %d  ---> %d\n", x, s, d, r);
	*/

	return (x + (x >> 31)) ^ (x >> 31); // use of byte-shifting technique to return absolute value of an integer. (-12 => 12, 12 => 12) 
	// actually this is a 'check' (bitwise XOR compare) 
	// (last byte contains Negative/Positive information, 
	// if that byte is XOR checked, byte copy will occur ONLY if one of the two is different but not both)
}


//int multiple_inputs(void) {
	//return 0;

	/*
		// KEEP FOR LATER USE
		// MULTIPLE SCANF INPUTS --> enter ANY non-numeric value to finish inputting
		int array[100];
		int i = 0;

		while (i < 100 && scanf_s(" %d", &array[i]) == 1) i++;
		while (--i >= 0 ) printf("\n%d", array[i]); // Array will actually contain the extra non-numeric value, so need to skip it with --i instead of i--
	*/

//}
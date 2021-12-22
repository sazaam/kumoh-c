
/*

@author :		sazaam@gmail.com
@description :	Week#3 Project 1 -- This project covers Calculation, Comparison and Booleans operators
@mission:		A Simple Area and Circumference calculator.

*/



#include <stdio.h>

/*

Example #1 - Math Operations 1 - (Basic & Integers)

int main(void) {

	int a, b;
	int sum, sub, mult, inv;

	a = 10;
	b = 20;

	sum = a + b;
	sub = a - b;
	mult = a * b;
	inv =  -a ;

	printf("a�� �� : %d, b�� �� : %d \n", a, b);
	printf("���� : %d \n", sum);						// 30
	printf("���� : %d \n", sub);						// -10
	printf("���� : %d \n", mult);					// 200
	printf("a�� ���� ����: %d \n", inv);				// -10	

	return 0;
}
*/


/*
 
Example #2 - Math Operations 2 - (Float / double requirements)

int main(void) {

	double apple;
	int banana, orange;

	apple = 5.0 / 2.0; // ==> divide as we would expect, apple needs to be 'double'-typed

	banana = 5 / 2; // => divide, but floor quotient, 'int'-type truncates decimal information
	orange = 5 % 2; // => Modulo Operator, here 'int'-type is enough to know if result is odd or even.

	printf("apple : %.1lf \n", apple);				// 2.5
	printf("banana : %d \n", banana);				// 2
	printf("orange : %d \n", orange);				// 1
	

	return 0;
}
*/


/*

Example #3 - Incrementations 1 - Basic Positive-Negative increments

int main(void) {

	int a = 10, b = 10;

	++a; // => increments by 1
	--b; // => decrements by 1

	printf("a : %d \n", a);							// 9
	printf("b : %d \n", b);							// 11

	return 0;
}
*/



/*

Example #4 - Incrementations 2 - Order

int main(void) {

	int a = 5, b = 5, c = 3;
	int pre, post;

	pre	= (++a) * c ; // => increments variable a by 1 AND multiplies a*c
	post = (b++) * c ; // => multiplies b*c AND increments variable b afterwards

	printf("�ʱ갪 a : %d, b : %d \n", a, b);		// 6 ==> was incremented

	printf("������ (++a) * 3 : %d \n", pre);			// 18
	printf("������ (b++) * 3 : %d \n", post);		// 15 ==> different result
	
	return 0;
}
*/


/*

Example #5 - Comparisons 

int main(void) {

	int a = 10, b = 20, c = 10;
	int res;
	
	res = (a > b);
	printf("(a > b) : %d \n", res);					// 0
	res = (a >= b);
	printf("(a >= b) : %d \n", res);				// 0
	res = (a < b);
	printf("(a < b) : %d \n", res);					// 1
	res = (a <= b);
	printf("(a <= b) : %d \n", res);				// 1
	res = (a <= c);
	printf("(a <= c) : %d \n", res);				// 1
	res = (a == c);
	printf("(a == c) : %d \n", res);				// 1
	res = (a != c);
	printf("(a != c) : %d \n", res);				// 0
	return 0;
}
*/

/*

Example #6 - Logical Comparisons

int main(void) {

	int a = 30;

	int res;
	

	res = (a > 10) && (a < 20);
	printf("(a > 10) && (a < 20) : %d \n", res);	// 0
	res = (a > 10) || (a < 20);
	printf("(a > 10) || (a < 20) : %d \n", res);	// 1
	res = !(a >= 30);
	printf("!(a >= 30) : %d \n", res);				// 1
	
	
	return 0;
}
*/

/*

Example #7 - Storing in variables

int main(void) {

	int a = 10, b = 20, res;
	
	a + b;											// this does NOT store anything, since no assignment to no variable
	printf("%d + %d = %d \n", a, b, a + b);			// 10 + 20 = 30
	
	res = a + b;									// a result should be ASSIGNED to a variable in order to store it.
	printf("%d + %d = %d \n", a, b, res);			// 10 + 20 = 30
	
	
	return 0;
}
*/



/* MISSION 
	
	Small Program that calculates for us, given the radius of a circle :
		- the circumference,
		- and the area
		of that given (radius 'r') circle.

		Given Tools :
			- Math >> PI constant
			- Circumference equation : c = r * 2 * PI ;
			- Area equation : A = r�� * PI ;
	
		Constraints :
			- Calculating everything in Ints would make the program so poor, 
			- Thus user input & calculations should be float-ready.

*/


#define _USE_MATH_DEFINES	// In order to have precise PI constant
#include <math.h>			// Let's import Math lib + Constants

double calc(double r, int isArea) {
	return M_PI * r * (isArea ? r : 2.0) ; // isArea ? PI * r�� : 2 * PI * r ;
}

int main(void) {

	printf("\n\n\n");

	double r, circ, area; // rad variable

	printf("Please Enter Circle Radius / ���� �������� �Է��ϼ��� : \n"); // ���ϴ� ������ �Է��� ��Ź��

	if (scanf_s("%lf", &r) != 1) { // �Է��ϴ� �� ���� Ȯ����
		printf("Sorry, You didn't enter a number.\n");
		return 0;
	}
	
	circ = calc(r, 0); // ���� �ѷ��� --> circumference of circle ==> 
	area = calc(r, 1); // ���� ������ --> area of circle ==> PI * r��

	printf("--------\n");
	printf("For a %.2lf cm radius circle  / �������� %.2lf cm �̸� :\n", r, r);
	printf("| Circumference / �ѷ� \t\t: %.2lf cm\n", circ);
	printf("| Area / ���� \t\t\t: %.2lf cm��\n", area);

	printf("\n\n\n");
	

	return 0;
}
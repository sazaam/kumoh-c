
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project Structs and arrays of Structs

@mission:		Simple Exercises that uses Arays of Structs in C

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Struct Classes & Arrays

*/


int Program(void) {

	// Loans();
	Coordinates();
	return 0;
}




struct Coords {
	int x, y;
};

int Coordinates() {

	struct Coords coords[2] = {
		{0, 0},{0,0}
	};

start:	

	printf("Please Input Center C's Coordinates (X Y) :");
	scanf_s("%d %d", &coords[0].x, &coords[0].y);
	printf("\n");
	printf("Please Input Point P's Coordinates (X Y) :");
	scanf_s("%d %d", &coords[1].x, &coords[1].y);
	printf("\n");


	struct Coords * cCent = &coords[0], * cP = &coords[1];

	if (cCent->x | cCent->y | cP->x | cP->y) { // !!! Binary check combo if every of these values compute to zero !!!
		struct Coords cRes = { cCent->x + (cCent->x - cP->x), cCent->y + (cCent->y - cP->y)};
		printf("The Inverted Coordinates of P along C in X is %d , and in Y is %d \n", cRes.x, cRes.y);
		goto start;
	}

	printf("Program will return.");

	return 0;
}




struct Account {
	char name[20];
	double amount;
	double rate, loan, year1, year2;
};


#define ACCOUNTS 3

int Loans() {

	struct Account accounts[ACCOUNTS] = {
		{"travel", 1000, 1.00},
		{"house", 5020, 5.20},
		{"auto", 3200, 2.70},
	};

	int i = 0, l = ACCOUNTS;


	printf("[ %s \t\t %s \t %s \t%s \t%s \t\t%s    ]\n", "name", "amount", "rate", "loan", "year1", "year2");
	printf("----------------------------------------------------------------------------\n");
	for (i = 0; i < l; i++) {
		struct Account* acc = &accounts[i];
		
		double loan = acc->amount / 100 * acc->rate;

		acc->loan = loan;
		acc->year1 = acc->amount + (acc->amount / 100 * acc->rate);
		acc->year2 = acc->year1 + (acc->year1 / 100 * acc->rate);
		printf("  %s  \t %1.2f \t %1.2f \t%1.2f \t%1.2f \t%1.2f\n", acc->name, acc->amount, acc->rate, acc->loan, acc->year1, acc->year2);
	}
	
}






int main(void) {
	printf("Exercises Start !!! \n\n\n");
	Program();

	return 0;
}


/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #5 Project 2 -- This project covers While Declarations

@mission:		A Simple Recursive A and B Addition Calculation Example

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Define & enums
Unions : Unions are just for easily store different types of data under one item i-e group different datas together


*/


int Program(void) {

	MiniProject();

	return 0;
}


typedef struct Event {
	char name[60];
	int day;
	double start, duration;
} Evt;

#define DAYS 7
#define HOURS 24


enum Actions {View=1, Add, Remove, Close};

int MiniProject() {

	struct Event Free = { "Free", 0, 0, 0 };

	struct Evt * weekEvts[DAYS*HOURS] = { &Free };

	char DNAMES[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	//weekEvts[0] = &Free;
	int l = sizeof(weekEvts) / sizeof(weekEvts[0]);
	printf("size of Events %d", l);
	

	/*
	

	week[0][6] = &ev;
	*/

start:
	puts("--------------- Week Scheduler ----------------\n");

	puts("1 : View the Weeek's schedule.");
	puts("2 : Add an Event.");
	puts("3 : Remove an Event.");
	puts("4 : Terminate Program.");

	int action = 0;
	
	printf("Please Select Action :");
	scanf_s("%d", &action);
	puts("");


	switch (action) {
	case View:
		puts("View");
		
		for (int d = 0; d < DAYS; d++) {
			printf("Day : %s\n", DNAMES[d]);
			for (int h = 0; h < HOURS; h++) {
				printf(" - %d", h);
			}
			printf("\n");
		}

		break;
	case Add:
		puts("Add");


		int day = 0;
		int start = 13;
		int duration = 2;
		struct Event saz = { "C Prog", 0, 13, 2 };
		for (int i = 0; i < duration; i++) {
			weekEvts[(day + 1) * (start + i)] = &saz;
		}
		

		break;
	case Remove:
		puts("Remove");
		break;
	case Close:
		puts("Program will terminate now.");
		return 0;
	default:
		puts("Please input again...");
	}
	puts("");
	goto start;

	return 0;
}


int main(void) {
	printf("Exercises Start !!! \n\n\n");
	Program();

	return 0;
}

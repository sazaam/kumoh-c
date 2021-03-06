

#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES	// import Mathematic famous constants
#include <math.h>			// import Math lib

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#define rows 4
#define cols 5
#define spacing "\n\n\n"

int exercise1(void);
int exercise2(void);
int show();

void main(void) {

	srand((unsigned)time(NULL));

	printf(spacing);


	// FIRST PART OF EXAM
	exercise1();

	// SECOND PART OF EXAM
	//exercise2();
	
	printf(spacing);
}


int exercise1(void) {

	////// Honestly I do not see how it is possible to have dynamic size allowance for array
	// (i-e having sizes stored in an other way than the #define way)


	// printf("Enter Number of rows and columns :");
	// scanf_s("%d %d", &x, &y);
	// This would NOT work...
	
	int sum = show(); //  show(x, y)
	printf("\n\tFor a total of %d", sum);
	
	return 1;
}

int show() {
	int i, j, val, result = 0;
	
	int space = 32;

	int matrix[rows][cols];

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			matrix[i][j] = (i * cols) + j + 1;
		}
	}

	//FIRST LOOP

	for (i = 0; i < rows; i++) {
		printf("\n\t");
		for (j = 0; j < cols; j++) {
			val = matrix[i][j];
			printf(val < 10 ? " %d " : "%d ", val);
		}
	}

	printf("\n\n\n");


	// SECOND LOOP
	
	for (i = 0; i < rows; i++) {
		printf("\n\t");
		for (j = 0; j < cols; j++) {
			val = matrix[i][j];
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					printf(val < 10 ? " %d " : "%d ", val);
					result += val;
				}
				else {
					printf("%*c", 3, space);
				}
			}
			else {
				if (j % 3 == 0) {
					printf(val < 10 ? " %d " : "%d ", val);
					result += val;
				}
				else {
					printf("%*c", 3, space);
				}
			}

		}
	}
	printf("\n");

	return result;
}

/**/



typedef struct MONTH {
	char name[10];
	int type;
}month;

typedef struct MEMBER {
	char name[10];
	int month;
	int day;
}member;

#define MAX_FAMILY 4
#define MAX_MONTHS 12

int exercise2(void) {
	month months[MAX_MONTHS] = {
		{"january", 1},
		{"february", 2},
		{"march", 1},
		{"april", 0},
		{"may", 1},
		{"june", 0},
		{"july", 1},
		{"august", 1},
		{"september", 0},
		{"october", 1},
		{"november", 0},
		{"december", 1}
	};

	member members[MAX_FAMILY] = {
		{"GrandMa", 0, 0},
		{"Mom", 0, 0},
		{"Dad", 0, 0},
		{"Sister", 0, 0}
	};

	for (int i = 0; i < MAX_FAMILY; i++) {
		int days;
		month m = months[rand() % 12];
		members[i].month = m.name;

		switch (m.type) {
		case 1:
			days = 31;
			break;
		case 2:
			days = 28;
			break;
		default:
			days = 30;
			break;

		};
		members[i].day = rand() % days;
		printf("\n\%s is born on %s, %d", members[i].name, m.name, members[i].day);

	}

	return 1;
}
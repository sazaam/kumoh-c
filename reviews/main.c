

#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES	// import Mathematic famous constants
#include <math.h>			// import Math lib

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



int exercise1(void);
int exercise2(void);
int show(int x, int y, int rows, int cols);

void main(void) {

	srand((unsigned)time(NULL));


	char spacing[20] = "\n\n\n";
	printf(spacing);


	// FIRST PART OF EXAM
	exercise1();

	// SECOND PART OF EXAM
	//exercise2();




	printf(spacing);
}


int exercise1(void) {

	int rows, cols;


	scanf_s("%d %d", &rows, &cols);


	int sum = show(rows, cols);
	printf("For a total of %d", sum);

}
int show(int x, int y, int rows, int cols) {
	int val, result = 0;

	int space = 32;

	int matrix[rows][cols];

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			matrix[i][j] = (i * cols) + j + 1;
		}
	}

	printf("\n\t�׵θ� ��Ҵ� ������ �����ϴ�.\n");


	//FIRST LOOP


	for (i = 0; i < ROWS; i++) {
		printf("\n\t");
		for (j = 0; j < COLS; j++) {
			val = matrix[i][j];
			printf("%d ", val);
		}
	}



	printf("\n\n\n");


	// SECOND LOOP

	for (i = 0; i < ROWS; i++) {
		printf("\n\t");
		for (j = 0; j < COLS; j++) {
			val = matrix[i][j];
			if (i % 2 == 0) {
				if (j % 2 == 1) {
					printf("%*c%d", val > 9 ? 0 : 2, space, val);
				}
				else {
					printf("%*c", 3, space);
				}
			}
			else {
				if (j % 3 == 0) {
					printf("%*c%d", val > 9 ? 0 : 2, space, val);
				}
				else {
					printf("%*c", 3, space);
				}
			}

		}
	}


	return result;
}





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

}
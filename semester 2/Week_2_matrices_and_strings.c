
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

Matrices => it's all about fine-tuning the logic behind the order of inputted data 

y & x (respectively row and columns data) coordinates
and in what order WE need to loop in order to make our calculations, 
i-e in respect of what coordinate we want our data processed and displayed.


*** BONUS ***
Strings in C are char arrays.
so arrays of strings logically become arrays of arrays of chars.

Similar order applies here as well, 
char[NUM_OF_STRINGS][LENGTH_OF_STRINGS] = {"str_1", "str_2"}


---- ALSO ------
remember to assign array variables (dynamically) through scan_f() with the &myarr[y][x] pointer assignment.
as in here :
// scanf_s("%d", &grades[j][i]);

*/


int Program(void) {


	/* Matrices */
	
	//StudentsGrades();
	
	//OtherGrades();


	/* Strings */
	Examples();

	return 0;
}

int Examples() {

	// assign a string variable to another will fail :

	char s1[10] = "Easy";
	char s2[10] = "Tiger";


	// will fail =>    s2 = s1;

	// instead
	strcpy(s1, s2);

	printf("%s", s1);
	printf("\n");
	
	printf("%d", strlen(s1)); // get actual length of inputted string

	char str1[80] = "allo maman tango charlie";
	char str2[80] = "coucou tonton sa va?";

	strcpy(str1 + 10, str2 + 8); // copying + some index will indeed copy and paste FROM that index ON.
	printf("\n%s", str1); // "allo maman" (until lengthindex = 10) + "onton sa va?"

	// concat
	char str3[80] = "Itaewon";
	char str4[80] = "Freedom";
	strcat(str3, str4);
	printf("\n%s\n", str3);


	char str5[80] = "cacaproutprout";

	char* ptr = strchr(str5, 'a');

	printf("\n%s\n", ptr);

	// strstr(); // acts as substr()

	return 0;
}


#define STUDENTS 2
#define COURSES 3

int OtherGrades() {

	char courses[COURSES][20] = {"Maths", "Python", "English"};
	char names[STUDENTS][20] = {"Samuel", "Cheolsu"};

	int grades[STUDENTS][COURSES] = { {10, 20 ,30}, {40, 50 ,60} };
	int row = 0, col = 0, total = 0;
	double av = 0;

	printf("Grades Per Student : \n");
	for (int j = 0; j < STUDENTS; j++) {
		printf("%s : \t\t\t", names[j]);
		total = 0;
		for (int i = 0; i < COURSES; i++) {
			total += grades[j][i];
		}
		av = total / COURSES;
		printf("\Total %d", total);
		printf("\t");
		printf("\Average %1.2f", av);

		printf("\n");
	}

	printf("\n");

	printf("Grades Per Course : \n");
	for (int j = 0; j < COURSES; j++) {
		printf("%s : \t\t\t", courses[j]);
		total = 0;
		for (int i = 0; i < STUDENTS; i++) {
			total += grades[i][j];
		}
		av = total / STUDENTS;
		printf("\Total %d", total);
		printf("\t");
		printf("\Average %1.2f", av);

		printf("\n");
	}

	printf("\n");
	return 0;
}


/* MATRICES */


#define ROWS 2
#define COLS 3
#define N 20

int StudentsGrades() {

	char name[N];
	int row = 0, col = 0;
	double av = 0;


	int grades[ROWS][COLS] ;
	int total = 0;

	printf("Entering Student's name and grade");
	printf("\n\n");


	int results[COLS][ROWS] = { {0} };

	for (int j = 0; j < ROWS; j++) {
		printf("%d Name:", j + 1);
		scanf_s("%s", name, sizeof(name));

		for (int i = 0; i < COLS; i++) {
			printf(" Subject %d : \t", i+1);
			
			scanf_s("%d", &grades[j][i]);
			int res = grades[j][i];
			results[i][j] = res;
		}


		printf("\n");

		total = grades[j][0] + grades[j][1] + grades[j][2];
		av = total / COLS;
		printf("Student : %s , \t total %d \t average : %1.2f", name, total, av);
		

		printf("\n\n");
	}
	printf("Subject Results : \n");

	for (int i = 0; i < COLS; i++) {
		total = av = 0;
		for (int j = 0; j < ROWS; j++) {
			int res = results[i][j];
			total += res;
			av = total / ROWS;
		}
		printf("Subject : %d , \t total %d \t average : %1.2f", i+1, total, av);
		printf("\n");
	}

	printf("\n\n");
	return 0;

}


int main(void) {
	printf("Matrices !!! \n\n\n");
	Program();

	return 0;
}
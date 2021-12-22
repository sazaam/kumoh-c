
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #11 Project 1 -- This is the 'Array of Random Values' project

@mission:		Array of Random Values

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



/*

	Main Function

*/



///////////  STUDENT
//////////////////////////////////////
//////////////////////////////////////


#define MAX 100
#define MAX_SCORES 3

typedef struct STUDENT {

	char name[MAX];
	char gender;
	int sno;

	float res[MAX_SCORES];
} student;

int inputStudent(void);
float calcAverage(student s1);
int checkStudent(student s1, student s2);



///////////  SHAPES
//////////////////////////////////////
//////////////////////////////////////



#define MAX_SHAPES 3

typedef struct SHAPE {

	float width;
	float height;
	char type[10];

} shape;

int testRectangles(void);
int inputRectangle(shape * shapes);
char* getShapeType(shape sh);


//////////////////////////////////////
///////////  MAIN
//////////////////////////////////////

int main(void) {

	/////// student example
	// inputStudent() ;
	

	testRectangles();

	return 0;

}


//////////////////////////////////////
///////////  SHAPES HELPERS FUNCTIONS
//////////////////////////////////////


int testRectangles(void) {
	
	shape shapes[] = {
		{0, 0},
		{0, 0},
		{0, 0}
	};
	inputShapes(shapes);
	
	printShapes(shapes);
	
}

inputShapes(shape * shapes) {
	
	for (int i = 0; i < MAX_SHAPES; i++) {
		printf("\nPlease input width and height of shape #%d : \n\t", i + 1);
		scanf_s("%f %f", &shapes[i].width, &shapes[i].height);

		strcpy(shapes[i].type, getShapeType(shapes[i]));
	}

}


printShapes(shape* shapes) {

	for (int i = 0; i < MAX_SHAPES; i++) {
		printf("\n\t\t\tDimensions (%.2f, %.2f)\n\n", shapes[i].width, shapes[i].height);
		printf("\n\tThe shape #%d is a %s\n\n", i, shapes[i].type);
	}

}


char* getShapeType(shape sh) {

	return sh.width == sh.height ? "Square" : "Rectangle";
}




//////////////////////////////////////
///////////  STUDENT HELPERS FUNCTIONS
//////////////////////////////////////


int inputStudent(void) {

	student saz, ji;
	
	printf("\nstudent name : \n\t");
	gets(saz.name);
	//scanf_s("%s", &saz.name, MAX);			/////// scanf + %s IS TRICKY
	//while (getchar() != '\n');				/////// got fooled again ¤Ì¤Ì gets seems better
	
	printf("student gender (m/f) : \n\t");
	scanf_s("%c", &saz.gender, 2);

	printf("student number :\n\t");
	scanf_s("%d", &saz.sno);

	printf("Last three results\n\t");
	scanf_s("%f %f %f", &saz.res[0], &saz.res[1], &saz.res[2]);

	float av = calcAverage(saz);
	
	printf("\n\t%.2f", av);

	ji = saz;
	ji.gender = 'f';
	strcpy(ji.name, "ji");
	printf("\n\n");
	printf("\n\t%s ==>> %c", saz.name, saz.gender);
	printf("\n\t%s ==>> %c", ji.name, ji.gender);
	printf("\n\n");
	
	student class[] = { saz, ji };

	printf("are the same student %d", checkStudent(saz, ji));

	return 0;
};

float calcAverage(student s1) {
	float total = 0, av = 0;
	for (int i = 0; i < MAX_SCORES; i++) {
		total += s1.res[i];
	}

	return total / (float)MAX_SCORES;;
}


int checkStudent(student s1, student s2) {

	int n = 0;
	if (s1.name == s2.name) { n += 1; }
	if (s1.gender == s2.gender) { n += 1; }
	if (s1.sno == s2.sno) { n += 1; }
	if (s1.res == s2.res) { n += 1; }
	
	return n == 0;
};
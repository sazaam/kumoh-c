
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

#include <malloc.h>

/*

Scheduler Minproject Example
Writing/Reading Arrays of structs

*/


int Program(void) {

	//FileDataWriteExample();

	//FileQuoteFindUppercase();
	
	FileFruitsWriteExample();

	return 0;
}


struct Fruit {
	char name[20];
	int price, quantity;
};


int FileFruitsWriteExample() {
	const char* inp = "fruits_inp.dat";
	const char* out = "fruits_out.dat";

	struct Fruit fruits[20] = { 0 };

	FILE* finp = fopen(inp, "rt");
	FILE* fout = fopen(out, "wt");
	if (!(finp && fout)) { printf("Error Opening file: %s", inp); exit(1); }

	puts("Successfully Opened Files.");
	int i = 0;

	fprintf(fout, "Fruit \t Price \t\t Quantity \t Total \n");
	fprintf(fout, "------------------------------------------------------- \n");

	struct Fruit fruit;
	int tot;
	double avg;

	for (i = 0; i < 3; i++) {
		fruit = fruits[i];

		fscanf_s(finp, "%s %d %d", &fruit.name, sizeof(fruit.name), &fruit.price, &fruit.quantity);


		tot = fruit.price * fruit.quantity;
		fprintf(fout, "%s \t %3d \t\t %3d \t\t %3d \n", fruit.name, fruit.price, fruit.quantity, tot);
	}
	fprintf(fout, "------------------------------------------------------- \n");


	printf("Successfully Written\n");

	fclose(finp);
	fclose(fout);

	return 0;
}




int FileQuoteFindUppercase() {
	const char* inp = "quote.dat";

	FILE* finp = fopen(inp, "rt");
	if (!finp) { printf("Error Opening file: %s", inp); exit(1); }

	puts("Successfully Opened Quote Files.\n");
	int i = 0;
	//size_t n = 0;
	//char* quote;
	char q;

	//quote = malloc(1000);
	while ((q = fgetc(finp)) != EOF){
		//quote[n++] = (char)q;
		i += (q >= 'A' && q <= 'Z') ? 1 : 0; /// isupper(q)? ... => also works  [isdigit(q), etc... toupper(q),  tolower(q)]
		printf("%c", q);
	}
	puts("\n");
	printf("they are %d Uppercase Letters.\n", i);
	puts("");
	printf("Successfully Written\n");

	fclose(finp);
	
	return 0;
}









struct Student {
	char surname[20];
	char firstname[20];
	int grades[5];
};


int FileDataWriteExample() {
	const char* inp = "inp.dat";
	const char* out = "out.dat";
	
	struct Student students[20] = {0};

	FILE* finp = fopen(inp, "rt");
	FILE* fout = fopen(out, "wt");
	if (!(finp && fout)) { printf("Error Opening file: %s", inp); exit(1); }

	puts("Successfully Opened Files.");
	int i = 0;
	fprintf(fout, "===================================== \n");
	fprintf(fout, "Last \t First \t\t Kor \t Eng \t Maths\t \n");
	fprintf(fout, "------------------------------------- \n");

	struct Student student;
	int tot;
	double avg;

	for (i = 0; i < 3 ; i++) {
		student = students[i];
		
		fscanf_s(finp, "%s %s %d %d %d", &student.surname, sizeof(student.surname), &student.firstname, sizeof(student.firstname), &student.grades[0], &student.grades[1], &student.grades[2]);
		
		
		tot = student.grades[0] + student.grades[1] + student.grades[2];
		avg = tot / 3;
		fprintf(fout, "%s \t %s \t %3d \t %3d \t %3d \t %3d \t %7.3f \t \n", student.surname, student.firstname, student.grades[0], student.grades[1], student.grades[2], tot, avg);
	}
	fprintf(fout, "------------------------------------- \n");


	printf("Successfully Written\n");

	fclose(finp);
	fclose(fout);

	return 0;
}

int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}










/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #12 Project 1&2 -- This project covers Combination of Struct and Binary Read/Write Files (fread() and fwrite() functions)

@mission:		A Simple Read / Write Example of Rectangle Data into Binary Files

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <malloc.h>

/*

Reading and Writing Binary Files
Here, using Struct Objects for Data Representation

*/


int Program(void) {
	
	BinaryFileAndStructWrite();
	BinaryFileAndStructRead();

	return 0;
}




typedef struct {
	int left, top, right, bottom;
} RECT;

#define SIZE 2


int BinaryFileAndStructWrite() {
	
	puts("\n>>> Writing Rectangles in Binary File Example");

	const char* inp = "rect.dat";

	RECT rect[SIZE] = {0};
	int i = -1;

	while (++i < SIZE) {
		printf("Please Enter dimensions of Rectangle # %d (T, R, B, L) :", i);
		scanf_s("%d %d %d %d", &rect[i].top, &rect[i].right, &rect[i].bottom, &rect[i].left);
	}

	FILE* finp = fopen(inp, "wb");
	if (!(finp)) { printf("Error Opening file: %s", inp); exit(1); }
	
	puts("");

	/*
		METHOD #1 : Write all at once specifying Size of ALL elements (length) of array
	*/

	//fwrite(&rect, sizeof(RECT), SIZE, finp);
	
	
	/*
		OR METHOD #2 : we can also write one at a time, but beware, as fwrite() returns successful written entries, NOT length of all entries
	*/
	i = -1;

	while (++i < SIZE && fwrite(&rect[i], sizeof(RECT), 1, finp));

	fclose(finp);

	puts("WRITING :: Successfully Created File.");


	return 0;
}


int BinaryFileAndStructRead() {
	
	puts("\n>>> Reading Rectangles from Binary File Example");

	const char* inp = "rect.dat";

	FILE* finp = fopen(inp, "rb");
	if (!(finp)) { printf("Error Opening file: %s", inp); exit(1); }
	puts("READING :: Successfully Read File.");

	RECT rect[SIZE];
	int i = -1 ;
	
	/*
		Method #1 : use fread in a loop contexted to 1, i-e ensures reading until it the file is really over
	*/
	/*
	while (fread(&rect[(++i)], sizeof(RECT), 1, finp)) {
		printf("\n Rectangle #%d\t Top: %d, Right: %d, Bottom: %d, Left: %d", (i + 1), rect[i].top, rect[i].right, rect[i].bottom, rect[i].left);
	}
	*/

	/* 
		OR Methof #2 : read all file first > and create a data array THEN loop inside array for data display
	*/


	
	i = -1;
	fread(&rect, sizeof(RECT), SIZE, finp);
	while (++i < SIZE) {
		printf("\n Rectangle #%d\t Top: %d, Right: %d, Bottom: %d, Left: %d", (i + 1), rect[i].top, rect[i].right, rect[i].bottom, rect[i].left);
	}
	/**/

	puts("");
	fclose(finp);

	return 0;
}



int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}








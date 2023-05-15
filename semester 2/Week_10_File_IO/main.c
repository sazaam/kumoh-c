
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

	FileSaveExample();

	return 0;
}

int OpenExample() {
	const char * filepath = "aaa.txt";

	FILE* fp = fopen(filepath, "r");
	
	if (!fp) {
		printf("Error Opening file: %s", filepath);
		return 1;
	}

	puts("File is Opened");
	fclose(fp);

	return 0;
}

int ErrOpenExample() {
	const char* filepath = "aaa.txt";

	FILE* fp;
	errno_t err = fopen_s(&fp, filepath, "r");

	if (err) {
		printf("Error Opening file: %s err#%d", filepath, err);
		return 1;
	}

	puts("File is Opened");
	//fclose(fp);

	return 0;
}


int FileReadExample() {
	const char* filepath = "aaa.txt";

	FILE* fp = fopen(filepath, "r");
	int ch;

	if (!fp) {
		printf("Error Opening file: %s", filepath);
		return 1;
	}

	puts("File is Opened");

	while ((ch = fgetc(fp)) != EOF) putchar(ch); // READ EACH CHARACTER

	fclose(fp);

	return 0;
}



int FileWriteExample() {
	const char* filepath = "aaa.txt";

	FILE* fp = fopen(filepath, "w");

	char * str = "Banana";
	int i = 0 ;
	char ch;
	if (!fp) {
		printf("Error Opening file: %s", filepath);
		return 1;
	}

	puts("File is Opened");

	while ((ch = str[i++])!='\0') fputc(ch, fp); // WRITE EACH CHARACTER

	fputc('\n', fp);
	fclose(fp);

	return 0;
}


int FileSCANFExample() {
	const char* filepath = "nums.txt";

	FILE* fp = fopen(filepath, "rt");
	int n1, n2, n3;

	if (!fp) {
		printf("Error Opening file: %s", filepath);
		return 1;
	}
	puts("File is Opened");

	while (EOF != fscanf_s(fp, "%d %d %d ", &n1, &n2, &n3)) {
		printf("%d %d %d \n", n1, n2, n3);
	}

	fclose(fp);

	return 0;
}


int FileTXTStringExample() {
	const char* filepath = "insa.txt";
	

	FILE* fp = fopen(filepath, "r");
	if (!fp) { printf("Error Opening file: %s", filepath); return 1; }
	
	
	
	const char insa[80] = "";
	int wordbyword = 0;
	
start:
	printf("Do you want it word by word (1) or line by line(2) :");
	scanf("%d", &wordbyword);

	switch (wordbyword){
	case 1:
		while (fscanf_s(fp, "%s", insa, sizeof(insa)) != EOF) {
			printf("%s \n", insa);
		}
		goto start;
	case 2:
		while (fgets(insa, sizeof(insa), fp)) {
			printf("%s", insa);
		}
		goto start;
	}
	fclose(fp);
	puts("");
	puts("Program will terminate now.");
	return 0;

	return 0;
}



int FileSaveExample() {
	const char* filepath = "save.txt";

	char sts[50];
	int i;

	FILE* fp = fopen(filepath, "w");
	if (!fp) { printf("Error Opening file: %s", filepath); return 1; }

	puts("save file created.");
	
	printf("1. Enter phrase:");
	gets_s(sts, sizeof(sts));

	printf("2. Saved into file : %s\n", sts);

	for (i = 0; (sts[i]!=NULL) ; i++) {
		fputc(sts[i], fp);
	}

	fclose(fp);
	puts("File Saved");
	puts("Program will terminate now.");
	return 0;

	return 0;
}



int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}










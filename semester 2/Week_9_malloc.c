
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


	// Exercise #1
	//MallocExample1();

	// Exercise #2
	// MallocExample2();

	// Exercise #3
	StrMallocExample1();

	return 0;
}



int StrMallocExample1() {

	// This format works :
	// char *pa[2] = { "Study", "Academy" };
	// just as (but better since no string length spcification -> adjustable)...
	// char pa[2][8] = { "Study", "Academy" };
	
	
	char* task[] = {
		"Office",
		"Laundry",
		"Dinner",
		"Carwash",
		"Kids Leasure"
	};
	// No errors + variating accurate number of characters for strings
	// In declaration, omitting length is also OK but not if full array is not declared at the same time;
	// char* task[] ; will fail >> does not know how many there will / could be...
	// 
	// will not write anything else in the string than necessary characters + \0


	int act;
	
	int i, size = sizeof(task) / sizeof(task[0]);

	//Adding a new Task
	task[size] = "Take Girly Out";
	size++;

	for (i = 0; i < size; i++) {
		printf("%s \n", task[i]);
	}
	
start:
	
	puts("");
	printf("what do you want to see (%d to close):", size+1);
	scanf("%d", &act);

	if (act == size + 1) {
		puts("Terminate");
		free(task);
		return 0;
	}

	if (act > 0 && act < size + 1)
		printf("The task you asked to see is : %s.\n", task[act - 1]);
	else
		printf("Wrong input...");


	goto start;

	return 0;
}


int MallocExample2() {

	int* p;
	int i, data, total = 0, cnt = 1;

	p = (int*)malloc(sizeof(int) * cnt);

	printf("#1 ? ");
	scanf("%d", &p[0]);

	for (i = ++cnt;; i++) {
		printf("#%d ? ", i);
		scanf("%d", &data);

		if (data) {
			p = (int*)realloc(p, sizeof(int) * i );
		} else {
			break;
		}
		p[i-1] = data;
	}

	for (i = 0; i < cnt + 1; i++) {
		// printf("#%d ? %d", i, p[i]); // check every entry of array
		total += p[i];
	}

	printf("total = %d", total);

	free(p);

	return 0;
}


int MallocExample1() {

	int* p;

	int i, cnt, total = 0;


	printf("How many do you want?");

	scanf("%d", &cnt);

	p = (int*) malloc(sizeof(int) * cnt);

	for (i = 0; i < cnt; i++) {
		printf("#%d : ", i+1);
		scanf("%d", (p + i));

	}

	for (i = 0; i < cnt; i++) {
		total += p[i];
	}

	printf("total = %d", total);




	// if want to re-alloc size of existing pointer
	// p = (int*) realloc(p, sizeof(int)+newcount);

	// if you want to allocate with default value
	// s = (int*) calloc(sizeof(int), newcount);

	// IMPORTANT garbage collector passes before rest of program...
	free(p);

	return 0;
}




int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}












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

Structs => it's important to remember the nuances between references and pointers

in c, assigning a struct instance into a variable such as in :
	struct Person p = people[i];
	will hard copy people[i] into a new Person instance, 
	which also means that writing onto this new datablock will never reach the actual people[i] instance.

	for that 'pointing' the access via pointer is necessary, as in :
	struct Person * p = &people[i];
	which also means from now on accessing its properties will have to go through the arrow ('->prop') notation and no longer the point ('.prop') notation

	in order to avoid that, we can always access people[i] by naming it explicitly.


*/


int Program(void) {

	// People();
	// Inventory();
	Coordinates();
	return 0;
}


int absolute(int a) { return a > 0 ? a : -a; }

struct Coords {
	int x, y;
};

#define COORDS 2
int Coordinates() {

	struct Coords coords[COORDS] = {
		{0, 0},{0,0}
	};

start:
	printf("Please Input first set of Coordinates (X Y) :");
	scanf_s("%d %d", &coords[0].x, &coords[0].y);
	printf("\n");
	printf("Please Input second set of Coordinates (X Y) :");
	scanf_s("%d %d", &coords[1].x, &coords[1].y);
	printf("\n");

	struct Coords c1 = coords[0], c2 = coords[1];
	
	if (c1.x | c1.y | c2.x | c2.y) {
		struct Coords cDiff = { absolute(c2.x - c1.x), absolute(c2.y - c1.y) };

		printf("The difference in X is %d , and in Y is %d \n", cDiff.x, cDiff.y);
		goto start;
	}

	puts("Program will terminate now.");

	return 0;

}



struct InventoryItem {
	char name[40];
	int quantity, price, total;
};

#define ITEMS 3
int Inventory() {

	struct InventoryItem items[ITEMS] = {
		{"Computer", 8, 155},
		{"Monitor", 6, 89},
		{"Keyboard", 7, 23}
	};

	int i = 0, l = ITEMS;

	printf("[%s \t\t%s \t%s \t%s ]\n", "Name", "Amount", "Price", "Total");
	for (i = 0; i < l; i++) {
		struct InventoryItem item = items[i];
		item.total = item.price * item.quantity;
		printf("  %s \t%d \t%d \t%d \n", item.name, item.quantity, item.price, item.total);
	}

	return 0;
}



struct Person {
	char name[40];
	int height;
	double weight;
	int age;
	double bmi;
};


double cal_BMI(struct Person* p) {
	double w = p->weight;
	double ki = ((double)p->height * .01);
	p->bmi = p->weight / (ki * ki);
	return p->bmi;
}

#define POPULATION 5
int People() {

	struct Person ppl[POPULATION] = {
		{"Jung", 175, 70.0},
		{"Park", 165, 38.7},
		{"Lee", 150, 60.0},
		{"Shin", 150, 32.7},
		{"Kim", 155, 28.9}
	};

	int i = 0, l = POPULATION;


	int tallest = 0, h_ind = 0;
	int lightest = 0;
	double w_ind = 500;

	for (i = 0; i < l; i++) {
		struct Person* p = &ppl[i];
		int h = p->height;
		double w = p->weight;
		if (h > h_ind) {
			tallest = i;
			h_ind = h;
		}
		if (w < w_ind) {
			lightest = i;
			w_ind = w;
		}
		cal_BMI(p);
		printf("%s %d %1.1f \n", p->name, p->height, p->weight);
	}
	puts("");
	printf("%s is the tallest person\n", ppl[tallest].name);
	printf("%s is the lightest person\n", ppl[lightest].name);
	puts("");

	for (int i = 0; i < l; i++) {
		struct Person* p = &ppl[i];
		printf("%s's BMI is %1.1f \n", p->name, p->bmi);
	}

	return 0;
}



int main(void) {
	printf("Exercises Start !!! \n\n\n");
	Program();

	return 0;
}

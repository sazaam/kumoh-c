
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

	
	Inventory();
	
	return 0;
}




#define ITEMS 10
struct InventoryItem {
	char name[40];
	double price, discount,  priceafter;
};

enum Actions { View = 1, Change, Add, Delete, Close };



double calcDiscount(double price, double discount) {
	return price - (price / 100 * discount);
}

void displayMenu() {

	puts("--------------- Week Scheduler ----------------\n");

	puts("  1 : View Products Info.");
	puts("  2 : Change a Discount.");
	puts("  3 : Add a Product.");
	puts("  4 : Remove a Product.");
	puts("  5 : Terminate Program.");

}
void createProduct(struct InventoryItem* item, char* name, double price, double discount) {
	strcpy(item->name, name);
	
	item->price = price;
	item->discount = discount;
	item->priceafter = calcDiscount(price, discount);
}

void addProduct(struct InventoryItem products[], char* name, double price, double discount) {
	
	int i = 0, l = ITEMS;
	struct InventoryItem item;
	for (i = 0; i < l; i++) {
		item = products[i];
		if (item.price == 0.0) {
			createProduct(&products[i], name, price, discount, price);
			break;
		}
	}
	

}

///////////////// REMOVES
void clearProduct(struct InventoryItem* item) {

	strcpy(item->name, "");
	item->price = 0.0;
	item->discount = 0.0;
	item->priceafter = 0.0;

}

void deleteProduct(struct InventoryItem products[], char * name) {
	
	int i = 0, l = ITEMS;
	struct InventoryItem item;
	for (i = 0; i < l; i++) {
		item = products[i];
		if (strcmp(item.name, name) == 0) {
			clearProduct(&products[i]);
			break;
		}
	}
	printf("Successfully Removed Event : %s \n", item.name);
	puts("");
}

void updateProduct(struct InventoryItem* item, double discount) {
	item->discount = discount;
	item->priceafter = calcDiscount(item->price, discount);
}
void modifyProduct(struct InventoryItem products[], char* name, double discount) {

	int i = 0, l = ITEMS;
	struct InventoryItem item;
	for (i = 0; i < l; i++) {
		item = products[i];
		printf("COMPARING %s %s %d", name, item.name, strcmp(item.name, name) == 0);
		if (strcmp(item.name, name) == 0) {
			updateProduct(&products[i], discount);
			break;
		}
	}
	printf("Successfully Updated Event Discount: %s \n", item.name);
	puts("");
}

void viewProducts(struct InventoryItem products[]) {

	printf("[%s \t\t%s \t%s \t%s ]\n", "Name", "Unit Price", "Discount", "Price After Discount");
	int i = 0, l = ITEMS;
	for (i = 0; i < l; i++) {
		struct InventoryItem item = products[i];
		if(item.price != 0) printf("  %s \t%1.2f \t%1.2f \t\t%1.2f \n", item.name, item.price, item.discount, item.priceafter);
	}

}

void addFixtures(struct InventoryItem products[]) {

	// Fixtures
	addProduct(products, "Crayon", 2000, 10);
	addProduct(products, "Notes", 1000, 25);
	addProduct(products, "Paint	", 12000, 15);

}


int Inventory() {

	struct InventoryItem products[ITEMS] = { 0 };

	addFixtures(products);


start:

	displayMenu();


	int action = 0;

	puts("");
	printf("Please Select Action :");
	scanf_s("%d", &action);
	puts("");


	char prname[100] = "Bicycle";
	int price = 17, discount = 2;


	switch (action) {
	case View:
		viewProducts(products);
		break;
	case Add:

		printf("Please inform Product's Name : ");
		scanf(" %100[0-9a-zA-Z ]", &prname); // In Order to have Spaces allowed in string

		while (getchar() != '\n');


		printf("Please inform Product's price and discount : ");
		scanf(" %d %d", &price, &discount);

		

		addProduct(products, prname, (double) price, (double) discount);
		
		break;
	case Change:

		printf("Please inform Product's Name : ");
		scanf(" %100[0-9a-zA-Z ]", &prname); // In Order to have Spaces allowed in string

		while (getchar() != '\n');


		printf("Please inform Product's new discount : ");
		scanf(" %d", &discount);



		modifyProduct(products, prname, (double)discount);

		break;
	case Delete:

		printf("Please inform Product's Name : ");
		scanf(" %100[0-9a-zA-Z ]", &prname); // In Order to have Spaces allowed in string

		while (getchar() != '\n');

		/**/

		deleteProduct(products, prname);

		break;
	case Close:
		puts("Program will terminate now.");
		return 0;
	default:
		puts("Wrong Input, Please input again...");
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

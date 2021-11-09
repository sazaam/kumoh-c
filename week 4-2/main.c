
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #4 Project 2 -- This project covers the use of Switch ~ Case

@mission:		A Simple Switch-Case Example

*/




/*

This program can find the accurate name-rank for each floor from 1~10th Floor
	Primary Mission :
		- rank each floor and name it!
	Secundary Mission:
		- X
	Bonus Mission :
		- X
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_FLOORS 10

/*

		First Method that comes to mind...

*/
int firstMethod(void) {

	// initialize
	int floor = 0, index = -1, forbidden = 1; // setting all floors to forbidden by default
	char* log = ""; // Our ouputted String


	// Require Input from User
	printf("\t1~10 ������ �Է��� �ּ��� : \n");

	scanf_s("%d", &floor);
	
	// Now only allow a range of floors defined by MAX_FLOORS
	index = (floor < MAX_FLOORS + 1) ? floor : index;
	forbidden = (index == -1 || index == 0);

	switch (index) {
		// two forbidden cases first
	case -1:
	case 0:
		log = (floor) ? "�߸� �Է��ϼ̽��ϴ�." : "���α׷��� �����մϴ�.";
		break;
		// grouping lower floors
	case 1:
	case 2:
	case 3:
		log = "����";
		break;
		// grouping upper floors
	case 8:
	case 9:
	case 10:
		log = "����";
		break;
		// case for all remaining floors
	default:
		log = "�ξ���";
		break;
	}

	if (forbidden) { // printing different result strings for forbidden
		printf("\n\t\t%s\n", log);
	}
	else {
		printf("\n\t\t>>> %d%c���� %s �Դϴ�.\n", floor, 32, log);
	}

	return 0;
}


/*

		This Second Method shall be better Looking...

*/
int secondMethod(void) {

	// initialize
	int floor = 0, index = -1; // setting all floors to forbidden by default
	int cat;
	char* name;
	

	// Require Input from User
	printf("\t1~10 ������ �Է��� �ּ��� : \n");

	scanf_s("%d", &floor);
	printf("\n\t����: %d\n", floor); // Log the Entered Floor Number


	

	index = (floor < MAX_FLOORS + 1) ? floor : index;
	

	switch (index) {
	case 1: case 2: case 3:
		cat = 1;
		name = "��";
		break;
		// grouping upper floors
	case 8: case 9: case 10:
		cat = 3;
		name = "��";
		break;
		// case for all remaining floors
	case -1: case 0:
		cat = 0;
		name = "�߸�";
		break;
	default:
		cat = 2;
		name = "�ξ�";
		break;
	}


	// Now we have a clean way of handling only correct or errored floors entries
	switch (cat) {
	case 1: case 2:case 3:
		printf("\n\t\t>>> %d%c���� %s���Դϴ�.\n", floor, 32, name);
		break;
	default:
		printf("\n\t\t>>> %s\n", floor != 0 ? "�߸� �Է��ϼ̽��ϴ�." : "���α׷��� �����մϴ�.");
		break;
	}


	return 0;
}



int main(void) {

	int i;
	int max_tries;
	
	
	// First Method
	
	printf("\n\n\n");
	printf("\t���α׷��� �� �� �������� �� ���ðڽ��ϱ�? : \n");
	scanf_s("%d", &max_tries);
	
	for(i = 0 ; i < max_tries; i ++)
		firstMethod();

	
	// Second Method
	
	printf("\n\n\n");
	printf("\t���α׷��� �� �� �������� �� ���ðڽ��ϱ�? : \n");
	scanf_s("%d", &max_tries);
	
	for(i = 0; i < max_tries; i++)
		secondMethod();
	


	printf("\n\n\n");

	return 0;
}

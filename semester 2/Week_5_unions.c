
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

Define & enums
Unions : Unions are just for easily store different types of data under one item i-e group different datas together


*/



int Program(void) {

	//EnumExample();

	//UnionExample();
	
	UnionDemo();


	return 0;
}





typedef struct Person {
	char name[20];
	int age;
	double height;
};


union Student {
	struct Person p;
	char id[20];
	int year, major;
};


enum majors {IT, Medic, Arch, Lang, Soc, Math, Phys, Bio, Gen};


int UnionExample() {

	struct Person people[2] = { {"Saz", 40, 175}, {"Toto", 40, 175}, };
	struct Person saz = people[0];

	union Student students[2] = {
		{ &people[0] , "20211314", 2, 0},
		{ &people[0] , "20211314", 6, 3}
	};



	return 0;
}


union Demo {
	char c;
	int i;
};
union Mate {
	char surname[20], gender;
};

int UnionDemo() {


	/// Example 1


	/*union Demo d = {0};
	printf("Size of Demo union : %d \n", sizeof(d));
	d.c = 'A';
	printf("d.c :(char)%c (size10) %d / d.i:%08d \n", d.c, d.c, d.i);
	d.i = 66;
	printf("d.c :(char)%c (size10) %d / d.i:%08d \n", d.c, d.c, d.i);
	*/

	/// Example 2 (FAILS)

	union Mate p;
	p.gender = 'G';
	strcpy(p.surname, "KIM");
	
	printf("%c\n", p.gender);
	puts(p.surname);
	
	//  Overwrites if similar types Strings or char are stored


	/// Example 3
	#define MONTHS 12
	enum mnames{JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int m;
	
start:
	printf("Please enter a month number: \n");
	scanf_s("%d", &m);
	
	if (m < 1 || m > MONTHS) {
		printf("Please enter again. \n");
		goto start;
	}
	
	printf("The month you chose is %s\n", months[m-1]);



	return 0;
}



#define MAX 100
#define MIN 0

int EnumExample() {

	typedef enum week {SUN, MON, TUE, WED, THU, FRI, SAT};
	typedef enum familyname {KIM=100, LEE, PARK, JUNG, HONG, JANG, CHOI, SONG, HWANG, OH, GONG, KANG, SEO} Fname;

	Fname n = JUNG;

	printf("MAX = %d, MIN=%d \n", MAX, MIN);
	printf("SUN = %d\n", SUN);
	printf("MON = %d\n", MON);
	printf("TUE = %d\n", TUE);
	printf("WED = %d\n", WED);
	printf("THU = %d\n", THU);
	printf("FRI = %d\n", FRI);
	printf("SAT = %d\n", SAT);
	printf("JUNG is #%d.\n", n);

	return 0;

}



int main(void) {
	printf("Exercises Start !!! \n\n\n");
	Program();

	return 0;
}

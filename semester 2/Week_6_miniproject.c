
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

Scheduler Minproject Example
Writing/Reading Arrays of structs

*/


int Program(void) {
	MiniProject();
	return 0;
}





////////////////////// CLASS DEFINITIONS
typedef struct Event {
	char name[100];
	int day;
	double start, duration;
};

#define DAYS 7
#define HOURS 24


enum Actions { View = 1, Add, Remove, Close };
static char DNAMES[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };




/////////////////////// HELPERS
double hours2float(double t) {
	int h = (int)t;
	double m = t - h;
	if (m == 0) return t;
	else return (double) (h + m * 100 / 60);
}
double float2hours(double t) {
	int h = (int)t;
	double m = t - h;
	if (m == 0) return t;
	else return (double)(h + m * 60 / 100);
}
char* getDayName(int n) {
	return DNAMES[n];
}
int getDayNum(char s[]) {
	for (int i = 0; i < 7; i++) {
		if (strcmp(DNAMES[i] , s)) return i;
	}
}
int checkEventExists(struct Event* ev) {
	return ev->duration > 0.0;
}

////////////////// ADDS
void createEvent(struct Event* ev, char *name, int day, double time, double dur) {
	strcpy(ev->name,name);
	ev->day = day;
	ev->start = time;
	ev->duration = dur;
}



void addEvent(struct Event evs[], char* name, int day, double time, double dur) {

	int n = (day*24) + (int) time;
	int cond = 0;
	struct Event* ev = &evs[n];
	for (int i = 0; i < (int)dur; i++) {
		ev = &evs[n + i];
		cond |= checkEventExists(ev);
	}

	if (cond) {
		puts("\tCannot create Event, as another Event is planned at that time...");
		printf("\tPlease Remove event occurring %s at %1.2f...\n", DNAMES[ev->day], ev->start);
		return;
	}

	for (int i = 0; i < (int) dur ; i++) {
		createEvent(&evs[n+i], name, day, time, dur);
	}

}


////////////////// REMOVES
void clearEvent(struct Event* ev) {

	strcpy(ev->name, "");
	ev->day = 0;
	ev->start = 0.0;
	ev->duration = 0.0;

}

void removeEvent(struct Event evs[], int day, double time) {
	int n = (day * 24) + (int) time;
	int cond = 0;
	struct Event* ev = &evs[n];
	double dur = (int) ev->duration;

	for (int i = 0; i < (int)dur; i++) {
		ev = &evs[n + i];
		cond |= checkEventExists(ev);
	}
	
	if (!cond) {
		puts("\tYour schedule is already free at that time...");
		return;
	}

	printf("Removed Event : %s \n", ev->name);
	for (int i = 0; i < (int)dur; i++) {
		clearEvent(&evs[n+i]);
	}
	puts("");
}

////////////////// DISPLAYS
void showEvent(struct Event* ev) {
	printf("\t%s : Start Time : %1.2f , Duration : %1.2f\n", ev->name, ev->start, ev->duration);
}

void viewEvents(struct Event evs[], int total) {

	puts("\t\t ~~ Weekly Events ~~\n");

	struct Event* ev;
	int day = -1;
	double start = -1.0;
	for (int i = 0; i < total; i++) {

		ev = &evs[i];

		if (ev->duration > 0) { // the event is printable

			int daycond = (ev->day != day);
			int diffcond = daycond || start != ev->start;

			if (diffcond) {
				if (daycond) printf("=> %s", DNAMES[ev->day]);
				showEvent(ev);
			}
			start = ev->start;
			day = ev->day;
		};
		
	}
}


displayMenu() {
	puts("--------------- Week Scheduler ----------------\n");

	puts("  1 : View the Weeek's schedule.");
	puts("  2 : Add an Event.");
	puts("  3 : Remove an Event.");
	puts("  4 : Terminate Program.");

}

addFixtures(struct Event evs[]) {

	// Fixtures
	addEvent(evs, "C Prog", 0, 13, 2);
	addEvent(evs, "Sport", 1, 11, 2);
	addEvent(evs, "Design Modelling", 2, 15, 2);
	addEvent(evs, "English Practice", 3, 10, 2);
	addEvent(evs, "Friends Meetings", 4, 18, 3);
	addEvent(evs, "School Trip", 5, 11, 6);
	addEvent(evs, "Bicycle", 6, 15, 2);
}

int MiniProject() {

	static struct Event weekEvts[168] = { 0 };

	//printf("fl2Hours :%1.2f \n", float2hours(1.5));
	//printf("Hours2Fl :%1.2f \n", hours2float(1.3));


	addFixtures(weekEvts);

	/*
	printf("find Day 'Mon' %d : ", getDayNum("MON"));
	printf("find Day 6 %s : ", getDayName(6));
	*/

start:
	
	displayMenu();


	int action = 0;

	puts("");
	printf("Please Select Action :");
	scanf_s("%d", &action);
	puts("");


	switch (action) {
	case View:
		viewEvents(weekEvts, 168);
		break;
	case Add:
		addEvent(weekEvts, "A new One", 0, 17, 2);
		break;
	case Remove:
		removeEvent(weekEvts, 0, 13);
		break;
	case Close:
		puts("Program will terminate now.");
		return 0;
	default:
		puts("Please input again...");
	}
	puts("");
	goto start;

	return 0;
}


int main(void) {
	printf("MiniProject Starts !!! \n\n\n");
	Program();

	return 0;
}

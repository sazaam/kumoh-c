
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #6 MiniProject >> This project covers Arrays of struct Type Declarations

@mission:		A Simple Scheduler
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Scheduler Miniproject Example
Writing/Reading Arrays of structs



In this project I made several choices, in order to have a smart application use :
	- for clarity reasons, i store event duration instead of event finish_time (meaning duration = 2 hours instead of end time = 17h)
	- other upgrades all concern the following possibilities :
		- having events at any hour of the day,
		- having events crossing from one day to the next,
		- having multiple events for the same day,
		- making the checking of already existing events when writing/deleting  
		- thus, having as many events as all hours included in a week (full schedule), but with safety of no inter-crossings.

I thought ahead and directly implemented Hours as floats in order to have events at potentially each quarter of hours (like 15:30), 
but that would have complexified the code a lot and make the array enormous, if following the already-applied logic.
Practically, that could be still be achieved in a smarter way in the future version of the project.

Synopsis of this Program's interface : 
- Entering Array of Events could be easily implemented (apply multiple events at once such as the 'addFixtures' function) within a loop;
- Entering a new Event checks if an other event shares similar time-frame and rejects the saving, encouraging to use a delete event instead;
- Clearing an event requires to be existing in the first place, and is made in an user-friendly attempt :
	- First asks for the day of the event (to filter and display a reminder list),
	- Then offers to delete Event by Start time (instead of name, or multiple necessary indications).


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
	else return (double)(h + m * 100 / 60);
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
		if (strcmp(DNAMES[i], s) == 0) return i;
	}
}
int checkEventExists(struct Event* ev) {
	return ev->duration > 0.0;
}

////////////////// ADDS
void createEvent(struct Event* ev, char* name, int day, double time, double dur) {
	strcpy(ev->name, name);
	ev->day = day;
	ev->start = time;
	ev->duration = dur;
}



void addEvent(struct Event evs[], char* name, int day, double time, double dur) {

	int n = (day * 24) + (int)time;
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

	for (int i = 0; i < (int)dur; i++) {
		createEvent(&evs[n + i], name, day, time, dur);
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
	int n = (day * 24) + (int)time;
	int cond = 0;
	struct Event* ev = &evs[n];
	double dur = (int)ev->duration;

	for (int i = 0; i < (int)dur; i++) {
		ev = &evs[n + i];
		cond |= checkEventExists(ev);
	}

	if (!cond) {
		puts("\tYour schedule is already free at that time...");
		return;
	}

	printf("Successfully Removed Event : %s \n", ev->name);
	for (int i = 0; i < (int)dur; i++) {
		clearEvent(&evs[n + i]);
	}
	puts("");
}

////////////////// DISPLAYS
void showEvent(struct Event* ev) {
	printf("\t%s : Start Time : %1.2f , Duration : %1.2f\n", ev->name, ev->start, ev->duration);
}

void viewEvents(struct Event evs[], int total, int focusday) {

	if(focusday == -10) puts("\t\t ~~ Weekly Events ~~\n");

	struct Event* ev;
	int day = -1;
	double start = -1.0;
	for (int i = 0; i < total; i++) {

		ev = &evs[i];

		if (ev->duration > 0) { // the event is printable

			int daycond = (ev->day != day);
			int diffcond = daycond || start != ev->start;

			if (diffcond) {
				if (daycond) {
					if (focusday != -10) {
						if (day == focusday) printf("=> %s", DNAMES[ev->day]);
					}else printf("=> %s", DNAMES[ev->day]);
				}
				if (focusday != -10) {
					if(day == focusday) showEvent(ev);
				}else showEvent(ev);
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

	
	//printf("find Day 'Mon' %d : ", getDayNum("MON"));
	//printf("find Day 6 %s : ", getDayName(6));
	

start:

	displayMenu();


	int action = 0;

	puts("");
	printf("Please Select Action :");
	scanf_s("%d", &action);
	puts("");

	
	
	char evname[100] = "Repair Bicycle", evday[4] = "MON";
	int evstart = 17, evdur = 2;
	
	
	switch (action) {
	case View:
		viewEvents(weekEvts, 168, -10);
		break;
	case Add:

		//printf("Please inform Event's Name :");
		//scanf_s(" %s", &evname, 100); // TRIMMING SPACE SCAN_F ISSUE -> # HACK // THIS WAS NOT SO COOL
		//while (getchar() != '\n');

		printf("Please inform Event's Name : ");
		scanf(" %100[0-9a-zA-Z ]", &evname); // In Order to have Spaces allowed in string

		while (getchar() != '\n');

		printf("Please inform day, start and end time: ");
		scanf(" %s %d %d", &evday, &evstart, &evdur);

		/*
		printf("Please inform name, day, start and end time:");
		scanf("%s %s %d %d",&evname, &evday,  &evstart, &evdur);
		*/


		addEvent(weekEvts, evname, getDayNum(evday), evstart, evdur);
		
		break;
	case Remove:

		
		printf("Please Select Event's Day (MON-SUN): ");
		scanf(" %s", &evday);

		/**/

		puts("");
		viewEvents(weekEvts, 168, getDayNum(evday) -1);
		puts("");

		printf("Please Select Event's Start Time to remove it (-1 to cancel): ");
		scanf(" %d", &evstart);

		if(evstart != -1) removeEvent(weekEvts, getDayNum(evday), evstart);

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

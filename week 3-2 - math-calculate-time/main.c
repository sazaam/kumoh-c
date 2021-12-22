

/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week#3 Project 2 -- This project covers Calculations, Byteshifting and Number Datatypes Casting

@mission:		A Simple Seconds to Time Converting Program

*/




/*

This program converts given number of seconds into Months/Weeks/Days/Hours/Minutes/Seconds format.
	
	--> Good Number to test ::: 6456456 (gives many values such as months, weeks, days that passed)...

	 - Let's remember : if an 160 seconds passed, 
		the format should NOT be 2 Minutes - 160 Sec
		format should be 2 Minutes - (160 - 60*2 ) Sec  ==>  2 Minutes 40 Seconds
		Same goes for everything > 3 days and 2 Hours passed, NOT 3 days and 75 Hours.

		OTHER VALUES
	--> Good Number to try ::: 0

		REFERENCES
	--> 29030400		== 1 Year (3600*24*7*4*12)
	--> 2419200			== 1 Month (3600*24*7*4)
	--> 604800			== 1 Week (3600*24*7)
	--> 86400			== 1 Day (3600*24*7)
	
	--> 116121600		== 4 Years (3600*24*7*4*12*4)
	--> 7335189			== 3 Months, 21 Hours, 33 Min, 9 Sec
	--> 123456789 = 116121600 + 7335189
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void calcMonths(int d, int* month, int* day) {

	int m = 12;
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 0;
	for (; i < m; i++) {
		int mm = months[i];
		if(d-mm >=0) d -= mm;
		else break;
	}
	*month = i;
	*day = d - 1;
}


int main(void) {


	printf("\n\n\n");
	
	time_t result = time(NULL);
	intmax_t seconds = (intmax_t) result;

	printf("Please Enter Number of Seconds : ");
	
	scanf_s("%jd", &seconds);
	
	int secret = 0;

	if (!seconds) { // SECRET !!! if user input is 0 --->> get seconds since "the Epoch"
		secret = 1;
		seconds = (intmax_t)result;
		printf("\nYou found a Secret !! Seconds since Year 0 :\n\t Tuesday Jan 20 1970 06:15:26 GMT+0900 :\n\t %jd\n", seconds);
	} else {
		printf("\nNumber of seconds is %jd.", seconds);
	}

	printf("\n\n");
	
	
	int secs = (int)seconds; // convert to int

	int d, m, s;

	int rem_secs = secs % 60; // finding what remain is what modulo is used for
	int perf_secs = secs - rem_secs; // deducing seconds that should be counted as minutes (60-packs)
	
	int mins = perf_secs / 60; // the same method can apply to the other conversions
	int rem_mins = mins % 60;
	int perf_mins = mins - rem_mins;

	int hours = perf_mins / 60;
	int rem_hours = (hours + (secret ? 9 : 0)) % 24; // Jet Lag (Korean Time = GMT+0900)
	
	int perf_hours = hours - rem_hours;

	int days = hours / 24;
	int rem_days = days % 365;
	int perf_days = days - rem_days;



	int years = days / 365;
	
	int month, day, weeks;
	
	if (secret) {
		int yy = years - 2;								// 1970 was not leap year, 1972 was the first leap year
		int leap_years_fix = (yy - (yy % 4)) / 4;		// since 1972, how many years were leap years, 
		rem_days -= leap_years_fix;						// remove 1 day per leap year in remaining days
		perf_days += leap_years_fix;					// add 1 day per leap year in passed days

		calcMonths(rem_days, &month, &day);
	}
	


	printf("seconds passed: %d\n", rem_secs);
	printf("minutes passed: %d\n", rem_mins);
	printf("hours passed: %d\n", rem_hours);
	
	
	if (secret) {
		printf("days passed: %d\n", day);
		printf("months passed: %d\n", month);
		printf("years passed: %d\n", 1970 + years);

		printf("\ncurrent date : %d / %d / %d\n", 1970 + years, month + 1, day + 1);
		printf("current time : %d : %d : %d\n", rem_hours, rem_mins, rem_secs);

	}else {
		weeks = days / 7;
		month = weeks / 4;
		years = month / 12;
		printf("days passed: %d\n", days - (weeks * 7));
		printf("weeks passed: %d\n", weeks - (month * 4));
		printf("months passed: %d\n", month - (years * 12));
		printf("years passed: %d\n", years);
	}
	



	printf("\n\n\n");


	printf("total number of second multiplied by 2 : %lu\n", (unsigned long)((int)(secs << 1))); 
	/// if ZERO was entered the number of seconds may be extremely large
	// first need to cast into (int) for the x2 byteshift operation, 
	// then need to cast the result into (unsigned long) in order to be allocated correctly.
	
	
	printf("\n\n\n");
	

	return 0;
}
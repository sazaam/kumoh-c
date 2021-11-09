/*

@author		> sazaam (sazaam@gmail.com)
			> github.com/sazaam/
@version	> 0.0.1

@desc		> Third Project - 2nd Week / 'Data Handling' Mission

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	Average Grades Calculations Challenge

		GOAL :
			- input : each respective grades for Korean, English and Math Classes
			- program : the calculation of the Average Grade for the semester / student
			- output : the total cumulated points AND the average grade out of 100 points

		BONUS TASK :
			- Try using Array of Courses and for-Loop, instead of hardcoded courses
			- Have the user input it (with help from scanf)
			- Transfer the result into an 'A~F' Grading system
			- Post a comment about it

		- Pre-assumables :
			- each discipline's scores are 100 points based.
			- user-input scores should be accepted as floats, 
			- all scores should be displayed with 2 decimals max. but perfect score displayed as integer(ex: 90.00/100 , ex : 98.25/100) 
			- however, average should be most exact as possible, so calculation's result would be ensured as floats
			- A-F grades / scores mapping are as such [
				{S:{'-':100}},
				{A:{'+':95,'-':90}},
				{B:{'+':85,'-':80}},
				{C:{'+':75,'-':70}},
				{C:{'+':65,'-':60}},
				{F:{'-':59}}
			]

*/

#define MAX_STRINGS 3
// GRADES
#define PERFECT 100
#define APLUS 95
#define A 90
#define BPLUS 85
#define B 80
#define CPLUS 75
#define C 75
#define DPLUS 65
#define D 60


char* getAdministrationComment(float points)
{
	if (points == PERFECT) return "Amazing! You may help your teachers now!";
	else if (points >= APLUS) return "Excellent! You may help your classmates now!";
	else if (points >= A) return "We are satisfied with your efforts... Keep it up!";
	else if (points >= BPLUS) return "A quite pleasant progress, but why not boost yourself to the top?";
	else if (points >= B) return "On the good path, keep on focusing!";
	else if (points >= CPLUS) return "You are perhaps having hard times, but it is no time to drop!";
	else if (points >= C) return "It is maybe time to double efforts in order to catch up";
	else if (points >= DPLUS) return "You must get yourself together... NOW !!!";
	else if (points >= D) return "Veeeery very disappointing...";

	return "You seem to be in total failure";
}
char* getAmStandardGrade(float points)
{
	if (points == PERFECT) return "S";
	else if (points >= APLUS) return "A+";
	else if (points >= A) return "A";
	else if (points >= BPLUS) return "B+";
	else if (points >= B) return "B";
	else if (points >= CPLUS) return "C+";
	else if (points >= C) return "C";
	else if (points >= DPLUS) return "D+";
	else if (points >= D) return "D";

	return "F";
}
int main(void) {
	printf("\n\n\n\n\n\n\n");
	/*
		- Need User Inputs for respective Courses Scores, in Korean, English and Math
	*/
	char* courses[MAX_STRINGS] = {	"Korean Language",
									"Business English",
									"Engineering Maths" } ;

	float scores[MAX_STRINGS] = { 0 }; // Empty array of personal scores
	float perfect = PERFECT, score, scores_total = 0, perfect_total = 0;
	
	for (int i = 0; i < MAX_STRINGS; ++i) {
		
		printf("Please Enter your %s Class Score : ", courses[i]);
		scanf_s("%f", &score); // store personal score in local variable.
		
		perfect_total += perfect; // accumulated perfect score
		scores_total += score; // accumulated personal score
		scores[i] = score; // store personal score in score array for later output
	}
	printf("\n");

	// Output the list of separate scores for the user
	for (int j = 0; j < MAX_STRINGS; ++j) {
		float cur_score = scores[j] ;
		printf("%3c|\t %s \t\t : %1.2f , \t : %s\n", 32, courses[j], cur_score, getAmStandardGrade(cur_score));
	}
	
	// Output a first raw score out of total accumulated points
	printf("\nYou have scored : \t\t%1.2f\n\t\t\t\t/%d\n\n\n", scores_total, (int)perfect_total);
	
	// Calculation of average score
	float scores_av = scores_total / perfect_total * perfect;

	// Output the calculated result, inform about the corresponding A-F Grade, and make a Teacher Comment.
	printf("Your average score :\t\t %1.2f \n\t\t\t\t/%d\n\n\n", scores_av, (int)perfect);
	printf("Which deserves the grade :\t%s : \n\t\t\t\t%s\n", getAmStandardGrade(scores_av), getAdministrationComment(scores_av));
	
	printf("\n\n\n\n\n\n\n");
	return 0;
}

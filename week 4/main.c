
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week#3 Project 2 -- This project covers Calculations, Byteshifting and Number Datatypes Casting

@mission:		A Simple X-Y Cartesian > Polar Coordinates calculator

*/




/*

This program can calculate / find Data upon given X and Y coordinates.
	Primary Mission :	
		- Find corresponding quadrant (1-4) of the point P(x, y) ;
	
	Secundary Mission:
		- Calculate Magnitude and Angle of Vector(OP) O(0,0)->P(x, y) ;
	Bonus Mission :
		- Draw a vizualizing graph of location of point P to confirm previous results.
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES	// import Mathematic famous constants
#include <math.h>			// import Math lib


#define MAX_H 13			// Number of Y-Lines in Graph
#define MAX_W 32			// Number of Y-Lines in Graph


float findMagnitude(float x, float y) {
	return sqrt(pow(x, 2) + pow(y, 2)) ;
}
float toDegrees(float theta) {
	return (theta / M_PI) * 180;
}
float toRadians(float angle) {
	return (angle * M_PI) / 180;
}
float findAngle(float x, float y) {

	float theta = x ? atan(y / x) : 0 ; // Gives NaN if is Zero --> cannot divide by 0
	float angle = toDegrees(theta);

	/*
		here the quadrant checking process is the same as in main function 
		but using shorthands to use less space...
	*/

	int ypos = y >= 0, xpos = x >= 0;
	angle = ypos ? angle : xpos ? 360 + angle: 180 + angle ;
	angle = xpos ? angle : ypos ? 90 - angle : angle;

	return angle;
}

void drawGraph(int line, int locx, int locy) {
	const int H = MAX_H >> 1;
	const int W = MAX_W >> 1;
	locx = locx > 50 ? 50 : locx;
	locy = locy > 50 ? 50 : locy;
	int x = round(locx / 10.0);
	int y = round(locy / 10.0);
	
	
	int coordy = (H) - (y == 0 ? (locy > 0 ? 1 : -1): y);
	if (locy == 0) coordy = H;
	
	int coordx = W + (x << 1) - 1;
	if (x == 0) coordx = locx > 0 ? W: W - 2;
	if (locx == 0) coordx = W -1;


	int space = 32;
	int dot = 46;
	int X = 120;

	
	printf("\t");
	int i = 0;
	for (i = 0; i < MAX_W; i ++) {
		if(line == coordy)
			printf("%c", i == coordx ? X : i == (W - 1) ? dot : (line == H) ? (i % 2 == 0) ? space : dot : space);
		else 
			printf("%c", (line == H) ? (i%2==0) ? space : dot : i == (W - 1 ) ? dot : space);
	}
	printf("\n");
	
}

int main(void) {

	printf("\n\n\n");

	printf("\t(x, y) 좌표를 입력해 주세요 : \n");

	float x = 0, y = 0;
	float angle, magnitude;


	scanf_s("%f %f", &x, &y);
	printf("\n\t좌표(x: %.2f, y: %.2f)", x, y); // Log the Entered Coordinates
	printf("\t크기: %.2f", magnitude = findMagnitude(x, y)); // Express Magnitude of vector (0, 0)->(x, y)
	printf("\t각도: %.2f° E\n", angle = findAngle(x, y)); // Express Angle of vector (0, 0)->(x, y)

	int posX = x >= 0; // store positivity of x
	int posY = y >= 0; // store positivity of y

	int quadrant = 0;

	/*
	Quadrant checking
		1: x >= 0	&&	y >= 0
		2: x <  0	&&	y >= 0
		3: x <  0	&&	y <  0
		4: x >= 0	&&	y <  0
	This would be the TRADITIONAL way, it works but is NOT SO GOOD LOOKING
	*/

	/*
	if (posX) {
		if (posY) {
			quadrant = 1;
		} else {
			quadrant = 4;
		}
	}else {
		if (posY) {
			quadrant = 2;
		} else {
			quadrant = 3;
		}
	}
	*/

	/*
		or, since I now have an Angle Value, feels more clear
	*/	

	if(angle > 270){
		quadrant = 4 ;
	}else if(angle > 180){
		quadrant = 3 ;
	}else if(angle > 90){
		quadrant = 2 ;
	}else{
		quadrant = 1 ;
	}

	printf("\n");
	
	
	/*
	
	BONUS DRAW LOCATION ON X-Y SIMPLIFIED GRAPH

	*/

	for (int i = 0; i < MAX_H; i++) {
		drawGraph(i, (int)x, (int)y);
	}

	printf("\n\n\t%d 사분면입니다.\n", quadrant);


	printf("\n\n\n");


	return 0;
}

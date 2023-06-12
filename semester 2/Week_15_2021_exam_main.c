
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #12 Project 1&2 -- This project covers Combination of Struct and Binary Read/Write Files (fread() and fwrite() functions)

@mission:		A Simple Read / Write Example of Rectangle Data into Binary Files

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include <windows.h>

/*

Reading and Writing Binary Files
Here, using Struct Objects for Data Representation

*/


int Program(void) {

	
	ConsoleRandomSquares(0);

	
	return 0;
}


HWND hwnd;
HDC hdc;


void gotoXY(int x, int y) {
	COORD curpos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curpos);
}

#define MAX 5

int ConsoleRandomSquares(int solid) {

	system("cls");
	
	//system("mode cols=60 lines=30");
	

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);
	HBRUSH Brush, oldBrush;
	HPEN Pen, oldPen;

	srand(time(NULL));


	
	///////////////////////////// INITIALIZE DATA
	int vals[MAX] = { 0 };
	double av = 0;
	for (int i = 0; i < MAX; i++) {
		vals[i] = 1 + rand() % 199;
		av += vals[i];
	}
	av /= 5;
	/////////////////////////////



	///////////////////////////// FILE CREATION
	const char* out = "graph.txt";

	int file_exists = fopen(out, "r") != NULL; // Hack to know if file was newly created, --> later use this bool variable to write newline or not

	FILE* fout = fopen(out, "a");
	if (!fout) { printf("Error Opening file: %s", out); exit(1); }
	/////////////////////////////




	///////////////////////////// APPENDING GRAPH DATA INTO FILE
	if (file_exists) {
		fprintf(fout, "\n");
	}
	for (int i = 0; i < MAX; i++) {
		fprintf(fout, "%d ", vals[i]);
	}
	fprintf(fout, "%1.1f", av);


	printf("File Successfully Written !!\n");

	fclose(fout);




	///////////////////////////// RENDERING GRAPH
	int startX = 100, startY = 100;
	int x = 0, y = 0, i = 0;

	int max = 5;
	int margin = 20;
	int randval;

	for (i = 0; i < max; i++) {
		x = startX;
		y = startY + (i * (margin << 1));
		randval = vals[i];
		///////////////////////////// DRAW
		Pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		oldPen = (HPEN)SelectObject(hdc, Pen);

		Rectangle(hdc, x, y, x + 100 + randval, y + margin);
		/////////////////////////////
	}

	DeleteObject(Pen);
	DeleteObject(oldPen);
	/////////////////////////////

	_getch();



	return 0;
}


int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}






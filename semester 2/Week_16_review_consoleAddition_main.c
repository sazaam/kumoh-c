
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
#include <wchar.h>
#include <locale.h>
#include <windows.h>

/*

Reading and Writing Binary Files
Here, using Struct Objects for Data Representation

*/


int Program(void) {


	ConsoleAddition(0);


	return 0;
}


HWND hwnd;
HDC hdc;


void gotoXY(int x, int y) {
	COORD curpos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curpos);
}

#define MAX 5

wchar_t* top[MAX] = { 0x250C, 0x2500, 0x2500, 0x2510 };
wchar_t* mid[MAX] = { 0x2502,' ', ' ',  0x2502};
wchar_t* bot[MAX] = { 0x2514,0x2500, 0x2500, 0x2518 };


void printTop() {
	for (int i = 0; i < MAX; i++) {
		wprintf(L"%lc", top[i]);
	}
}

void printMid(int n) {
	for (int i = 0; i < MAX; i++) {
		if (i == 2) {
			printf("%d", n);
		}else wprintf(L"%lc", mid[i]);
	}
}

void printBot() {
	for (int i = 0; i < MAX; i++) {
		wprintf(L"%lc", bot[i]);
	}
}
void hideCursor(int size, BOOL flag) {
	CONSOLE_CURSOR_INFO	curInfo = { 0, };
	curInfo.dwSize = size;
	curInfo.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void printNum(int x, int y, int n) {

	gotoXY(x, y);
	printTop();
	gotoXY(x, y+1);
	printMid(n);
	gotoXY(x, y+2);
	printBot();
}

void printPlus(int x, int y) {
	gotoXY(x, y);
	printf("+");
}
int generateRandomNum() {
	return (rand() % 9);
}

concatenate(int x, int y) {
	unsigned pow = 10;
	while (y >= pow)
		pow *= 10;
	return x * pow + y;
}

void deconcatenate(int z, int* arr) {
	
	arr[0] = z / 100;
	arr[1] = z % 100 / 10;
	arr[2] = z % 10;
}

void printAns(int ans) {
	int arr[3] = {0,};
	deconcatenate(ans, arr);

	printNum(1, 15, arr[0]);
	printNum(5, 15, arr[1]);
	printNum(9, 15, arr[2]);
	gotoXY(0, 18);

}

int ConsoleAddition(int solid) {

	/////////////////////////////////// SETTINGS
	hideCursor(1, FALSE);
	system("mode con cols=60 lines=30");

	system("cls");
	setlocale(LC_CTYPE, "");
	srand(time(NULL));
	/////////////////////////////////// END SETTINGS
	
	int correctes = 0, falses = 0;



startgame:
	system("cls");

	int numtop[2] = { generateRandomNum(), generateRandomNum() };
	int numbot[2] = { generateRandomNum(), generateRandomNum() };

	printNum(5, 5, numtop[0]);
	printNum(9, 5, numtop[1]);

	printPlus(2, 9);
	
	printNum(5, 8, numbot[0]);
	printNum(9, 8, numbot[1]);

	int topnum = concatenate(numtop[0], numtop[1]);
	int botnum = concatenate(numbot[0], numbot[1]);

	int correctAns = topnum + botnum;
	int ans;
	puts("\n--------------------------------");
	gotoXY(0, 12);
	printf("Your Answer :");
	scanf("%d", &ans);
	
	
	if (ans == correctAns) {
		correctes++;
		printf("You are correct!");
	}else {
		falses++;
		printf("Wrong!... it was");
	}

	puts("");
	printAns(correctAns);

	printf("Correct Answers : %d, Wrong Answers %d\n", correctes, falses);
	char next;
	printf("Continue? (Any, 0) ...");
	
	scanf(" %c", &next);
	while (getchar() != '\n');

	switch (next) {
		case '0':
		
		break;
		default:
			goto startgame;
	}
	



	return 0;
}


int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}




int oldFunc() {

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

}

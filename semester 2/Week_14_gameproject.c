
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #12 Project 1&2 -- This project covers Combination of Struct and Binary Read/Write Files (fread() and fwrite() functions)

@mission:		A Simple Read / Write Example of Rectangle Data into Binary Files

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <ctype.h>

#include <conio.h>

#include <windows.h>
#include <Windows.h>

/*

Reading and Writing Binary Files
Here, using Struct Objects for Data Representation

*/


int Program(void) {


	// ConsoleClock();
	ConsoleWASD();
	return 0;
}


void gotoXY(int x, int y) {
	COORD curpos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curpos);
}
void hideCursor(int size, BOOL flag) {
	CONSOLE_CURSOR_INFO	curInfo = { 0, };
	curInfo.dwSize = size;
	curInfo.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int ConsoleClock() {
	BOOL dot = TRUE;
	int h, m, s;
	int now;
	system("title CLOCK");

	while (1) {
		now = (int)time(NULL);

		h = now / 3600 % 24 + 9;
		h %= 24;
		m = now / 60 % 60;
		s = now % 3600 % 60;

		gotoXY(8, 4);

		char sep = dot == TRUE ? ':' : ' ';
		printf("%02d %c %02d %c %02d", h, sep, m, sep, s);
		
		// can rewind/forward cursor position with this
		//gotoXY(11, 4);

		hideCursor(1, FALSE);
		
		Sleep(500);
		dot = !dot;
	}


	return 0;
}




#define ARROW 224
#define U 72
#define D 80
#define L 75
#define R 77

#define XMAX 50
#define YMAX 24


typedef struct Coords {
	int x;
	int y;
	char icon;

} C;



int clampCoord(int n, BOOL flag) {
	int max = flag ? XMAX : YMAX;
	int min = 0;
	return n < min ? min : n > max ? max: n;
}


int ConsoleWASD() {
	

	system("title WASD");
	system("mode con:cols=50 lines=24");
	hideCursor(1, FALSE);
	
	int x = XMAX >> 1, y = YMAX >> 1;

	gotoXY(x, y);
	printf("*");


	while (1) {


		if (_kbhit) {

			unsigned char key;
			key = _getch();
			printf("%c", tolower(key));

			
			switch (key)
			{
			case 'w':
				system("cls");
				y = clampCoord(y - 1, FALSE);
				break;
			case 's':
				system("cls");
				y = clampCoord(y + 1, FALSE);
				break;

			case 'a':
				system("cls");
				x = clampCoord(x - 1, TRUE);
				break;
			case 'd':
				system("cls");
				x = clampCoord(x + 1, TRUE);
				break;

			default:
				printf("\n Program will close now !");
				break;
			}


		}
		
		gotoXY(x, y);
		printf("*");

		Sleep(10);
	}

	return 0;
}


int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}

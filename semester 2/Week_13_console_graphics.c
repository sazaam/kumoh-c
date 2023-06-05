
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

	// ConsoleSystem();
	// ConsoleColor();
	// ConsoleCoords();
	// ConsolePixels();

	// ConsoleLine();

	// ConsoleEllipse();
	// ConsoleRandomSquares(0);

	ConsoleClock();
	return 0;
}


HWND hwnd;
HDC hdc;

int ConsoleSystem(){

	system("title Console Project Test");
	
	printf("First Console \n");
	

	system("pause");
	system("cls");
	system("mode con cols=60 lines=30");

	printf("Second Console \n");

	return 0;
}



void TextColor(unsigned short txt, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back | txt);
}

int ConsoleColor() {
	int i = 0, txt = 0, back = 0;

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);


	srand(time(NULL));

	for (i = 0; i < 16; i++) {
		txt = rand() % 16;
		back = rand() % 16;
		back = back << 4;
		TextColor(txt, back);
		printf(">> text %d backgound %d \n", txt, back);
	}
	_getch();


	return 0;
}


int ConsoleCoords(){
	COORD cur;

	cur.X = 10;
	cur.Y = 10;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	printf("x = %d y = %d \n", cur.X, cur.Y);

	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	_getch();

	return 0;
}



int ConsolePixels() {
	
	int x = 0, y = 0, i = 0, r = 0, g = 0, b = 0;
	

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	srand(time(NULL));


	for (i = 0 ; i < 100 ; i++) {
		x = rand() % 300;
		y = rand() % 300;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		SetPixel(hdc, x, y, RGB(r, g, b));
	}

	_getch();

	return 0;
}


void drawLine(HDC hdc, int x0, int y0, int x1, int y1) {
	MoveToEx(hdc, x0, y0, NULL);
	LineTo(hdc, x1, y1);
}


int ConsoleLine() {
	
	system("cls");

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	int x0 = 0, y0 = 0, x1 = 0, y1 = 0;

	srand(time(NULL));

	x0 = rand() % 100;
	y0 = rand() % 100;
	x1 = (rand() % 100) + 200;
	y1 = (rand() % 100) + 200;

	drawLine(hdc, x0, y0, x1, y1);
	//drawLine(hdc, 40, 60, 100, 300);
	
	ReleaseDC(hwnd, hdc);
	_getch();

	return 0;
}


int ConsoleEllipse() {
	
	system("cls");

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	int x = 0, y = 0, i = 0;


	Ellipse(hdc,100, 100, 180, 150);
	ReleaseDC(hwnd, hdc);

	_getch();

	return 0;
}


int ConsoleRandomSquares(int solid) {
	
	system("cls");

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);
	HBRUSH Brush, oldBrush;
	HPEN Pen, oldPen;

	int x = 0, y = 0, i = 0, r = 0, g = 0, b = 0;

	srand(time(NULL));

	for (i = 0; i < 100; i++) {
		x = rand() % 300;
		y = rand() % 300;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;

		if (solid) {
			Brush = CreateSolidBrush(RGB(r, g, b));
			oldBrush = (HBRUSH)SelectObject(hdc, Brush);

		} else {
			Pen = CreatePen(PS_DASH, 1, RGB(r, g, b));
			oldPen = (HPEN)SelectObject(hdc, Pen);
		}
		

		Rectangle(hdc, x, y, x + 30, y+30);
	}
	if (solid) {
		DeleteObject(Brush);
		DeleteObject(oldBrush);
	} else {
		DeleteObject(Pen);
		DeleteObject(oldPen);
	}
	
	
	_getch();

	return 0;
}

void gotoXY(int x, int y) {
	COORD curpos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curpos);
}
void hideCursor(int size, BOOL flag) {
	CONSOLE_CURSOR_INFO	curInfo = { 0, };
	curInfo.dwSize = size;
	curInfo.bVisible = flag;
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
		printf("%02d %02d %02d ", h, m, s);

		gotoXY(11, 4);

		if (dot == TRUE) {
			printf(":");
			gotoXY(16, 4);
			printf(":");
		}
		else {
			printf(":");
			gotoXY(16, 4);
			printf(":");
		}
		Sleep(500);
		dot = !dot;
	}


	return 0;
}


int main(void) {
	printf("Exercises !!! \n\n\n");
	Program();

	return 0;
}







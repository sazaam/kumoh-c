
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #14 Mini Console Project

@mission:		A Simple escaping game called XSCAPE !!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <Windows.h>


static const char* TITLE = "\
MNx; ::, , ''cxKWWMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMM\
MMXo........'cONWMMMMMMMMMMMMMMMMMMMNKXWMMMMMMMMMM\
MMMWOl'........l0WMMMMMMMMMMMMMMMMW0lxNWKXMMMMMMMM\
MMMMMWKd'.......'dXMMMMMMMMMMMMMMNd; okolxXWMMMMMM\
MMMMMMWWKl........; oOWMMWMMMMMMNk;.cl'.ck0WMMMMMM\
MMMMMWWWWNO; .........dNMWWMMMNO:..; : .. : oxXMMM\
MMMMMMWMMMMXo.........cKMMMW0c.......clxNMMMMMMMMM\
MMMMMMMMMMMMNk, ........; 0WNx'.......;ckNMMMMMMMM\
MMMMMMMMMMMMMW0; ........, o:........, l0WMMMMMMMM\
MMMMMMMMMMMMMMMXc................., xNMMMMMMMMMMMM\
MMMMMMMMMMMMMMMMXo............... : OWMWWMMMMMMMMM\
MMMMMMMMMMMWMMMMMNl.............oXMMMMMMMMMMMMMMMM\
MMMMMMMMMMMMMMMMNx, ........... : 0WMMMMMMMMMMMMMM\
MMMMMMMMMMMMMMNO : .............oNWMMMMMMMMMMMMMMM\
MMMMMMMMMMMWWKl................cXMMMMMMMMMMMMMMMMM\
MMMMMMMMMMMXd'..................;0WMMMMMMWMMMMMMMM\
MMMWWMMMMNk; ....... ...'l;.......'dNWWMMMWMMMMMMM\
MMMWWMMW0c..........., dKWXl........:0WWMMMMMMMMMM\
MMMWMMNx, .........'cdXMMMMNk,........oKMMMMMMMMMM\
MMMMWKo, ........'oKWWMMMMMMMXo'......., oKWMMMMMM\
MMMNOl'.......,oKWMMMMMMMMMMMW0c.........l0WMMMMMM\
MWKd; ......:okXMMMMMMMMMMMMMMMMWOl; .......'dMMMM\
W0oc, ...':dKWMMMMMMMMMMMMMMWWMMMMWXOo:::oxodMMMMM\
0do:, ;; :dKWMMMMMMMMMMMMMMMMMMMMMMMMMMWXKWMMMMMMM\
";


enum difficulty{ EASY, MEDIUM, HARD};


#define OK 13
#define SPACE 32
#define ESC 27

#define ARROW 224
#define U 72
#define D 80
#define L 75
#define R 77

#define XMAX 50
#define YMAX 24
#define ENNEMIES 30

#define WIN 1
#define LOSE 0


#define CREDITS "*       Made By Sazaam          *"



HWND hwnd;
HDC hdc;


int Program(void) {
	App(EASY);
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


void TextColor(unsigned short txt, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back | txt);
}




typedef struct Coords {
	int x;
	int y;
	char icon;

} C;



int clampCoord(int n, BOOL flag) {
	int max = flag ? XMAX : YMAX;
	int min = 0;
	return n < min ? min : n > max ? max : n;
}

C curTo(C c) {
	gotoXY(c.x, c.y);

	return c;
}

C moveTo(C c, int flag, unsigned char key) {
	int x = c.x, y = c.y;

	switch (key)
	{
		case	'w':
		case	U:
			y = clampCoord(y - 1, FALSE); break;
		case	's':
		case	D:
			y = clampCoord(y + 1, FALSE); break;
		case	'a':
		case	L:
			x = clampCoord(x - 1, TRUE); break;
		case	'd':
		case	R:
			x = clampCoord(x + 1, TRUE); break;
		case	224:
			break; // Do Nothing
	}

	C tar = { x, y };
	return tar;
}

int reached(C c) {
	return (c.x == 0 || c.x == XMAX - 1 || c.y == 0 || c.y == YMAX - 1);
}

int collapse(C c, C t) {
	return (c.x == t.x && c.y == t.y);
}

int drawLines(int x, int y, int back) {
	gotoXY(x, y);
	puts(back ? "                                 ": "*********************************");
}

int msgboard(int success, char* msg[], int back) {

	TextColor(success != 3 ? 3 : 15, 0x000000);
	
	drawLines(8, 10, success == 3);
	gotoXY(8, 11);
	
	switch (success) {
		case 1:
			puts("*          YOU WIN !!!          *");
			break;
		case 0:
			puts("*         GAME OVER !!          *");
			break;
		case 2:
			puts("*      THANKS FOR PLAYING       *");
			break;
		case 3:
			puts("        SELECT DIFFICULTY        ");
			break;
	} 
	
	drawLines(8, 12, success == 3);

	TextColor(success == 2 ? 3 : 15, 0x000000);


	gotoXY(8, 14);
	printf("%s", msg);
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	return 0;
}

int endScreen(int success, int difficulty) {

	
	int key = 0;
	char* msg[40] = {0,};
	
	int choice = 1;
	strcpy(msg, "* New Game *               Exit  ");
display:
	
	system("cls");
	
	
	msgboard(success, msg, 1);
	

	if (_kbhit) {
		key = _getch();
		
		if (key == 224) {
			goto display;
		}
		switch (key) {
			case 'd':
			case R:
				strcpy(msg, "  New Game               * Exit *");
				choice = 0;
				break;
			case 'a':
			case L:
				strcpy(msg, "* New Game *               Exit  ");
				choice = 1;
				break;
			case OK:
			case SPACE:
				return choice ? App(difficulty) : msgboard(2, CREDITS, 0);
				break;
			case ESC:
				msgboard(2, CREDITS, 0);
				return 0;
		}
	}else Sleep(100);

	
	goto display;

	return 0;

}




int difficultyScreen(int difficulty) {

	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	
	int key = 0;
	char* msg[40] = { 0, };
	
	

display:

	switch (difficulty) {
		case EASY:
			strcpy(msg, "* Easy *      Medium       Hard  ");
			break;
		case MEDIUM:
			strcpy(msg, "  Easy      * Medium *     Hard  ");
			break;
		case HARD:
			strcpy(msg, "  Easy        Medium     * Hard *");
			break;

	}


	/////////////////////////// TITLE + MSG BOARD
	system("cls");
	TextColor(3, 0x000000);
	printf(TITLE);
	TextColor(15, 0x000000);
	
	msgboard(3, msg, 1);
	/////////////////////////// 


	if (_kbhit) {
		key = _getch();

		if (key == 224) {
			goto display;
		}
		switch (key) {
		case 'd':
		case R:
			difficulty++;
			break;
		case 'a':
		case L:
			difficulty--;
			break;
		case OK:
		case SPACE:
			return game(difficulty);
			break;
		case ESC:
			// back to home screen 
			return 0;
		}
	}
	else Sleep(100);

	difficulty = difficulty >= 2 ? 2 : difficulty <= 0 ? 0 : difficulty;



	goto display;

	return 0;

}



int App(int difficulty) {


	///////////////// SETTINGS
	system("title Xscape GAME");
	system("mode con:cols=50 lines=24");
	hideCursor(1, FALSE);
	srand(time(NULL));
	
	
	
	char* diff[40] = { 0, };
	difficultyScreen(difficulty);


	return 0;

	
	
	game(difficulty);


	return 0;
}


int isValid(int key) {
	switch (key) {
		case	'w':
		case	's':
		case	'a':
		case	'd':
		case	U:
		case	D:
		case	L:
		case	R:
			return 1;
			break;
		default:
			return 0;
	}
}

int game(int difficulty) {

	system("cls");

	//////////////////////////////////////////////////////////////////////// SETTINGS
	int i = 0;
	int totalennemies = 0;
	double spawnpos = 1.0;
	int state = 1;


	///////////////// INITIALIZE TARGET
	C target = { XMAX >> 1, YMAX >> 1 };
	curTo(target);
	printf("*");
	///////////////// INITIALIZE TARGET

	///////////////// DIFFICULTY
	switch (difficulty) {
		case 0: 
			totalennemies = 15;

			break;
		case 1:
			totalennemies = 20;
			spawnpos = 1;
			break;
		case 2:
			totalennemies = 30;
			spawnpos = .9;
			break;
	}


	TextColor(3, 0x000000);


	///////////////// INITIALIZE ENNEMIES
	C ennemies[ENNEMIES] = { 0, };

	int minx = (int)XMAX / (4.0 * spawnpos);
	int miny = (int)YMAX / (4.0 * spawnpos);

	for (i; i < totalennemies ; i++) {
		
		int ennx, enny, condx, condy, poscond = 0;
		
		while(!poscond) {
			ennx = rand() % XMAX;
			enny = rand() % YMAX;
			
			condx = ennx <= minx || ennx >= XMAX - minx;
			condy = enny <= miny || ennx >= YMAX - miny;
			
			poscond = condx && condy;
		}
		
		ennemies[i].x = ennx;
		ennemies[i].y = enny;
		curTo(ennemies[i]);
		printf("X");
	}
	///////////////// INITIALIZE ENNEMIES


	TextColor(15, 0x000000);


	///////////////// GAME LOOP
	while (1) {

		if (_kbhit) {

			unsigned char key;
			key = _getch();

			if (!isValid(key)) { continue; }
			


			system("cls");


			target = moveTo(target, 0, key);
			curTo(target);
			printf("*");


			if (reached(target)) {
				state = WIN;
				break;
			}



			TextColor(3, 0x000000);


			for (i = 0; i < ENNEMIES; i++) {


				int distx = ennemies[i].x - target.x;
				int disty = ennemies[i].y - target.y;
				if (distx) {
					ennemies[i].x = distx < 0 ? ennemies[i].x + 1 : ennemies[i].x - 1;
				}
				if (disty) {
					ennemies[i].y = disty < 0 ? ennemies[i].y + 1 : ennemies[i].y - 1;
				}


				curTo(ennemies[i]);

				if (collapse(ennemies[i], target)) {

					state = LOSE;
					goto win;
				}
				printf("X");
			}




			TextColor(15, 0x000000);



		}

		Sleep(10);

	}
	///////////////// GAMELOOP


win:
	endScreen(state, difficulty);


}



int main(void) {

	Program();

	return 0;
}

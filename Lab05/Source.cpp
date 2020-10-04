#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void draw_bullet(int, int);
void erase_bullet(int, int);
int main(){
	int direc = 2;
	char ch = ' ';
	int x = 38, y = 20, a[5] = { 0 }, b[5] = { 0 }, bullet[5] = { 0 };
	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' ' && bullet[0] == 0) {
				a[0] = x + 3;
				b[0] = y - 1;
				bullet[0] = 1;
			}
			else if (ch == ' ' && bullet[1] == 0) {
				a[1] = x + 3;
				b[1] = y - 1;
				bullet[1] = 1;
			}
			else if (ch == ' ' && bullet[2] == 0) {
				a[2] = x + 3;
				b[2] = y - 1;
				bullet[2] = 1;
			}
			else if (ch == ' ' && bullet[3] == 0) {
				a[3] = x + 3;
				b[3] = y - 1;
				bullet[3] = 1;
			}
			else if (ch == ' ' && bullet[4] == 0) {
				a[4] = x + 3;
				b[4] = y - 1;
				bullet[4] = 1;
			}
			if (ch == 'a') {
				direc = 0;
			}
			if (ch == 'd') {
				direc = 1;
			}
			if (ch == 's') {
				direc = 2;
			}
			fflush(stdin);
		}
		if (direc == 0 && x > 0) {
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direc == 1 && x < 80) {
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direc == 2) {
			draw_ship(x, y);
		}
		if (bullet[0] == 1) {
			erase_bullet(a[0], b[0]);
			if (b[0] > 0) {
				draw_bullet(a[0], --b[0]);
			}
			else {
				bullet[0] = 0;
			}
		}
		if (bullet[1] == 1) {
			erase_bullet(a[1], b[1]);
			if (b[1] > 0) {
				draw_bullet(a[1], --b[1]);
			}
			else {
				bullet[1] = 0;
			}
		}
		if (bullet[2] == 1) {
			erase_bullet(a[2], b[2]);
			if (b[2] > 0) {
				draw_bullet(a[2], --b[2]);
			}
			else {
				bullet[2] = 0;
			}
		}
		if (bullet[3] == 1) {
			erase_bullet(a[3], b[3]);
			if (b[3] > 0) {
				draw_bullet(a[3], --b[3]);
			}
			else {
				bullet[3] = 0;
			}
		}
		if (bullet[4] == 1) {
			erase_bullet(a[4], b[4]);
			if (b[4] > 0) {
				draw_bullet(a[4], --b[4]);
			}
			else {
				bullet[4] = 0;
			}
		}
		Sleep(100);
	}
	while (ch != 'x');
	return 0;
}
void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_bullet(int a, int b) {
	gotoxy(a, b);
	setcolor(2, 0);
	printf("!");
}
void erase_bullet(int a, int b) {
	gotoxy(a, b);
	setcolor(0, 0);
	printf(" ");
}
void setcursor(bool visible) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
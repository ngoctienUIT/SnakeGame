#include <iostream>
using namespace std;
#include <winbgim.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define 	MINW 		20
#define 	MINH 		20
#define 	MAXW 		420
#define 	MAXH 		220
#define 	MINX 		20
#define 	MINY 		20
#define 	MAXX 		420
#define 	MAXY 		220
#define 	BACKGROUND	15

struct Point {
	int x,y,x0,y0;
};

void loadingScreen();
void run();

void loadingScreen() {
	int x = 0;
	char *s = new char[5];
	while (x <= 100){
		cleardevice();
		setcolor(10);settextstyle(4,0,5);
		outtextxy (60,200,"Game Loading...");
		sprintf(s,"%d",x);
		setcolor(4);
		outtextxy (550,200, strcat(s,"%"));
		if (x == 100)
			delay (500);
		
		delay (rand()% 20);
		x++;
	}
}

void run (){
	initwindow (800,600);
	loadingScreen();
}


int main (){
	cout<< "Welcome to 3PGT's Snake Game!";
	run();
	return 0;
}
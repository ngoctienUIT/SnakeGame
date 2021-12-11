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

struct HighScore {
	int score;
	char name[30];
};

void initGame ();
bool checkPoint ();
void drawPoint (int x,int y,int r);
void drawSnake ();
void drawFood ();
void drawGame ();
void classic();
void modern();
void mainLoop (void (*gloop)());
void run ();
void changeDirecton (int x);
void showHighScore();
void getHighScore();
void checkHighScore(int score);
void initScore();
bool isEmpty();
void showText(int x,int y,char *str);
void showTextBackground(int x,int y,char *str,int color);


int level;
bool endGame;
int snakeLength;
Point snake[100];
Point direction;
Point food;
const int DIRECTION	= 10;
HighScore  highscore[5];
char* score_str = new char[20];

//Hien thi text voi mau ngau nhien
void showText(int x,int y,char *str)
{
	int c = getcolor();
	int color = rand() % 16 + 1;
	setcolor(color);
	outtextxy(x+3,y,str);
	setcolor(c);
	delay(50);
}

//Hien thi text voi mau background co dinh
void showTextBackground(int x,int y,char *str,int color)
{
	int bk = getbkcolor();
	setbkcolor(color);
	outtextxy(x,y,str);
	delay(200);
	setbkcolor(bk);
}

void loadingScreen() 
{
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


bool checkPoint ()
{
	for (int i = 0;i < snakeLength;i++){
		if (food.x == snake[i].x && food.y == snake[i].y)
		return false;
	}
	return true;
}

//Ve Point co toa do tam (x,y) ban kinh r
void drawPoint (int x,int y,int radius)
{
	circle (x,y,radius);
	floodfill (x,y,getcolor());
}

//Ve Snake
void drawSnake ()
{
	setfillstyle (1,10);
	int dem = 0;
	for (int i = 0;dem < snakeLength;i++){
			drawPoint(snake[i].x, snake[i].y,5);
			dem++;
		}
	//Xoa dot cuoi cung cua than ran moi khi no di chuyen
	int x = getcolor();
	setfillstyle (1,BACKGROUND);
	drawPoint(snake[snakeLength-1].x0,snake[snakeLength-1].y0,5);
	setcolor (BACKGROUND);
	circle (snake[snakeLength-1].x0,snake[snakeLength-1].y0,5);
	setcolor(x);
	setfillstyle (1,5);
}

//Hien thi thuc an
void drawFood ()
{
	int x = getcolor();
	int c = rand() % 14 + 1;
		setcolor(c);
		setfillstyle (SOLID_FILL, c);
		drawPoint(food.x, food.y,5);
	setcolor(x);
	setfillstyle (1,BACKGROUND);
}

//Ve toan bo giao dien game
void drawGame ()
{
	drawSnake();
	drawFood();
	int x = getcolor ();
	setcolor (2);
	sprintf(score_str,"%d",snakeLength*level*10-level*30);    //Hien thi diem
   settextstyle(4,0,3);
   outtextxy(450,100,"SCORE:");
   setcolor(12);
   outtextxy(600,20,score_str);
   setcolor (x);
}

void initGame()
{
	setbkcolor (15);
	cleardevice ();
	setwindowtitle ("SNAKE-Playing....");
	endGame = false;
	setfillstyle (1,12);

	// Khoi tao khung tro choi
	bar(MINX,MINY,MAXX,MINY+5);
	bar(MAXX,MINY,MAXX-5,MAXY);
	bar(MAXX,MAXY,MINX,MAXY-5);
	bar(MINX,MINY,MINX+5,MAXY);
    setcolor (0);
    int bk = getbkcolor();
    
    // Khoi tao bang huong dan cac phim dieu huong
    setfillstyle (SOLID_FILL,0);
	int a[] = {15,350,30,350,30,345,50,355,30,365,30,360,15,360,15,350};
    fillpoly (8,a);
    settextstyle (4,0,3); outtextxy (70,340,"Right");
    int b[] = {15,410,30,400,30,405,45,405,45,415,30,415,30,420,15,410};
    fillpoly (8,b);outtextxy (70,400,"Left");
	int c[] = {235,370,235,355,230,355,240,340,250,355,245,355,245,370,235,370};
	fillpoly (8,c);outtextxy (265,340,"Up");
	int d[] = {235,400,235,415,230,415,240,430,250,415,245,415,245,400,235,400};
	fillpoly (8,d);outtextxy (265,400,"Down");
	bar (50,450,170,480);setcolor(15);settextstyle(1,0,1);setbkcolor(0);outtextxy(60,455,"SPACE");setbkcolor(bk);
	setcolor(0);settextstyle (4,0,3);outtextxy(200,450,"Pause/Resum");
	bar (50,500,170,530);setcolor(15);settextstyle(1,0,1);setbkcolor(0);outtextxy(80,505,"ESC");setbkcolor(bk);
	setcolor(0);settextstyle (4,0,3);outtextxy(200,500,"End Game");
	
	//Khoi tao thuoc tinh ban dau cho con ran
	snake[0].x = 60;snake[0].y = 50;
	snake[1].x = 50;snake[1].y = 50;
	snake[2].x = 40;snake[2].y = 50;
	snakeLength = 3;
	
	setfillstyle (1,BACKGROUND);
	bar (25,25,415,215);
	
	// Khoi tao huong di
	direction.x = 10;direction.y = 0; 
	setcolor (2);
	srand ( time(NULL));
	
	//Khoi tao trai cay
   	/*do{
        food.x = (rand() % (39) + 3)*10;
    	food.y = (rand() % (19) + 3)*10;
	}while (checkPoint() == false);*/

}

void run ()
{
	initwindow (800,600);
	//loadingScreen();
;
	initGame();
	settextstyle(1,0,6);
	setcolor (10);
	showText(110, 110, "Hien thi text");
	clearmouseclick(WM_LBUTTONDOWN);
	
	showTextBackground(110, 210, "Hien thi text", 12);
	
	Sleep(10000);
}
	
void changeDirecton (int x)
{
	switch(x){
                case 72: // di len neu hien tai dang sang trai hoac phai
                    if (direction.y != DIRECTION) {
                    	PlaySound(TEXT("beep.wav"), NULL, SND_ASYNC);
            			direction.y = -DIRECTION; direction.x = 0;
        			}
                    break;
                case 80: // di xuong neu hien tai dang sang trai hoac phai
                	if (direction.y != -DIRECTION) {
                		PlaySound(TEXT("beep.wav"), NULL, SND_ASYNC);
            			direction.y = DIRECTION; direction.x = 0;
        			}
                   break;
                case 77: //sang phai neu hien tai dang len hoac xuong
                    if (direction.x != -DIRECTION) {
                    	PlaySound(TEXT("beep.wav"), NULL, SND_ASYNC);
            			direction.x = DIRECTION; direction.y = 0;
        			}
                    break;
                case 75: //sang trai neu hien tai dang len hoac xuong
                    if (direction.x != DIRECTION) {
                    	PlaySound(TEXT("beep.wav"), NULL, SND_ASYNC);
            			direction.x = -DIRECTION; direction.y = 0;
        			}
                    break;
                case 27: // an phim esc de thoat
                	endGame = true;
					break;
            }
}

void classic()
{
	// che do choi di xuyen qua tuong
    for (int i = 0; i < snakeLength; i++) {
        if (i == 0) {
            snake[0].x0 = snake[0].x;snake[0].y0 = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
        }else{
            snake[i].x0 = snake[i].x;snake[i].y0 = snake[i].y;
			snake[i].x = snake[i-1].x0;snake[i].y = snake[i-1].y0;
        }
         
        if (snake[i].x >= MAXX) snake[i].x = MINX + 10;
        if (snake[i].x <= MINX) snake[i].x = MAXX - 10;
        if (snake[i].y >= MAXY) snake[i].y = MINY + 10;
        if (snake[i].y <= MINY) snake[i].y = MAXY - 10;
         
        // ket thuc neu ran cham vao than
        if (i != 0 && (snake[0].x == snake[i].x && snake[0].y == snake[i].y)) endGame = true;
    }
    if (snake[0].x == food.x && snake[0].y == food.y){
		snake[snakeLength].x = snake[snakeLength-1].x0;snake[snakeLength].y = snake[snakeLength-1].y0;
		snakeLength++;
		PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
		
		//Tao thuc an moi
		srand ( time(NULL));
        do{
        	food.x = (rand() % (39) + 3)*10;
    		food.y = (rand() % (19) + 3)*10;
		}while (checkPoint() == false);
	}
}

void modern()
{
	// che do choi khong di xuyen tuong
	for (int i = 0;i < snakeLength;i++){
		if (i == 0){
			snake[0].x0 = snake[0].x;snake[0].y0 = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}
		else {
			snake[i].x0 = snake[i].x;snake[i].y0 = snake[i].y;
			snake[i].x = snake[i-1].x0;snake[i].y = snake[i-1].y0;
		}
		
		// ket thuc neu ran cham tuong
		if (snake[0].x < MINX+5 || snake[0].y < MINY+5 || snake[0].x > MAXX-5 || snake[0].y > MAXY - 5 )
			endGame = true;
			
		// ket thuc neu ran cham vao than
		if (i != 0 && snake[0].x == snake[i].x && snake[0].y == snake[i].y)	 endGame = true;
	}
	if (snake[0].x == food.x && snake[0].y == food.y){
		snake[snakeLength].x = snake[snakeLength-1].x0;snake[snakeLength].y = snake[snakeLength-1].y0;
		snakeLength++;
		PlaySound(TEXT("eatFood.wav"), NULL, SND_ASYNC);
		
		//Tao thuc an moi
		srand ( time(NULL));
		do{
        	food.x = (rand() % (39) + 3)*10;
    		food.y = (rand() % (19) + 3)*10;
		}while (checkPoint() == false);
	}
}

//ham lap cho game chay va thuc thi toan bo  cac hanh dong khi game chay
void mainLoop (void (*xxx)())
{
	int x = getcolor();
	if (!kbhit()){
		xxx();
	}
	else{
		char ch;
        ch = getch();
		if (ch == -32) ch = getch();
		if ( ch == 32){
			setcolor(0);outtextxy (100,100,"Game Pause");setcolor(x);
			ch = getch();
			while (ch != 32){
				ch = getch();
				delay(0);
			}
			setcolor (BACKGROUND);
			outtextxy (100,100,"Game Pause");
			setcolor (x);
			delay(1000);
		}
        changeDirecton(ch);
        mainLoop (xxx);
    }
}

//ham hien thi diem cao tu file
void showHighScore(){
	FILE *f;
	f = fopen("highscore.txt", "r");
	char ch[20];
	settextstyle (1,0,5);
	setcolor (15);
	outtextxy (150,50,"HIGH SCORE");
	settextstyle (1,0,4);
	int y = 150,count = 0;
	while (!feof(f)){
		if (count == 10) break;
		count++;
		fscanf(f, "%s", ch);
   		if (count%2 == 1){
   			setcolor (10);
   			outtextxy (180,y,ch);
   			y+=50;
		}else{
			setcolor (12);
			outtextxy (500,y-50,ch);	   	
		}
	}
	fclose(f);
}

//ham luu diem cao vao file 
void getHighScore (){
	FILE *f;
	f = fopen("highscore.txt", "w");
	for (int i = 0;i < 5;i++){
		fputs(highscore[i].name,f);
		fputs(" ",f);
		fprintf(f,"%d",highscore[i].score);
		fputs("\n",f);
	}
	fclose(f);
}

int main () {
	cout<< "Welcome to 3PGT's Snake Game!";
	run();
	return 0;
}
#include <iostream>
#include "graphics.h"
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <dos.h>


int yax[5] = { 0,100,200,300,400 };
int copy[5] = { 0,100,200,300,400 };
void car(int &x,int &y);
void steering(int &X, int&y);
void crash();
int sleep = 50;
//only testing:
bool obschance()
{
	int i = 1;
	if (i == 1)
	{
		i = 0;

		i = ((rand() % 100) + 1);
		if (i == 69)
		{
			i = 1;
			return i;
		}
	}
}
void obstacle(bool i)
{ 
	if (i == 1)
	{
		srand(time(0));
		int x = ((rand() % 700) + 200);
		myRectangle(x, 80, x + 60, 87, 255, 255, 255, 255, 255, 255);
		myRectangle(x, 80, x + 5, 150, 255, 255, 255, 255, 255, 255);
		myRectangle(x + 60, 80, x + 65, 150, 255, 255, 255, 255, 255, 255);
		myLine(x, 80, x + 65, 150, 255, 0, 0, 5);
		myLine(x + 60, 80, x, 150, 255, 0, 0, 5);
	}
}
void mainscr()
{
	/*myLine(300, 200, 775, 200, 255, 255, 255,4);
	myLine(775, 200, 775, 250, 255, 255, 255, 4);
	myLine(775, 250, 300, 250, 255, 255, 255, 4);
	myLine(300, 200, 300, 250, 255, 255, 255, 4);
	myLine(700, 200, 625, 100, 255, 255, 255, 6);
	myLine(625, 100, 450, 100, 255, 255, 255, 6);
	myLine(450, 100, 400, 200, 255, 255, 255, 6);
	myLine(530, 200, 530, 100, 255, 255, 255, 6);
	myLine(580, 200, 580, 170, 255, 255, 255, 4);
	myEllipse(570, 180, 590, 150, 255, 255, 255, 195, 149, 130);
	myEllipse(350, 250, 450, 325, 255, 255, 255, 0, 0 ,0);
	myEllipse(575, 250, 675, 325, 255, 255, 255, 0, 0, 0);*/

	
	gotoxy(300, 450);
	std::cout << "\nWELCOME TO MEHRAN GAME         alpha 2.07567\n";
	std::cout << "left right arrow keys to move \n";
	std::cout << "top bottom arrow keys to change speed\n";
	std::cout << "beta version coming soon!!!!!!! includes fun coins , obstacles and points system\n";
	std::cout << "press any key to play\n";
	_getch();
	cls();
	std::cout << "loading";
	for (int i = 0; i < 15; ++i)
	{
		std::cout << '.';
		Sleep(100);
	}
	cls();

	
}
void roadside(int yax[]) {
	
	
	myRectangle(180, 1, 760, 478, 255, 255, 255,0,0,0);
	myRectangle(200, 1, 740, 478, 255, 255, 255,0,0,0);
	//for left boundary:
	myRectangle(180, 0, 200, 100, 255, 255, 255, 255, 255, 255);
	myRectangle(180, yax[0],200, yax[0] + 150, 255, 255, 255, 255, 0, 0);
	myRectangle(180, yax[1], 200, yax[1] + 250, 255, 255, 255, 255, 255, 255);
	myRectangle(180, yax[2] , 200, yax[2] + 350, 255, 255, 255, 255, 0, 0);
	myRectangle(180, yax[3], 200, yax[3] + 450, 255, 255, 255, 255, 255, 255);
	myRectangle(180, yax[4], 200, yax[4] + 478, 255, 255, 255, 255, 0, 0);
	//for right boundary:
	myRectangle(740, 0, 760, 100, 255, 255, 255, 255, 255, 255);
	myRectangle(740, yax[0] , 760, yax[0] + 150, 255, 255, 255, 255, 0, 0);
    myRectangle(740, yax[1] , 760, yax[1] + 250, 255, 255, 255, 255, 255, 255);
	myRectangle(740, yax[2] , 760, yax[2] + 350, 255, 255, 255, 255, 0, 0);
	myRectangle(740, yax[3] , 760, yax[3] + 450, 255, 255, 255, 255, 255, 255);
	myRectangle(740, yax[4] , 760, yax[4] + 478, 255, 255, 255, 255, 0, 0);

	
}
void midlines()
{
	
	int x = 250;
	int y = 300;

	int c = 10;
	while (x>200 && x<670 && y>0)
	{
		roadside(yax);
		myRectangle(460, 1, 480, 478, 255, 255, 255, 255, 255, 255);
		myRectangle(460, c, 480, c+150, 0, 0, 0, 0, 0, 0);
	    myRectangle(460,  c+300, 480, c+400, 0, 0, 0, 0, 0, 0);
		if (c > 170)
		{
			c = 0;
		}
		c = c + 10;
		{
			for (int i = 0; i < 5; i++)
			{
				yax[i] = yax[i] + 10;
			}

		}
		
		steering(x,y);
		car(x,y);

		for (int i = 0; i < 5; i++)
		{
			if (yax[i] > (copy[i] + 100))
			{
				yax[i] = copy[i];
			}
		}
		//int eks = obschance();
		//obstacle(eks);
		
	}
}
void car(int &x, int&y)
{
	int a;
	int b;
	    myLine(x + 10, y - 40, x + 60, y - 40, 255, 0, 0,2);
		myLine(x, y+2, x + 10, y - 40, 255, 0, 0,2);
		myLine(x + 70, y+2, x + 60, y - 40, 255, 0, 0,2);
		myRectangle(x + 12, y, x + 60, y - 38, 255, 0, 0, 255, 0, 0);
		myRectangle(x, y, x + 70, y + 150, 0, 0, 0, 255, 0, 0);
		myRectangle(x + 20, y + 20, x + 50, y + 130, 0, 0, 0, 255, 255, 0);
		myLine(x + 35, y, x + 35, y - 40, 0, 0, 0,2);
		myLine(x, y, x + 20, y + 20, 0, 0, 0,2);
		myLine(x + 70, y, x + 50, y + 20, 0, 0, 0,2);
		myLine(x, y + 150, x+20, y + 130, 0, 0, 0,2);
		myLine(x + 70, y + 150, x + 50, y + 130, 0, 0, 0,2);
		
	Sleep(sleep);

		myRectangle(x + 20, y + 20, x + 50, y + 130, 255, 255, 255, 255, 255, 0);
		myEllipse(x - 2, y + 65, x + 71, y - 60, 0, 0, 0, 0, 0, 0);
		a = x; b = y;
		
		myRectangle(a, b, a + 70, b + 150, 0, 0, 0, 0, 0, 0);
}
void steering(int &x,int &y)
{
	int key = 0;
	isCursorKeyPressed(key);
	if (key == 1)
		x = x - 20;
	else if (key == 2)
	{
		sleep = sleep - 5;
		if (sleep < 10)
			sleep = 10;
	}
	else if (key == 3)
		x = x + 20;
	else if (key == 4)
		sleep = sleep + 5;
}
void crash()
{
	
	myRectangle(250, 120, 625, 240, 255, 0, 0, 255, 0, 0);
	//C:
	myRectangle(270, 130, 275, 230, 0, 0, 0, 0, 0, 0);
	myRectangle(270, 130, 320, 135, 0, 0, 0, 0, 0, 0);
	myRectangle(270, 230, 320, 235, 0, 0, 0, 0, 0, 0);
	//R:
	myRectangle(340, 130, 345, 230, 0, 0, 0, 0, 0, 0);
	myRectangle(340, 130, 390, 135, 0, 0, 0, 0, 0, 0);
	myLine(340, 170, 395, 230, 0, 0, 0, 5);
	myRectangle(390, 130, 395, 170, 0, 0, 0, 0, 0, 0);
	myRectangle(395, 170, 340, 175, 0, 0, 0, 0, 0, 0);
	//A:
	myRectangle(405, 130, 410, 230, 0, 0, 0, 0, 0, 0);
	myRectangle(405, 130, 455, 135, 0, 0, 0, 0, 0, 0);
	myRectangle(455, 130, 460, 230, 0, 0, 0, 0, 0, 0);
	myRectangle(405, 170, 460, 175, 0, 0, 0, 0, 0, 0);
	//S:
	myRectangle(480, 130, 485, 180, 0, 0, 0, 0, 0, 0);
	myRectangle(480, 130, 530, 135, 0, 0, 0, 0, 0, 0);
	myRectangle(480, 180, 530, 185, 0, 0, 0, 0, 0, 0);
	myRectangle(530, 180, 535, 230, 0, 0, 0, 0, 0, 0);
	myRectangle(480, 230, 535, 235, 0, 0, 0, 0, 0, 0);
	//H:
	myRectangle(550, 130, 555, 235, 0, 0, 0, 0, 0, 0);
	myRectangle(550, 180, 600, 185, 0, 0, 0, 0, 0, 0);
	myRectangle(600, 130, 605, 235, 0, 0, 0, 0, 0, 0);
	
}
int main()
{
	    //background:
	
		myRectangle(1, 1, 960, 478, 255, 255, 255, 0, 0, 0);
		mainscr();
		cls();
		myRectangle(0, 0, 960, 478, 0, 0, 0, 0, 0, 0);
		
		myRectangle(1, 1, 960, 478, 255, 255, 255, 0, 0, 0);
		myRectangle(0, 0, 180, 478, 0, 255, 0, 0, 255, 0); 
		myRectangle(760, 0, 960, 478, 0, 255, 0, 0, 255, 0);
		//roadside(y);
		myRectangle(0, 0, 180, 478, 0, 255, 0, 0, 255, 0);
		midlines();
		//car();
		crash();
	//	obstacle();
		Sleep(2000);

		
	
	system("pause");
}
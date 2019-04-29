#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include <wincon.h>
#include <fstream>
using namespace std;
void Colour(int fore,int back)
{
	HANDLE Con;
	Con = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(fore){
		case 7:
			switch(back){
				case 1:
				//	system("color 10");
				SetConsoleTextAttribute(Con,FOREGROUND_WHITE | BACKGROUND_BLUE);
				break;	
				case 2:
				SetConsoleTextAttribute(Con,FOREGROUND_WHITE | BACKGROUND_GREEN);
				break;
				case  0:
				SetConsoleTextAttribute(Con,FOREGROUND_WHITE | BACKGROUND_BLACK);
				break;
			}
			break;
		case 4:
			switch(fore)
			{
				case 7:
					//system("color 20");
				SetConsoleTextAttribute(Con,FOREGROUND_RED | BACKGROUND_WHITE);
				break;
			}
		case 1:
		switch(fore)
			{
				case 7:
					//system("color 20");
				SetConsoleTextAttribute(Con,FOREGROUND_BLUE | BACKGROUND_WHITE);
				break;
			}
			
	}
}
void gotoxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col,row };
	SetConsoleCursorPosition(h, position);
}
	void ScheduleHeader()
	{
		system("color 7C");
		int x = 0, y = 2;
		gotoxy(x,y);
		cout << "FLIGHT NUMBER";
		x+=20;
		gotoxy(x,y);
		cout<< "FROM";
		x+=15;
		gotoxy(x,y);
		cout<< "TO";
		x+=12;
		gotoxy(x,y);
		cout<<"DEPARTURE";
		x+=15;
		gotoxy(x,y);
		cout<<"ARRIVAL";
			
	}

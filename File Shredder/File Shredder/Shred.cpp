#include "stdafx.h"
#include "Shred.h"


Shred::Shred()
{
}


Shred::~Shred()
{
}

void Shred::Display()
{
	cout << "******************************************\n";
	cout << "| File Encryption Shredder      \n";
	cout << "| Created By: Benjamin Milian   \n";
	cout << "******************************************\n";
	cout << "Select File\n" << "Select Directory\n" << "Exit\n";
}

void Shred::SetCursorPosition(int _x, int _y)
{
	// First set the cursor position according to 
	// menu items
	COORD cursorPosition;
	cursorPosition.X = _x;
	cursorPosition.Y = _y;

	// set the cursor position after menu is displayed
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	
}



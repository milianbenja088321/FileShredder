// File Shredder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	// Data members
	bool isOn = true;
	char cursor = '<';
	int csrX = 20, csrY = 4;
	Shred file;

	

	while (isOn)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			isOn = false;

		if (GetAsyncKeyState(VK_UP))
		{
			// CHECK IF YOU ARE ALREADY AT THE TOP
			if (csrY == 4)
			{
				continue;
			}
			else
			{
				csrY--;
			}
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			// CHECK IF IT'S AT THE BOTTOM
			if (csrY == 6)
			{
				continue;
			}
			else
			{
				csrY++;
			}
		}
		
		if (GetAsyncKeyState(VK_RETURN))
		{
			// CHOOSE FILE (TEST)
			if (csrY == 4) { file.GetInputFile(); }
			// EXIT THE APPLICATION
			if (csrY == 6) { exit(0); }
		}

		file.Display();
		file.SetCursorPosition(csrX, csrY);
		
		cout << cursor;
		Sleep(500);
		system("cls");
	}
	system("pause");
}


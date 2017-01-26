#include "stdafx.h"
#include "Shred.h"
#include <string>


Shred::Shred()
{
}


Shred::~Shred()
{
}

void Shred::Display()
{
	for (int i = 0; i < 102; i++)
	{
		cout << '*';
	}

	cout << "\n| File Encryption Shredder      \n";
	cout << "| Created By: Benjamin Milian   \n";
	
	for (int i = 0; i < 102; i++)
	{
		cout << '*';
	}

	cout << "\nSelect File\n" << "Select Directory\n" << "Exit\n";
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

void Shred::GetInputFile()
{
	OPENFILENAME ofn = { 0 };
	TCHAR szFileName[MAX_PATH] = _T("");

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = 0;
	ofn.lpstrFilter = _T("Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0\0");
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = _T("txt");

	if (GetOpenFileName(&ofn))
	{
		MessageBox(NULL, szFileName, _T("File was selected"), MB_OK);
		ReadInFile(szFileName);
	}
}

void Shred::ReadInFile(TCHAR* _fileName)
{
	char str[255];
	ifstream myFile;
	myFile.open(_fileName);

	while (!myFile.eof())
	{
		myFile.getline(str, 255);
		cout << str << "\n";
	}
	system("pause");
	myFile.close();
}

void Shred::OverwriteFile(TCHAR* _fileName)
{
	
}






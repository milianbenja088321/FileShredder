#pragma once
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <fstream>

using namespace std;

class Shred
{
public:
	Shred();
	~Shred();
	void Display();
	void SetCursorPosition(int _x, int _y);
	void GetInputFile();
	void ReadInFile(TCHAR* _fileName);
	void OverwriteFile(TCHAR* _fileName);
};


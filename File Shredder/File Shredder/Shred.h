#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;
class Shred
{
public:
	Shred();
	~Shred();
	void Display();
	void SetCursorPosition(int _x, int _y);
};


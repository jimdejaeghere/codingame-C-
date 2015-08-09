#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getJump(int position, int previousPosition){
	int NumberOfJumps = 0;
	int difference = abs(position - previousPosition)+1;

	if ((difference / 2) == 0)
	{
		NumberOfJumps = 1;
	}
	else
	{
		NumberOfJumps = difference / 2;
	}

	return NumberOfJumps;
}

int main()
{

	int Width;
	int Height;
	cin >> Width >> Height; cin.ignore();
	cerr << "Width: " << Width << endl;
	cerr << "Height: " << Height << endl;
	--Width;
	--Height;
	int NumberOfJumps;
	cin >> NumberOfJumps; cin.ignore();
	cerr << "Number of jumps: " << NumberOfJumps << endl;
	int X0;
	int Y0;
	cin >> X0 >> Y0; cin.ignore();
	cerr << "X: " << X0 << endl << "Y: " << Y0 << endl;
	int jumpHorizontal = 0, jumpVertical = 0, previousX = Width, previousY = Height;

	// game loop
	while (1) {
		string BOMB_DIR;
		cin >> BOMB_DIR; cin.ignore();
		cerr << "Direction: " << BOMB_DIR << endl;

		if (BOMB_DIR == "U")
		{
			//jump up
			if (previousY == Height)
			{
				previousY = 1;
			}
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 -= jumpVertical;
		}
		else if (BOMB_DIR == "UR")
		{
			//jump up
			if (previousY == Height)
			{
				previousY = 1;
			}
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 -= jumpVertical;

			//jump right
			jumpHorizontal = getJump(X0, previousX-1);
			previousX = X0;
			X0 += jumpHorizontal;
		}
		else if (BOMB_DIR == "R")
		{
			//jump right
			jumpHorizontal = getJump(X0, previousX-1);
			previousX = X0;
			X0 += jumpHorizontal;
		}
		else if (BOMB_DIR == "DR")
		{
			//jump down
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 += jumpVertical;

			//jump right
			jumpHorizontal = getJump(X0, previousX-1);
			previousX = X0;
			X0 += jumpHorizontal;
		}
		else if (BOMB_DIR == "D")
		{
			//jump down
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 += jumpVertical;
		}
		else if (BOMB_DIR == "DL")
		{
			//jump down
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 += jumpVertical;

			//jump Left
			if (previousX == Width){
				previousX = 1;
			}
			jumpHorizontal = getJump(X0, previousX);
			previousX = X0;
			X0 -= jumpHorizontal;
		}
		else if (BOMB_DIR == "L")
		{
			//jump Left
			if (previousX == Width){
				previousX = 1;
			}
			jumpHorizontal = getJump(X0, previousX);
			previousX = X0;
			X0 -= jumpHorizontal;
		}
		else if (BOMB_DIR == "UL")
		{
			//jump up
			if (previousY == Height)
			{
				previousY = 1;
			}
			jumpVertical = getJump(Y0, previousY);
			previousY = Y0;
			Y0 -= jumpVertical;

			//jump Left
			if (previousX == Width){
				previousX = 1;
			}
			jumpHorizontal = getJump(X0, previousX);
			previousX = X0;
			X0 -= jumpHorizontal;
		}

		if (X0 > Width)
		{
			X0=Width;
		}

		if (Y0 > Height){
			Y0=Height;
		}

		cout << X0 << " " << Y0 << endl;
	}
}
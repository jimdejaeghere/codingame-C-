#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int W; // number of columns.
	int H; // number of rows.
	cin >> W >> H; cin.ignore();
	cerr << "Width: " << W << endl << "Height: " << H << endl;
	vector<vector<int>> lstNodes(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
		{
			cin >> lstNodes[i][j];
		}

	}
	int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
	cin >> EX; cin.ignore();

	string output = "";
	// game loop
	while (1) {
		int XI;
		int YI;
		string POS;
		cin >> XI >> YI >> POS; cin.ignore();

		int nodeType = lstNodes[YI][XI];

		switch (nodeType)
		{
		case 0:
			break;
		case 1:
		case 7:
		case 8:
		case 9:
			output = to_string(XI) + " " + to_string(YI + 1);
			break;
		case 2:
			if (POS == "LEFT")
			{
				output = to_string(XI + 1) + " " + to_string(YI);
			}
			else
			{
				output = to_string(XI - 1) + " " + to_string(YI);
			}
			break;
		case 3:
		case 12:
		case 13:
			output = to_string(XI) + " " + to_string(YI + 1);
			break;
		case 4:
			if (POS == "TOP"){
				output = to_string(XI - 1) + " " + to_string(YI);
			}
			else
			{
				output = to_string(XI) + " " + to_string(YI + 1);
			}
			break;
		case 5:
			if (POS == "TOP"){
				output = to_string(XI + 1) + " " + to_string(YI);
			}
			else
			{
				output = to_string(XI) + " " + to_string(YI + 1);
			}
			break;
		case 6:
			if (POS == "LEFT")
			{
				output = to_string(XI + 1) + " " + to_string(YI);
			}
			else
			{
				output = to_string(XI - 1) + " " + to_string(YI);
			}
			break;
		case 10:
			output = to_string(XI - 1) + " " + to_string(YI);
			break;
		case 11:
			output = to_string(XI + 1) + " " + to_string(YI);
			break;
		}

		cout << output << endl; // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
	}
}
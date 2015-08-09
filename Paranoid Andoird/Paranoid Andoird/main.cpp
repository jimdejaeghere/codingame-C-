#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Elevator {
	int floor;
	int position;
	bool operator() (Elevator i, Elevator j) { return (i.floor < j.floor); }
} elevator;

int main()
{
	vector<Elevator> lstElevators;
	int nbFloors;
	int width;
	int nbRounds;
	int exitFloor;
	int exitPos;
	int nbTotalClones;
	int nbAdditionalElevators;
	int nbElevators;
	cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
	for (int i = 0; i < nbElevators; i++) {
		Elevator elv;
		cin >> elv.floor >> elv.position; cin.ignore();
		lstElevators.push_back(elv);
		sort(lstElevators.begin(), lstElevators.end(), elevator);
	}
	while (1) {
		string output = "WAIT";
		int cloneFloor;
		int clonePos;
		string direction;
		cin >> cloneFloor >> clonePos >> direction; cin.ignore();
		cerr << "Clone floor:" << cloneFloor << endl << "Clone pos: " << clonePos << endl;
		cerr << "Direction: " << direction << endl;

		if (cloneFloor != -1)
		{
			if (cloneFloor == exitFloor)
			{
				if (clonePos > exitPos && direction == "RIGHT")
				{
					output = "BLOCK";
				}
				if (clonePos < exitPos && direction == "LEFT")
				{
					output = "BLOCK";
				}
			}
			else
			{
				if (clonePos > lstElevators[cloneFloor].position && direction == "RIGHT")
				{
					output = "BLOCK";
				}
				if (clonePos < lstElevators[cloneFloor].position && direction == "LEFT")
				{
					output = "BLOCK";
				}
			}
		}
		cout << output << endl;
	}
}
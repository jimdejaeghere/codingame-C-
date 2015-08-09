#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Don't let the machines win. You are humanity's last hope...
**/
int test()
{
	int width; // the number of cells on the X axis
	cin >> width; cin.ignore();
	int height; // the number of cells on the Y axis
	cin >> height; cin.ignore();
	cerr << "width: " << width << endl << "height :" << height << endl;
	for (int i = 0; i < height; i++) {
		string line; // width characters, each either 0 or .
		getline(cin, line);
		cerr << "string :" << line << endl;
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << "0 0 1 0 0 1" << endl; // Three coordinates: a node, its right neighbor, its bottom neighbor

	return 0;
}
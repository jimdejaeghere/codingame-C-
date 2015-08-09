#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string findNodeRight(vector<vector<char>> nodes, int width, int height){
	string output;

	for (int i = width + 1; i < nodes[0].size(); i++)
	{
		if (nodes[height][i] == '0')
		{
			output = ' ' + to_string(i) + ' ' + to_string(height);
			return output;
		}
		else if (nodes[height][i] == '.')
		{
			continue;
		}
		else {
			output = " -1 -1";
			return output;
		}
	}
}

string findNodeBelow(vector<vector<char>> nodes, int width, int height){
	string output;

	for (int i = height + 1; i < nodes.size(); i++)
	{
		if (nodes[i][width] == '0')
		{
			output = ' ' + to_string(width) + ' ' + to_string(i);
			return output;
		}
		else if (nodes[i][width] == '.')
		{
			continue;
		}
		else {
			output = " -1 -1";
			return output;
		}
	}
}

int main()
{
	int width; // the number of cells on the X axis
	cin >> width; cin.ignore();
	int height; // the number of cells on the Y axis
	cin >> height; cin.ignore();
	//cerr << "width: " << width << endl << "height :" << height << endl;

	vector<vector<char>> nodes;

	nodes.resize(height + 1);
	for (int i = 0; i < height + 1; ++i){
		nodes[i].resize(width + 1);
	}

	//read the grid
	for (int i = 0; i < height; i++) {
		vector<char> temp;
		string line;
		getline(cin, line);
		cerr << "string :" << line << endl;
		for (int j = 0; j < width; j++)
		{
			nodes[i][j] = line[j];
		}
	}

	for (int iHeight = 0; iHeight < height; iHeight++) {

		for (int jWidth = 0; jWidth < width; jWidth++)
		{
			string output = "";
			string temp;

			if (nodes[iHeight][jWidth] == '0')
			{
				nodes[iHeight][jWidth] = '.';
				output += to_string(jWidth) + " " + to_string(iHeight);
				temp = findNodeRight(nodes, jWidth, iHeight);
				output += temp;
				temp = findNodeBelow(nodes, jWidth, iHeight);
				output += temp;
				cout << output << endl;
			}

		}
	}

}
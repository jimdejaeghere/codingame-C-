#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int L;
	cin >> L; cin.ignore();
	int H;
	cin >> H; cin.ignore();
	string T;
	getline(cin, T);
	vector<string> ascii;
	for (int i = 0; i < H; i++) {
		string ROW;
		getline(cin, ROW);
		ascii.push_back(ROW);
	}

	string output = "";

	for (int j = 0; j != H; j++)
	{

		for (int i = 0; i < T.size(); i++)
		{
			int asciiVal = T[i];

			if (asciiVal >= 65 && asciiVal <= 90)
			{
				asciiVal -= 65;
			}
			else if (asciiVal >= 97 && asciiVal <= 122)
			{
				asciiVal -= 97;
			}

			string temp = ascii[j];

			for (int k = 0; k < L; k++)
			{
				output += temp[k + (asciiVal * L)];
			}			
		}

		output += "\n";

	}

	cout << output << endl;
	return 0;
}
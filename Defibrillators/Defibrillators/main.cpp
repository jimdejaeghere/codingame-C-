#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Defib{
	int number;
	string name;
	string adress;
	string phoneNumber;
	double longtitude;
	double latitude;
};

void split(const string& s, char c,
	vector<string>& v) {
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

int main()
{
	vector<Defib> lstDefib;

	string LON;
	cin >> LON; cin.ignore();
	replace(LON.begin(), LON.end(), ',', '.');
	double dblLon = atof(LON.c_str());
	string LAT;
	cin >> LAT; cin.ignore();
	replace(LAT.begin(), LAT.end(), ',', '.');
	double dblLat = atof(LAT.c_str());
	int N;
	cin >> N; cin.ignore();

	for (int i = 0; i < N; i++) {
		Defib myDefib;
		string DEFIB;
		getline(cin, DEFIB);
		vector<string> tokens;
		split(DEFIB, ';', tokens);

		myDefib.number = stoi(tokens[0]);
		myDefib.name = tokens[1];
		myDefib.adress = tokens[2];
		myDefib.phoneNumber = tokens[3];
		replace(tokens[4].begin(), tokens[4].end(), ',', '.');
		myDefib.longtitude = atof(tokens[4].c_str());
		replace(tokens[5].begin(), tokens[5].end(), ',', '.');
		myDefib.latitude = atof(tokens[5].c_str());
		lstDefib.push_back(myDefib);
	}

	double x = 0.0;
	double y = 0.0;
	double d = 0.0;
	double smallest = -1;
	int closest = 0;

	for (size_t i = 0; i < lstDefib.size(); i++)
	{
		Defib myDefib = lstDefib[i];

		x = (myDefib.longtitude - dblLon) * cos((dblLat + myDefib.latitude) / 2);
		y = myDefib.latitude - dblLat;

		d = sqrt((pow(x, 2) + pow(y, 2))) * 6371;

		if (smallest != -1)
		{
			if (d < smallest)
			{
				smallest = d;
				closest = i;
			}
		}
		else {
			smallest = d;
			closest = i;
		}

	}
	cout << lstDefib[closest].name << endl;
}
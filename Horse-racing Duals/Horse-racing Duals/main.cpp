#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	vector<int> lstHorses;

	int N;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		int Pi;
		cin >> Pi; cin.ignore();
		lstHorses.push_back(Pi);		
	}

	sort(lstHorses.begin(), lstHorses.end());

	int smallest = abs(lstHorses[0] - lstHorses[1]);

	for (int i = 1; i < lstHorses.size() - 1; i++)
	{
			int temp = abs(lstHorses[i] - lstHorses[i + 1]);
			if (smallest > temp)
			{
				smallest = temp;
			}

	}

	cout << smallest << endl;
}
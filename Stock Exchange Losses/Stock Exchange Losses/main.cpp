#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	vector<int> quotes;
	int largerst, smallest, tmpOutput = 0, output = 0;
	int n;
	cin >> n; cin.ignore();
	string vs;
	for (int i = 0; i < n; i++)
	{
		string strQuote;
		cin >> strQuote;
		int iQuote = stoi(strQuote);
		quotes.push_back(iQuote);
		if (i == 0)
		{
			largerst = iQuote;
			smallest = iQuote;
		}
	}

	for (int i = 0; i < quotes.size(); ++i)
	{
		if (quotes[i] > largerst){
			largerst = quotes[i];
			smallest = quotes[i];
		}

		if (quotes[i] < smallest){
			smallest = quotes[i];
		}

		tmpOutput = smallest - largerst;

		if (tmpOutput < output){
			output = tmpOutput;
		}
	}

	cout << output << endl;
}
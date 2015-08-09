#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

void toLowerCase(string &input){

	for (int i = 0; i < input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}

}

string getExtension(const string input){

	string output;

	size_t found = input.find_last_of(".");

	output = input.substr(found + 1);

	if (found > input.size())
	{
		return "";
	}
	else {
		return output;
	}	

}

int main()
{
	int N; // Number of elements which make up the association table.
	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();
	string output = "";
	vector<string> EXT;
	vector<string> MT;
	vector<string> FNAME;

	for (int i = 0; i < N; i++) {
		string tmpExt; // file extension
		string tmpMt; // MIME type.
		cin >> tmpExt >> tmpMt; cin.ignore();
		//toLowerCase(tmpExt);
		transform(tmpExt.begin(), tmpExt.end(), tmpExt.begin(), ::tolower);
		EXT.push_back(tmpExt);
		MT.push_back(tmpMt);
	}

	for (int i = 0; i < Q; i++) {
		string tmpFName; // One file name per line.
		getline(cin, tmpFName);
		//toLowerCase(tmpFName);
		transform(tmpFName.begin(), tmpFName.end(), tmpFName.begin(), ::tolower);
		FNAME.push_back(tmpFName);
	}

	for (int i = 0; i != FNAME.size(); i++)
	{
		string tmpString = FNAME[i];
		string extension = getExtension(tmpString);

		int it = (find(EXT.begin(), EXT.end(), extension) - EXT.begin());

		if (it >= EXT.size()) {
			cout << "UNKNOWN" << endl;
		}
		else {
			cout << MT[it] << endl;
		}

	}

}
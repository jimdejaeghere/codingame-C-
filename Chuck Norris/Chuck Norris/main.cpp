#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);
	string answer = "";
	string binary = "";

	for (size_t i = 0; i < MESSAGE.size(); i++)
	{
		int Ibinary = MESSAGE[i];

		binary += std::bitset< 7 >(Ibinary).to_string();
	}

	char last = '2';

	for (size_t j = 0; j < binary.size(); j++)
	{
		if (binary[j] != last){
			last = binary[j];
			if (binary[j] == '0'){
				answer += " 00 ";
			}
			else {
				answer += " 0 ";
			}
		}
		answer += "0";
	}

	answer.erase(0, 1);

	cout << answer << endl;
}
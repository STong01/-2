#include <iostream>
#include <string>
using namespace std;

string FindNum(string str)
{
	string s;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			s += str[i];
		}
	}
	return s;
}

int main1()
{
	string str;
	while (getline(cin , str))
	{
		cout << FindNum(str) << endl;
	}
	system("pause");
	return 0;
}
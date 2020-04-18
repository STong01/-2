#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'w')
			{
				str[i] += 3;
			}
			else if (str[i]>'w' && str[i] <= 'z')
			{
				str[i] = str[i] - 23;
			}
		}
		cout << str << endl;
	}

	return 0;
}
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main1()
{
	int num;
	string str;
	string tmp = "22233344455566677778889999";
	while (cin >> num)
	{
		set<string> teb;
		for (int i = 0; i < num; i++)
		{
			int val = 0;
			string cur;
			cin >> str;
			for (int i = 0; i < str.size(); i++)
			{
				if (val == 3)
				{
					cur += '-';
					val++;
					if (str[i] >= 'A' && str[i] <= 'Z')
					{
						cur += tmp[str[i] - 'A'];
						val++;
					}
					else if (str[i] >= '0' && str[i] <= '9')
					{
						cur += str[i];
						val++;
					}
				}
				else
				{
					if (str[i] >= 'A' && str[i] <= 'Z')
					{
						cur += tmp[str[i] - 'A'];
						val++;
					}
					else if (str[i] >= '0' && str[i] <= '9')
					{
						cur += str[i];
						val++;
					}
				}
			}
			teb.insert(cur);
		}
		for (set<string>::iterator j = teb.begin(); j != teb.end(); j++)
		{
			cout << *j << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
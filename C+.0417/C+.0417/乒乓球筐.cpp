#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test(vector<int> v1, vector<int> v2)
{
	if (v1.size() < v2.size())
	{
		cout << "No" << endl;
	}
	else
	{
		for (int i = 0; i < v2.size(); i++)
		{
			if (v2[i] > v1[i])
			{
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
	}
}

int main1()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<int> v1(26, 0);
		vector<int> v2(26, 0);
		for (int i = 0; i < str1.size(); i++)
		{
			v1[str1[i] - 'A']++;
		}
		for (int j = 0; j < str2.size(); j++)
		{
			v2[str2[j] - 'A']++;
		}
		test(v1, v2);

	}

	system("pause");
	return 0;
}

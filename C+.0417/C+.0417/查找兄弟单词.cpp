#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool test(string str1, string str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}
	else
	{
		if (str1 != str2)
		{
			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());
			if (str1 == str2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	int sum;
	while (cin >> sum)
	{
		string str;
		string str0, st;
		int num;
		vector<string> dic;
		for (int i = 0; i < sum; ++i)
		{
			cin >> str;
			dic.push_back(str);
		}

		sort(dic.begin(), dic.end());
		cin >> str0;
		cin >> num;

		int counts = 0;//总的兄弟单词个数

		for (int i = 0; i < sum; ++i)
		{
			if (test(str0, dic[i]))
			{
				counts++;
				if (counts == num)
				{
					st = dic[i];
				}
			}
		}

		if (!dic.empty())
		{
			cout << counts << endl;
		}
		if (counts >= num)
		{
			cout << st << endl;
		}
	}
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int hashtable[256] = { 0 };
		for (auto&e : str)
		{
			hashtable[e]++;
		}

		int i, sum = 0;
		for (i = 0; i < str.size(); i++)
		{
			if (hashtable[str[i]] == 1)
			{
				cout << str[i] << endl;
				break;//第一个只出现一次的字符
				//sum++;//只出现一次的字符
			}
		}

		//第一个只出现一次的字符
		if (i >= str.size())
		{
			cout << -1 << endl;
		}

		//只出现一次的字符
		/*if (sum == 0)
		{
			cout << -1 << endl;
		}*/
	}
	system("pause");
	return 0;
}
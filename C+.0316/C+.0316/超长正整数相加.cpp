#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addstring(string num1, string num2)
{
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string sum = "";

	int cur = 0;
	//逐位相加
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			cur += num1[i] - '0';
		}
		if (j >= 0)
		{
			cur += num2[j] - '0';
		}

		sum += char(cur % 10 + '0');

		//当数字大于10的时候产生进位
		cur /= 10;
		i--;
		j--;
	}

	//加完之后，若还存在进位，则前置加1
	if (cur == 1)
	{
		sum += '1';
	}

	//倒置数字
	reverse(sum.begin(), sum.end());
	return sum;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addstring(s1, s2) << endl;
	}
	system("pause");
	return 0;
}
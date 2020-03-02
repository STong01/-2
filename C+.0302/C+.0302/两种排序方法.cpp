#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;//输入字符串个数
	cin >> n;
	vector<string> s1;
	s1.resize(n);
	for (auto& str : s1)
	{
		cin >> str;//输入字符串
	}

	bool lenSym = true;//长度判断
	bool lexSym = true;// 字典序排序

	//验证长度排序
	for(size_t i = 1; i < s1.size(); i++)
	{
		if (s1[i - 1].size() >= s1[i].size())
		{
			lenSym = false;
			break;
		}
	}

	//验证字典序排序
	for (size_t i = 1; i < s1.size(); i++)
	{
		if (s1[i - 1] >= s1[i])
		{
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym)
	{
		cout << "both" << endl;
	}
	else if (!lenSym && lexSym)
	{
		cout << "lexicographically" << endl;
	}
	else if (lenSym && !lexSym)
	{
		cout << "lengths" << endl;
	}
	else if (!lenSym && !lexSym)
	{
		cout << "none" << endl;
	}

	system("pause");
	return 0;
}
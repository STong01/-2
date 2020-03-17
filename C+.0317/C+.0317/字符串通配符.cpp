#include <iostream>
#include <string>
using namespace std;

//字符串通配符
bool test(const char* tmp, const char* str)
{
	//当两个字符串同时结束时候，返回真
	if (*tmp == '\0' && *str == '\0')
	{
		return true;
	}

	//当其中有一个字符串首先结束，返回假
	if (*tmp == '\0' || *str == '\0')
	{
		return false;
	}

	//'?'通配一个字符，继续递归下一个字符
	if (*tmp == '?')
	{
		return test(tmp + 1, str + 1);
	}
	//'*'通配不计数字符，直接递归str的下一个字符
	else if (*tmp == '*')
	{
		return test(tmp + 1, str) || test(tmp + 1, str + 1) || test(tmp, str + 1);
	}
	else if (*tmp == *str)
	{
		return test(tmp + 1, str + 1);
	}
	return false;
}

int main()
{
	string tmp, str;
	while (cin >> tmp >> str)
	{
		bool ret = test(tmp.c_str(), str.c_str());
		if (ret)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	system("pause");
	return 0;
}
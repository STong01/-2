#include <iostream>
#include <string>
using namespace std;

//参数解析
int main1()
{
	string s1;
	while (getline(cin, s1))
	{
		int sum = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == ' ')
			{
				sum++;
			}
			//判断有没有双引号，双引号中的空格是需要打印出来的
			if (s1[i] == '"')
			{
				do
				{
					i++;
				} while (s1[i] != '"');
			}
		}
		cout << sum + 1<< endl;

		int flag = 1;
		for (int i = 0; i < s1.size(); i++)
		{
			//有双引号，下一次遇见双引号，flag异或
			if (s1[i] == '"')
			{
				flag ^= 1;
			}
			//双引号和普通空格不需要打印
			if (s1[i] != ' ' && s1[i] != '"')
			{
				cout << s1[i];
			}
			//双引号中的空格打印
			if (s1[i] == ' ' && (!flag))
			{
				cout << s1[i];
			}
			//遇到双引号之外的空格换行
			if (s1[i] == ' ' && flag)
			{
				cout<<endl;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
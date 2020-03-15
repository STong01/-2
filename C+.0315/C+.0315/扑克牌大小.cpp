#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//扑克牌大小
int main()
{
	string str;
	while (getline(cin, str))
	{
		//当扑克牌中出现对王的时候，对王最大直接输出
		if (str.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
		}
		else
		{
			int tmp = str.find('-');

			//在输入字符串中，将两个输入的手牌分开
			string str1 = str.substr(0, tmp);
			string str2 = str.substr(tmp + 1);

			//首先计算两个手牌的牌个数
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');

			//当手牌个数相同的时候，直接比较第一个手牌
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string cur = "345678910JQKA2jokerJOKER";

			if (c1 == c2)
			{
				if (cur.find(first1) > cur.find(first2))
				{
					cout << str1 << endl;
				}
				else
				{
					cout << str2 << endl;
				}
			}
			else
			{
				//当手牌个数不统一的时候，说明类型不同，此时只有炸弹可以和其他牌比较
				if (c1 == 3)
				{
					cout << str1 << endl;
				}
				else if (c2 == 3)
				{
					cout << str2 << endl;
				}
				else
				{
					cout << "ERROR" << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}
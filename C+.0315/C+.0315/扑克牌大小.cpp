#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//�˿��ƴ�С
int main()
{
	string str;
	while (getline(cin, str))
	{
		//���˿����г��ֶ�����ʱ�򣬶������ֱ�����
		if (str.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
		}
		else
		{
			int tmp = str.find('-');

			//�������ַ����У���������������Ʒֿ�
			string str1 = str.substr(0, tmp);
			string str2 = str.substr(tmp + 1);

			//���ȼ����������Ƶ��Ƹ���
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');

			//�����Ƹ�����ͬ��ʱ��ֱ�ӱȽϵ�һ������
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
				//�����Ƹ�����ͳһ��ʱ��˵�����Ͳ�ͬ����ʱֻ��ը�����Ժ������ƱȽ�
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
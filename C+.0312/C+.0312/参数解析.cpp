#include <iostream>
#include <string>
using namespace std;

//��������
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
			//�ж���û��˫���ţ�˫�����еĿո�����Ҫ��ӡ������
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
			//��˫���ţ���һ������˫���ţ�flag���
			if (s1[i] == '"')
			{
				flag ^= 1;
			}
			//˫���ź���ͨ�ո���Ҫ��ӡ
			if (s1[i] != ' ' && s1[i] != '"')
			{
				cout << s1[i];
			}
			//˫�����еĿո��ӡ
			if (s1[i] == ' ' && (!flag))
			{
				cout << s1[i];
			}
			//����˫����֮��Ŀո���
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
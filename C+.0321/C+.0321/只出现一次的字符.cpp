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
				break;//��һ��ֻ����һ�ε��ַ�
				//sum++;//ֻ����һ�ε��ַ�
			}
		}

		//��һ��ֻ����һ�ε��ַ�
		if (i >= str.size())
		{
			cout << -1 << endl;
		}

		//ֻ����һ�ε��ַ�
		/*if (sum == 0)
		{
			cout << -1 << endl;
		}*/
	}
	system("pause");
	return 0;
}
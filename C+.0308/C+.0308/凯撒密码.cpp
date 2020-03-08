#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string str1;
	int key;

	cout << "请输入明文:" << endl;
	getline(cin, str1);
	cout << "请输入密钥:" << endl;
	cin >> key;
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] <= 'Z' && str1[i] >= 'A')
		{
			str1[i] += key;
			if (str1[i] > 'Z')
			{
				str1[i] -= 26;
			}
		}
	}
	cout << "输出密文:"<< str1 << endl;

	system("pause");
	return 0;
}
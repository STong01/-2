#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string str1;
	int key;

	cout << "����������:" << endl;
	getline(cin, str1);
	cout << "��������Կ:" << endl;
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
	cout << "�������:"<< str1 << endl;

	system("pause");
	return 0;
}
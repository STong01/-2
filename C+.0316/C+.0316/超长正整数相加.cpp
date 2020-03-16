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
	//��λ���
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

		//�����ִ���10��ʱ�������λ
		cur /= 10;
		i--;
		j--;
	}

	//����֮���������ڽ�λ����ǰ�ü�1
	if (cur == 1)
	{
		sum += '1';
	}

	//��������
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
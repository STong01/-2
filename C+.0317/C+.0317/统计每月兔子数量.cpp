#include <iostream>
using namespace std;

//ͳ��ÿ����������
int main1()
{
	int month;
	while (cin >> month)
	{
		int first = 1;
		int second = 1;
		int sum;

		//�����������µ�ʱ��ֻ��һֻ����
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
			continue;
		}

		//������������֮��ÿ����һ���£�ǰһ���µ����Ӵ����ǰ�����µ������Ѿ������������������Կ���������һ��
		for (int i = 3; i <= month; i++)
		{
			sum = first + second;
			first = second;
			second = sum;
		}

		cout << sum << endl;
	}

	system("pause");
	return 0;
}
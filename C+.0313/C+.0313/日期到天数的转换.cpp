#include <iostream>
using namespace std;

//�������ڵ�������ת��
int main1()
{
	//����ÿ���µ��·��ۼ�����
	int tmp[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += tmp[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
			{
				//�ж��ǲ������꣬����+1
				sum += 1;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

//计算日期到天数的转换
int main1()
{
	//保存每个月的月份累计天数
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
				//判断是不是闰年，闰年+1
				sum += 1;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
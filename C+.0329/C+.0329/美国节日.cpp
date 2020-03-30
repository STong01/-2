#include <iostream>
#include <vector>
using namespace std;

vector<int> mon1 = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> mon2 = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


//判断是不是闰年
bool IsLeap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//元旦
void NewYearDay(int year)
{
	cout << year << "-0" << 1 << "-0" << 1 << endl;
}

//国庆
void NationalDay(int year)
{
	cout << year << "-0" << 7 << "-0" << 4 << endl;
}

//圣诞
void Christmas(int year)
{
	cout << year << "-" << 12 << "-" << 25 << endl;
	cout << endl;
}

//mon月的第n个星期day
void test1(int year, int mon, int n, int day)
{
	int d_sum = 0;
	//按照年份增加天数
	for (int i = 2000; i < year; i++)
	{
		if (IsLeap(i))
		{
			d_sum += 366;
		}
		else
		{
			d_sum += 365;
		}
	}
	//按照月份增加天数
	for (int j = 1; j < mon; j++)
	{
		if (IsLeap(year))
		{
			d_sum += mon1[j];
		}
		else
		{
			d_sum += mon2[j];
		}
	}

	//d_sum += 1;
	//判断year年mon月01号是周几
	int day_p = ((d_sum % 7) + 6) % 7;
	if (day_p <= day)
	{
		day_p = (day - day_p + 1);
		for (int i = 0; i < n - 1; i++)
		{
			day_p += 7;
		}
	}
	else
	{
		day_p = (day + 7 - day_p + 1);
		for (int i = 0; i < n - 1; i++)
		{
			day_p += 7;
		}
	}

	if (mon >= 10)
	{
		if (day_p >= 10)
		{
			cout << year << "-" << mon << "-" << day_p << endl;
		}
		else
		{
			cout << year << "-" << mon << "-0" << day_p << endl;
		}
	}
	else
	{
		if (day_p >= 10)
		{
			cout << year << "-0" << mon << "-" << day_p << endl;
		}
		else
		{
			cout << year << "-0" << mon << "-0" << day_p << endl;
		}
	}
}

//mon月的倒数第n个星期day
void test2(int year, int mon, int n, int day)
{
	int d_sum = 0;
	int days = 0;
	//按照年份增加天数
	for (int i = 2000; i < year; i++)
	{
		if (IsLeap(i))
		{
			d_sum += 366;
		}
		else
		{
			d_sum += 365;
		}
	}
	//按照月份增加天数
	for (int j = 1; j <= mon; j++)
	{
		if (IsLeap(year))
		{
			d_sum += mon1[j];
		}
		else
		{
			d_sum += mon2[j];
		}
	}

	d_sum -= 1;
	//判断year年mon+1月01号是周几
	int day_p = ((d_sum % 7) + 6) % 7;
	//从mon月的最后一天倒着数回来
	if (IsLeap(year))
	{
		days = mon1[mon];
	}
	else
	{
		days = mon2[mon];
	}

	if (day_p >= day)
	{
		days -= (day_p - day);
		for (int i = 0; i < n - 1; i++)
		{
			days -= 7;
		}
	}
	else 
	{
		days -= (day_p + 7 - day);
		for (int i = 0; i < n - 1; i++)
		{
			day_p -= 7;
		}
	}

	if (mon >= 10)
	{
		if (days >= 10)
		{
			cout << year << "-" << mon << "-" << days << endl;
		}
		else
		{
			cout << year << "-" << mon << "-0" << days << endl;
		}
	}
	else
	{
		if (days >= 10)
		{
			cout << year << "-0" << mon << "-" << days << endl;
		}
		else
		{
			cout << year << "-0" << mon << "-0" << days << endl;
		}
	}
}


int main()
{
	int year;
	while (cin >> year)
	{
		NewYearDay(year);
		test1(year, 1, 3, 1);
		test1(year, 2, 3, 1);
		test2(year, 5, 1, 1);
		NationalDay(year);
		test1(year, 9, 1, 1);
		test1(year, 11, 4, 4);
		Christmas(year);
	}

	system("pause");
	return 0;
}
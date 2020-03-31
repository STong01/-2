#include <iostream>
#include <vector>
using namespace std;

vector<int> month1 = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> month2 = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

//判断月份是否为素数
bool IsPrime(int n)
{
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
	{
		return true;
	}
	return false;
}

int test(int year1, int mon1, int day1, int year2, int mon2, int day2)
{
	int day = 0;
	int money = 0;
	if (year1 == year2)
	{
		if (mon1 == mon2)
		{
			day = day2 - day1 + 1;
			if (IsPrime(mon1))
			{
				money += day * 1;
			}
			else
			{
				money += day * 2;
			}
		}
		else
		{
			if (IsLeap(year1))
			{
				day = month1[mon1] - day1 + 1;
				if (IsPrime(mon1))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
				for (int i = mon1 + 1; i < mon2; i++)
				{
					day = month1[i];
					if (IsPrime(i))
					{
						money += day * 1;
					}
					else
					{
						money += day * 2;
					}
				}
				if (IsPrime(mon2))
				{
					money += day2 * 1;
				}
				else
				{
					money += day2 * 2;
				}
			}
			else
			{
				day = month2[mon1] - day1 + 1;
				if (IsPrime(mon1))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
				for (int i = mon1 + 1; i < mon2; i++)
				{
					day = month2[i];
					if (IsPrime(i))
					{
						money += day * 1;
					}
					else
					{
						money += day * 2;
					}
				}
				if (IsPrime(mon2))
				{
					money += day2 * 1;
				}
				else
				{
					money += day2 * 2;
				}
			}
		}
	}
	else
	{
		if (IsLeap(year1))
		{
			day = month1[mon1] - day1 + 1;
			if (IsPrime(mon1))
			{
				money += day * 1;
			}
			else
			{
				money += day * 2;
			}
			for (int i = mon1 + 1; i <= 12; i++)
			{
				day = month1[i];
				if (IsPrime(i))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
			}
		}
		else
		{
			day = month2[mon1] - day1 + 1;
			if (IsPrime(mon1))
			{
				money += day * 1;
			}
			else
			{
				money += day * 2;
			}
			for (int i = mon1 + 1; i <= 12; i++)
			{
				day = month2[i];
				if (IsPrime(i))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
			}
		}
		for (int i = year1 + 1; i < year2; i++)
		{
			if (IsLeap(i))
			{
				for (int i = 1; i <= 12; i++)
				{
					day = month1[i];
					if (IsPrime(i))
					{
						money += day * 1;
					}
					else
					{
						money += day * 2;
					}
				}
			}
			else
			{
				for (int i = 1; i <= 12; i++)
				{
					day = month2[i];
					if (IsPrime(i))
					{
						money += day * 1;
					}
					else
					{
						money += day * 2;
					}
				}
			}
		}
		if (IsLeap(year2))
		{
			for (int i = 1; i < mon2; i++)
			{
				day = month1[i];
				if (IsPrime(i))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
			}
			if (IsPrime(mon2))
			{
				money += day2 * 1;
			}
			else
			{
				money += day2 * 2;
			}
		}
		else
		{
			for (int i = 1; i < mon2; i++)
			{
				day = month2[i];
				if (IsPrime(i))
				{
					money += day * 1;
				}
				else
				{
					money += day * 2;
				}
			}
			if (IsPrime(mon2))
			{
				money += day2 * 1;
			}
			else
			{
				money += day2 * 2;
			}
		}
	}
	return money;
}

int main1()
{
	int year1, year2;
	int mon1, mon2;
	int day1, day2;
	while (cin >> year1 >> mon1 >> day1 >> year2 >> mon2 >> day2)
	{
		cout << test(year1, mon1, day1, year2, mon2, day2)<<endl;
	}

	system("pause");
	return 0;
}
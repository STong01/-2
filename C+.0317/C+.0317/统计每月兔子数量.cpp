#include <iostream>
using namespace std;

//统计每月兔子数量
int main1()
{
	int month;
	while (cin >> month)
	{
		int first = 1;
		int second = 1;
		int sum;

		//当不满足三月的时候，只有一只兔子
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
			continue;
		}

		//当满足三个月之后，每到下一个月，前一个月的兔子存货，前两个月的兔子已经存在生育能力，所以可以再生育一批
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
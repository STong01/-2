#include <iostream>
#include <vector>
using namespace std;

//升级之路
//求两个数的最大公约数
int GCD(int n, int m)
{
	int num;
	while (num = n % m)
	{
		n = m;
		m = num;
	}
	return m;
}

int main1()
{
	//n为怪兽数目，power为每个怪兽的能量值
	int n, power;
	vector<int>nums;

	while (cin >> n >> power)
	{
		nums.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		
		for (int j = 0; j < n; j++)
		{
			//若怪兽的能量值小于玩家的能量值，则玩家打败怪兽，获取怪兽的全部能量值
			if (nums[j] < power)
			{
				power += nums[j];
			}
			//若怪兽的能量值大于或者等于玩家的能量值，则玩家打败怪兽，获取公约数的能量值
			else
			{
				power += GCD(power, nums[j]);
			}
		}
		cout << power << endl;
	}
	system("pause");
	return 0;
}
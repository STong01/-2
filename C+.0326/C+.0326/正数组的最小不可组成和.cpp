#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int getminsum(vector<int>& arr, int length)
	{
		int max = 0;
		int min = arr[0];
		//确定组合判断范围值
		for (int i = 0; i < length; i++)
		{
			max += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}

		vector<int> p(max + 1, 0);
		for (int i = 0; i < length; i++)
		{
			for (int j = max; j >= arr[i]; j--)
			{
				//dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的重量后还能放置的最大重量
				//对每个承重计算当前最大能放置重量
				if (p[j] < p[j - arr[i]] + arr[i])
				{
					//更新背包中能够放入的最大值
					p[j] = p[j - arr[i]] + arr[i];
				}
				else
				{
					p[j] = p[j];
				}
			}
		}
		for (int i = min; i <= max; i++)
		{
			if (i != p[i])
			{
				return i;
			}
		}
		return max + 1;
	}
};

int main1()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		solution s;
		cout << s.getminsum(a, n) << endl;
	}
	system("pause");
	return 0;
}
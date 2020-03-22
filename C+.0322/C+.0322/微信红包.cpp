#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class H_bao1
{
public:
	int getval(vector<int> gifts, int n)
	{
		sort(gifts.begin(), gifts.end());
		int mid = gifts[n / 2];
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == mid)
			{
				sum++;
			}
		}

		if (sum>n / 2)
		{
			return mid;
		}
		else
		{
			return 0;
		}
	}
};

//class H_bao2
//{
//public:
//	int getval(vector<int>gifts, int n)
//	{
//		map<int, int> sum;
//		int mid = gifts.size() / 2;
//		for (const auto& e : gifts)
//		{
//			sum[e]++;
//		}
//		for (const auto&e : sum)
//		{
//			if (e.second >= mid)
//			{
//				return e.first;
//			}
//		}
//		return 0;
//	}
//};

int main1()
{
	H_bao1 bao;
	vector<int> gifts = { 1, 4, 4, 4, 2 };
	int n = gifts.size();
	int p = bao.getval(gifts, n);
	cout << p << endl;

	system("pause");
	return 0;
}

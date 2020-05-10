#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		vector<int> num;
		num.resize(n);
		int max_num = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
			max_num = max(max_num, num[i]);
		}

		vector<int> sum(max_num + 1, 0);
		for (int i = 0; i < n; i++)
		{
			sum[num[i]]++;
		}

		int k;
		cin >> k;
		int k1 = 1;
		for (int i = 0; i <= max_num; i++)
		{
			if (sum[i] != 0 && k1 == k)
			{
				cout << i << endl;
				break;
			}
			else if (sum[i] != 0)
			{
				k1++;
			}
		}
	}

	system("pause");
	return 0;
}
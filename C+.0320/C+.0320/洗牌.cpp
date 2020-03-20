#include <iostream>
#include <vector>
using namespace std;

//洗牌
int main1()
{
	int T, n, k;
	//T确定需要洗几副牌
	cin >> T;
	while (T--)
	{
		//n为1/2牌数，k为这副牌需要洗的次数
		cin >> n>>k;
		int num = 2 * n;
		vector<int>table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}

		while (k--)
		{
			vector<int>tmp(table.begin(), table.end());
			for (int i = 0; i < n; i++)
			{
				table[2 * i] = tmp[i];
				table[2 * i + 1] = tmp[i + n];
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << table[i] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

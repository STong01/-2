#include <iostream>
#include <string>
#include <vector>
using namespace std;

//杨辉三角变形
int main1()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> tmp(n, vector<int>(m, 0));
		tmp[0][0] = 1;

		//构建变形杨辉三角
		for (int i = 1; i < n; i++)
		{
			tmp[i][0] = tmp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; j++)
			{
				if (j == 1)
				{
					tmp[i][j] = tmp[i - 1][j - 1] + tmp[i - 1][j];
				}
				else
				{
					tmp[i][j] = tmp[i - 1][j - 2] + tmp[i - 1][j - 1] + tmp[i - 1][j];
				}
			}
		}

		//记录第一个偶数的位置坐标
		int k;
		for (k = 0; k < m; k++)
		{
			if (tmp[n - 1][k] % 2 == 0 && tmp[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == m)
		{
			cout << -1 << endl;
		}
	}
	system("pause");
	return 0;
}
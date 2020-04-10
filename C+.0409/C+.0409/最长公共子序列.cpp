#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2) 
	{
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int> > dp(len1, vector<int>(len2, 0));
		// 进行边界初始化
		if (s1[0] == s2[0])
		{
			dp[0][0] = 1;
		}
		else
		{
			dp[0][0] = 0;
		}
		for (int i = 1; i < len1; i++)
		{
			dp[i][0] = (s1[i] == s2[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j<len2; j++)
		{
			dp[0][j] = (s1[0] == s2[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}
		// 计算最长公共子序列
		for (int i = 1; i<len1; i++)
		{
			for (int j = 1; j<len2; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i] == s2[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[len1 - 1][len2 - 1] << endl;
	}
	system("pause");
	return 0;
}


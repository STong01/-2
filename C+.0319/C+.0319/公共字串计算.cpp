#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		vector<vector<int>>sum(len1, vector<int>(len2, 0));

		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (str1[i] == str2[j])
				{
					if (i >= 1 && j >= 1)
					{
						sum[i][j] = sum[i - 1][j - 1] + 1;
					}
					else
					{
						sum[i][j] = 1;
					}
				}
				if (sum[i][j] > max)
				{
					max = sum[i][j];
				}
			}
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}
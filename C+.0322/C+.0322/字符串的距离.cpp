#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minload(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (str1.empty() || str2.empty())
	{
		return max(len1, len2);
	}

	vector<vector<int>> p(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; i++)
	{
		p[i][0] = i;
	}
	for (int j = 0; j <= len2; j++)
	{
		p[0][j] = j;
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				p[i][j] = 1 + min(p[i][j - 1], p[i - 1][j]);
				p[i][j] = min(p[i][j], p[i - 1][j - 1]);
			}
			else
			{
				p[i][j] = 1 + min(p[i][j - 1], p[i - 1][j]);
				p[i][j] = min(p[i][j], 1 + p[i - 1][j - 1]);
			}
		}
	}
	return p[len1][len2];
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << minload(s1, s2) << endl;
	}
	system("pause");
	return 0;
}
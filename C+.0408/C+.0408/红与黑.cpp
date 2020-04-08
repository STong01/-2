#include<iostream>
#include<vector>
using namespace std;

int sum = 0;
void Result(vector<vector<char>>&arr, int x, int y)
{
	if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] == '#')//走不通
		return;
	sum++;
	arr[x][y] = '#';//走过之后也不能走了
	Result(arr, x - 1, y);//上下左右
	Result(arr, x + 1, y);
	Result(arr, x, y - 1);
	Result(arr, x, y + 1);
}

int main()
{
	int m = 0, n = 0;
	while (cin >> m >> n)
	{
		vector<vector<char>>v(m, vector<char>(n));
		int x = 0, y = 0;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		Result(v, x, y);
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
//迷宫地图
vector<vector<int>> map;
//当前路径
vector<vector<int>>path_tmp;
//最佳路径
vector<vector<int>>path_best;

void Map(int i, int j)
{
	//表示当前位置已走
	map[i][j] = 1;
	//将当前位置加入路径
	path_tmp.push_back({ i, j });
	//判断是否已经到达终点
	if (i == n - 1 && j == m - 1)
	{
		if (path_best.empty() || path_best.size() > path_tmp.size())
		{
			path_best = path_tmp;
		}
	}
	//判断向上是否可走
	if (i - 1 >= 0 && map[i - 1][j] == 0)
	{
		Map(i - 1, j);
	}
	//判断向左是否可走
	if (j - 1 >= 0 && map[i][j - 1] == 0)
	{
		Map(i, j - 1);
	}
	//判断向下是否可走
	if (i + 1 < n && map[i + 1][j] == 0)
	{
		Map(i + 1, j);
	}
	//判断向右是否可走
	if (j + 1 < m && map[i][j + 1] == 0)
	{
		Map(i, j + 1);
	}
	map[i][j] = 0;
	path_tmp.pop_back();
}

int main()
{
	while (cin >> n >> m)
	{
		map = vector<vector<int>>(n, vector<int>(m, 0));
		path_tmp.clear();
		path_best.clear();
		for (auto&i : map)
		{
			for (auto&j : i)
			{
				cin >> j;
			}
		}
		Map(0, 0);
		for (auto i : path_best)
		{
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}

	system("pause");
	return 0;
}

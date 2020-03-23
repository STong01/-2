#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
//�Թ���ͼ
vector<vector<int>> map;
//��ǰ·��
vector<vector<int>>path_tmp;
//���·��
vector<vector<int>>path_best;

void Map(int i, int j)
{
	//��ʾ��ǰλ������
	map[i][j] = 1;
	//����ǰλ�ü���·��
	path_tmp.push_back({ i, j });
	//�ж��Ƿ��Ѿ������յ�
	if (i == n - 1 && j == m - 1)
	{
		if (path_best.empty() || path_best.size() > path_tmp.size())
		{
			path_best = path_tmp;
		}
	}
	//�ж������Ƿ����
	if (i - 1 >= 0 && map[i - 1][j] == 0)
	{
		Map(i - 1, j);
	}
	//�ж������Ƿ����
	if (j - 1 >= 0 && map[i][j - 1] == 0)
	{
		Map(i, j - 1);
	}
	//�ж������Ƿ����
	if (i + 1 < n && map[i + 1][j] == 0)
	{
		Map(i + 1, j);
	}
	//�ж������Ƿ����
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

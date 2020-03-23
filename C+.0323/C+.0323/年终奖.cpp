#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//年终奖
class Bonus
{
public:
	int getMost(vector<vector<int>>board)
	{
		int len = board.size();
		int wid = board[0].size();
		vector<vector<int>>price;
		for (int i = 0; i < len; i++)
		{
			vector<int>cur(wid, 0);
			price.push_back(cur);
		}

		price[0][0] = board[0][0];
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < wid; j++)
			{
				//起点位置，不做任何处理
				if (i == 0 && j == 0)
				{
					continue;
				}
				//当处于行的临界值的时候，只能向右走
				else if (i == 0)
				{
					price[i][j] = price[i][j - 1] + board[i][j];
				}
				//当处于列的临界值的时候，只能向下走
				else if (j == 0)
				{
					price[i][j] = price[i - 1][j] + board[i][j];
				}
				//除去两个临界值的时候，可以向右或者向下走
				//此时选择当前可以走的可能值中的最大值进行选择
				else
				{
					price[i][j] = max(price[i][j - 1], price[i - 1][j]) + board[i][j];
				}
			}
		}
		return price[len - 1][wid - 1];
	}
};

int main1()
{

	system("pause");
	return 0;
}
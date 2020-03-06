#include <iostream>
#include <vector>
using namespace std;

//井子棋
//当有一行或者有一列，或者在主对角线、副对角线上和等于row的时候，则玩家胜利
class Board
{
public:
	bool checkWon(vector<vector<int>>board)
	{
		int row = board.size();

		//判断每一行的和是否等于row
		int i, j, sum;
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
			{
				return true;
			}
		}

		//判断每一列是否等于row
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}

		//判断主对角线上之和是否等于row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}

		//判断副对角线上之和是否等于row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}

		return false;
	}
};


int main()
{
	Board boo;
	vector<vector<int>> tel = { { 1, 0, 1 }, { 1, -1, -1 }, { 1, -1, 0 } };
	cout << boo.checkWon(tel) << endl;

	system("pause");
	return 0;
}
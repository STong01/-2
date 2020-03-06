#include <iostream>
#include <vector>
using namespace std;

//������
//����һ�л�����һ�У����������Խ��ߡ����Խ����Ϻ͵���row��ʱ�������ʤ��
class Board
{
public:
	bool checkWon(vector<vector<int>>board)
	{
		int row = board.size();

		//�ж�ÿһ�еĺ��Ƿ����row
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

		//�ж�ÿһ���Ƿ����row
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

		//�ж����Խ�����֮���Ƿ����row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}

		//�жϸ��Խ�����֮���Ƿ����row
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
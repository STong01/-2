#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���ս�
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
				//���λ�ã������κδ���
				if (i == 0 && j == 0)
				{
					continue;
				}
				//�������е��ٽ�ֵ��ʱ��ֻ��������
				else if (i == 0)
				{
					price[i][j] = price[i][j - 1] + board[i][j];
				}
				//�������е��ٽ�ֵ��ʱ��ֻ��������
				else if (j == 0)
				{
					price[i][j] = price[i - 1][j] + board[i][j];
				}
				//��ȥ�����ٽ�ֵ��ʱ�򣬿������һ���������
				//��ʱѡ��ǰ�����ߵĿ���ֵ�е����ֵ����ѡ��
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
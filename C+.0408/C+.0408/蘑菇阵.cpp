#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	while (cin >> N >> M >> K)
	{
		vector<vector<int>> table((N + 1), vector<int>(M + 1));
		vector<vector<double>> P((N + 1), vector<double>(M + 1));
		int x, y;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}

		P[1][1] = 1.0;      //������Ϊ1
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (!(i == 1 && j == 1))
				{      //�������
					P[i][j] = P[i - 1][j] * (j == M ? 1 : 0.5) + P[i][j - 1] * (i == N ? 1 : 0.5);   //�߽��ʱ�򣬸���Ϊ1
					if (table[i][j] == 1) 
						P[i][j] = 0;        //����õ���Ģ����������Ϊ0
				}
			}
		}
		printf("%.2lf\n", P[N][M]);
	}
	return 0;
}
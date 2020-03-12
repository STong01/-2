#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//计算约数
void Y_sum(int n, vector<int>&num)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			num.push_back(i);
			//约数*约数=num
			if (n / i != i)
			{
				num.push_back(n / i);
			}
		}
	}
}

int jump(int N, int M)
{
	//计算N到每一步的距离，其中N到N为1步
	vector<int> step_num(M + 1, 0);
	step_num[N] = 1;

	for (int i = N; i < M; i++)
	{
		//N的所有约数，表示从本身这个点开始可以走的数量
		vector<int> divnum;

		if (step_num[i] == 0)
		{
			continue;
		}

		//求出所有能走的步数
		Y_sum(i, divnum);

		for (int j = 0; j < divnum.size(); j++)
		{
			//由位置i出发的能到达的点为step_num[divnum[j]+i]
			if ((divnum[j] + i) <= M && step_num[divnum[j] + i] != 0)
			{
				step_num[divnum[j] + i] = min(step_num[divnum[j] + i], step_num[i] + 1);
			}
			else if ((divnum[j] + i) <= M)
			{
				step_num[divnum[j] + i] = step_num[i] + 1;
			}
		}
	}
	if (step_num[M] == 0)
	{
		return -1;
	}
	else
		return step_num[M] - 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << jump(n, m) << endl;
	system("pause");
	return 0;
}
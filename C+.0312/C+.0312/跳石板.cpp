#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����Լ��
void Y_sum(int n, vector<int>&num)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			num.push_back(i);
			//Լ��*Լ��=num
			if (n / i != i)
			{
				num.push_back(n / i);
			}
		}
	}
}

int jump(int N, int M)
{
	//����N��ÿһ���ľ��룬����N��NΪ1��
	vector<int> step_num(M + 1, 0);
	step_num[N] = 1;

	for (int i = N; i < M; i++)
	{
		//N������Լ������ʾ�ӱ�������㿪ʼ�����ߵ�����
		vector<int> divnum;

		if (step_num[i] == 0)
		{
			continue;
		}

		//����������ߵĲ���
		Y_sum(i, divnum);

		for (int j = 0; j < divnum.size(); j++)
		{
			//��λ��i�������ܵ���ĵ�Ϊstep_num[divnum[j]+i]
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
#include <iostream>
#include <vector>
using namespace std;

//ϴ��
int main1()
{
	int T, n, k;
	//Tȷ����Ҫϴ������
	cin >> T;
	while (T--)
	{
		//nΪ1/2������kΪ�⸱����Ҫϴ�Ĵ���
		cin >> n>>k;
		int num = 2 * n;
		vector<int>table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}

		while (k--)
		{
			vector<int>tmp(table.begin(), table.end());
			for (int i = 0; i < n; i++)
			{
				table[2 * i] = tmp[i];
				table[2 * i + 1] = tmp[i + n];
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << table[i] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

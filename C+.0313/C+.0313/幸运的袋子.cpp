#include <iostream>
#include <algorithm>
using namespace std;

//�ӵ�ǰλ�ÿ�ʼ����
int getsum(int x[], int n, int pos, int sum, int mul)
{
	//x[]������������n���������pos��ǰλ�ã�sum�ܺͣ�mul�ܻ�
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		mul *= x[i];
		if (sum>mul)
		{
			//�������ϣ��ܺͼ�1�������������
			count += 1 + getsum(x, n, i + 1, sum, mul);
		}
		else if (x[i] == 1)
		{
			//���������ϣ������������
			count += getsum(x, n, i + 1, sum, mul);
		}
		else
		{
			//sum < mul�����û�з��ϵ������
			break;
		}
		//������һ��λ��ʱ��sum��mul�ָ�
		sum -= x[i];
		mul /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x[] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << getsum(x, n, 0, 0, 1) << endl;
	}
	system("pause");
	return 0;
}
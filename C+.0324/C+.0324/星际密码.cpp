#include <iostream>
#include <vector>
using namespace std;

//�Ǽ�����
//������������
int init(int n)
{
	vector<int>a = { 1, 1 };
	for (int i = 2; i <= n; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
	return a[n];
}

int main1()
{
	int sum, n;
	while (cin >> sum)
	{
		while (sum--)
		{
			cin >> n;
			int tmp = init(n);
			//ȡ�������λ����������λ��ʱ��ǰ�油0��������λ
			printf("%04d", tmp);
		}
		cout << endl;
	}
	system("pause");
	return 0;

}

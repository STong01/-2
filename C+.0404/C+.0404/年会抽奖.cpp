#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> tmp = { 0, 0, 1 };
	vector<long long> fun = { 0, 1, 2 };

	int n;
	//���˻�����ݼ�
	//fun��ʾn��ʱ���ܵĳ�ȡ�������Ϊn!
	//tmpΪ���˻񽱵����������B����A���֣���1��Aǡ������B�����֣��������Ϊtmp[n - 2];
	//2��Aû����B�����֣��������Ϊtmp[n - 1]
	for (int i = 3; i < 21; i++)
	{
		tmp.push_back(0);
		tmp[i] = (i - 1) * (tmp[i - 2] + tmp[i - 1]);
		fun.push_back(0);
		fun[i] = i * fun[i - 1];
	}
	while (cin>>n)
	{
		printf("%.2f%c\n", 1.0*tmp[n] / fun[n] * 100, '%');
	}

	system("pause");
	return 0;
}

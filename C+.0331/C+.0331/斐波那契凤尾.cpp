#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<long> tmp = { 1, 1 };
	for (int i = 2; i <= 100001; i++)
	{
		tmp.push_back(0);
		tmp[i] = ((tmp[i - 1] % 1000000) + (tmp[i - 2] % 1000000)) % 1000000;
	}
	while (cin >> n)
	{
		if (n <= 25)  //�����жϣ���ʱ������ֵ����100000�ķֽ紦
			cout << tmp[n] << endl; //ֱ�����
		else
			printf("%06ld\n", tmp[n]);//�������λ
	}

	system("pause");
	return 0;
}
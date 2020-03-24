#include <iostream>
#include <string>
using namespace std;

//����
int num_root(int n)
{
	int n_root = 0;
	while (n > 0)
	{
		//����λλ���������
		n_root += n % 10;
		n /= 10;
	}
	while (n_root > 9)
	{
		n_root = num_root(n_root);
	}
	return n_root;
}

int main()
{
	//ʹ��str�����������ֵķ�Χ
	string str;
	while (cin >> str)
	{
		int sum = 0;
		for (int i = 0; i < str.size(); i++)
		{
			//����ֱ�ӽ���һ�θ�λ֮��
			sum += str[i] - '0';
		}
		cout << num_root(sum) << endl;
	}

	system("pause");
	return 0;
}
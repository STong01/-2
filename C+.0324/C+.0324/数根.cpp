#include <iostream>
#include <string>
using namespace std;

//数根
int num_root(int n)
{
	int n_root = 0;
	while (n > 0)
	{
		//将各位位数依次相加
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
	//使用str可以增大数字的范围
	string str;
	while (cin >> str)
	{
		int sum = 0;
		for (int i = 0; i < str.size(); i++)
		{
			//首先直接进行一次各位之和
			sum += str[i] - '0';
		}
		cout << num_root(sum) << endl;
	}

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

//�������������Լ��
int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main1()
{
	int a, b;
	while (cin >> a >> b)
	{
		//�������������󹫱���
		cout << a * b / gcd(a, b) << endl;
	}
	system("pause");
	return 0;
}
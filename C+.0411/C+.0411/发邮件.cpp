#include<iostream>
using namespace std;

long int Failrec(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	//n - 1ΪAǡ���յ���B���ʼ���Bȴû���յ�A���ʼ�
	//n - 2ΪAǡ���յ���B���ʼ�������BҲ�յ�A���ʼ�
	return (n - 1) * (Failrec(n - 1) + Failrec(n - 2));
}

int main1()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << Failrec(n) << endl;
	}
	system("pause");
	return 0;
}
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
	//n - 1为A恰好收到了B的邮件，B却没有收到A的邮件
	//n - 2为A恰好收到了B的邮件，并且B也收到A的邮件
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
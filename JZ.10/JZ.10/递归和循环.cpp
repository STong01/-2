#include <iostream>
using namespace std;

//�ݹ鷽����1 + 2 + 3 + ... + n;
int AddFrom1ToN_Recursive(int n)
{
	return n <= 0 ? 0 : n + AddFrom1ToN_Recursive(n - 1);
}

//ѭ��������1 + 2 + 3 + ... + n;
int AddFrom1ToN_Iterative(int n)
{
	int result = 0;
	for (int i = 0; i <= n; i++)
	{
		result += i;
	}
	return result;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << "ѭ����⣺";
		cout << AddFrom1ToN_Iterative(n) << endl;
		cout << "�ݹ���⣺";
		cout << AddFrom1ToN_Recursive(n) << endl;
	}

	system("pause");
	return 0;
}
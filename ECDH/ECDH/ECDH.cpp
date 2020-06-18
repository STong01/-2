#include <iostream>
#include <vector>
using namespace std;

//分母求模逆
int power(int x, int y, int mod)
{
	int r = 1;
	while (y)
	{
		if (y & 1)
		{
			r = (r * x) % mod;
		}
		x = (x * x) % mod;
		y >>= 1;
	}
	return r;
}

//分数求模运算
int Modular_operation(int x, int y, int mod)
{
	int p = power(y, mod - 2, mod);
	int ans = x * p % mod;
	return ans;
}

vector<int> test(int N, vector<int>Sp0)
{
	vector<int>Sp1 = { 0, 0 };
	if (N == 1)
	{
		Sp1[0] = Sp0[0];
		Sp1[1] = Sp1[1];
	}
	if (N == 2)
	{

	}
	return Sp1;
}

int main()
{
	int x = 14;
	int y = 3;
	int mod = 23;

	cout << Modular_operation(x, y, mod) << endl;


	system("pause");
	return 0;
}
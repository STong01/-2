#include <iostream>
using namespace std;

bool P_san(double num1, double num2, double num3)
{
	if ((num1 + num2) > num3)
	{
		if ((num1 + num3) > num2)
		{
			if ((num2 + num3) > num1)
			{
				return true;
			}
		}
	}
	return false;
}

int main2()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (P_san(a, b, c))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}
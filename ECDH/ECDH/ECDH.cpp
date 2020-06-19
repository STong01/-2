#include <iostream>
#include <vector>
using namespace std;

//��ĸ��ģ��
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

//������ģ����
int Modular_operation(int x, int y, int mod)
{
	int p = power(y, mod - 2, mod);
	int ans = x * p % mod;
	if (ans < 0)
	{
		ans = ans + mod;
	}
	return ans;
}


vector<int> test(int N, int a, int p, vector<int>Sp0)
{
	vector<int>Sp1 = { 0, 0 };
	int R = 0;
	int son = 0;
	int fat = 0;
	if (N == 1)
	{
		Sp1[0] = Sp0[0];
		Sp1[1] = Sp1[1];
	}
	if (N == 2)
	{
		son = 3 * Sp0[0] * Sp0[0] + a;
		fat = 2 * Sp0[1];
		R = Modular_operation(son, fat, p);
		Sp1[0] = Modular_operation((R*R - Sp0[0] - Sp0[0]), 1, p);
		Sp1[1] = Modular_operation((R*(Sp0[0] - Sp1[0]) - Sp0[1]), 1, p);
	}
	if (N > 2)
	{
		son = 3 * Sp0[0] * Sp0[0] + a;
		fat = 2 * Sp0[1];
		R = Modular_operation(son, fat, p);
		Sp1[0] = Modular_operation((R*R - Sp0[0] - Sp0[0]), 1, p);
		Sp1[1] = Modular_operation((R*(Sp0[0] - Sp1[0]) - Sp0[1]), 1, p);
		for (int i = 3; i <= N; i++)
		{
			fat = Sp1[0] - Sp0[0];
			son = Sp1[1] - Sp0[1];
			R = Modular_operation(son, fat, p);
			Sp1[0] = Modular_operation((R*R - Sp0[0] - Sp1[0]), 1, p);
			Sp1[1] = Modular_operation((R*(Sp0[0] - Sp1[0]) - Sp0[1]), 1, p);
		}
	}
	return Sp1;
}

int main()
{
	int p;
	cout << "������pֵ��";
	cin >> p;
	cout << endl;

	int a, b;
	cout << "��������Բ����a,b��ֵ��";
	cin >> a >> b;
	if (a == 0 && b != 0)
	{
		cout << "��Բ����Ϊ��";
		cout << "y^2 = x^3 + (" << b << ")" << endl;
		cout << endl;
	}
	if (a != 0 && b == 0)
	{
		cout << "��Բ����Ϊ��";
		cout << "y^2 = x^3 + (" << a << ")x^2" << endl;
		cout << endl;
	}
	if (a == 0 && b == 0)
	{
		cout << "��Բ����Ϊ��";
		cout << "y^2 = x^3 "<< endl;
		cout << endl;
	}
	if (a != 0 && b != 0)
	{
		cout << "��Բ����Ϊ��";
		cout << "y^2 = x^3 + (" << a << ")x^2 + (" << b << ")" << endl;
		cout << endl;
	}

	vector<int>G = { 0, 0 };
	cout << "���������G����(x1, y1)��";
	cin >> G[0] >> G[1];
	cout << endl;

	int Na = 0;
	cout << "������A��˽Կ��";
	cin >> Na;

	vector<int>Pa = { 0, 0 };
	Pa = test(Na, a, p, G);
	cout << "�û�A�Ĺ�Կ��(" << Pa[0] << "," << Pa[1] << ")" << endl;
	cout << endl;

	int Nb = 0;
	cout << "������B��˽Կ��";
	cin >> Nb;

	vector<int>Pb = { 0, 0 };
	Pb = test(Nb, a, p, G);
	cout << "�û�B�Ĺ�Կ��(" << Pb[0] << "," << Pb[1] << ")" << endl;
	cout << endl;

	vector<int>Ka = { 0, 0 };
	Ka = test(Na, a, p, Pb);
	cout << "�û�A��������Կ��(" << Ka[0] << "," << Ka[1] << ")" << endl;

	vector<int>Kb = { 0, 0 };
	Kb = test(Nb, a, p, Pa);
	cout << "�û�B��������Կ��(" << Kb[0] << "," << Kb[1] << ")" << endl;

	system("pause");
	return 0;
}
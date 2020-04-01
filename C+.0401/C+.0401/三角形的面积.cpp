#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//判断能否构成三角形
bool IsSan(double a, double b, double c)
{
	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//计算面积
double S(double a, double b, double c)
{
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p*(p - a)*(p - b)*(p - c));
	return S;
}

int main1()
{
	int n;
	vector<double> a;
	vector<double> b;
	vector<double> c;
	vector<double> s;

	while (cin >> n)
	{
		a.resize(n);
		b.resize(n);
		c.resize(n);
		s.resize(n);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (IsSan(a[i],b[i],c[i]))
			{
				s[i] = S(a[i], b[i], c[i]);
				printf("%0.3f\n", s[i]);//输出后三位
			}
			else
			{
				cout << -1 << endl;
			}
			cout << endl;
		}
	}
	return 0;
}

//#include <iostream>
//#include <iomanip>
//#include <math.h>
//using namespace std;
//
//bool Istriangle(int a, int b, int c)
//{
//	if ((a + b > c) && (a + c > b) && (b + c > a))
//	{
//		return true;
//	}
//	return false;
//}
////三角形面积：S=√[p(p-a)(p-b)(p-c)] ，而公式里的p为半周长：p=(a+b+c)/2
//double triangle(int a, int b, int c)
//{
//	if (Istriangle(a, b, c))
//	{
//		double p = (a + b + c) / 2;
//		double area;
//		area = sqrt(p * (p - a) * (p - b) *(p - c));
//		return area;
//	}
//	return -1;
//}
//
//int main()
//{
//	int num;
//	cin >> num;
//	int a, b, c;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> a >> b >> c;
//		double area = triangle(a, b, c);
//		if (area == -1) 
//			cout << area << endl;
//		else
//		{
//			cout.precision(3);
//			cout.setf(ios::fixed);
//			cout << area << endl;
//		}
//		if (i != num - 1)
//			cout << endl;
//	}
//	system("pause");
//	return 0;
//}
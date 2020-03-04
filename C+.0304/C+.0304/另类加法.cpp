#include <iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) 
	{
		int sum = 0;
		int carry = 0;
		while (B != 0)
		{
			//���Ӧλ�ĺ�
			sum = A^B;
			//���Ӧλ�Ľ�λ����Ϊ�ǽ�λ��������������һλ
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};

int main()
{
	int A = 11;
	int B = 22;
	UnusualAdd ADD;
	int add = ADD.addAB(A, B);
	cout << add << endl;

	system("pause");
	return 0;
}
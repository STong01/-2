#include <iostream>
#include <string>
using namespace std;

int P_num(int num)
{
	int sum = 0;
	while (num > 1)
	{
		//����ƿ�ӻ�һƿˮ��
		int cur1 = num / 3;
		//��������ƿ��������
		int cur2 = num % 3;
		//���Ժȵ�ˮΪ��������ˮ�Լ�ԭ�����µ�ˮ
		sum = sum + cur1;
		//����������ӵ�е�ƿ����Ϊ��ˮ֮���ƿ���Լ�ʣ���ƿ����
		num = cur2 + cur1;
		if (num == 2)
		{
			sum++;
			break;
		}
	}
	return sum;
}

int main()
{
	int number;
	while (cin >> number)
	{
		cout << P_num(number) << endl;
	}
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

//�ַ���ͨ���
bool test(const char* tmp, const char* str)
{
	//�������ַ���ͬʱ����ʱ�򣬷�����
	if (*tmp == '\0' && *str == '\0')
	{
		return true;
	}

	//��������һ���ַ������Ƚ��������ؼ�
	if (*tmp == '\0' || *str == '\0')
	{
		return false;
	}

	//'?'ͨ��һ���ַ��������ݹ���һ���ַ�
	if (*tmp == '?')
	{
		return test(tmp + 1, str + 1);
	}
	//'*'ͨ�䲻�����ַ���ֱ�ӵݹ�str����һ���ַ�
	else if (*tmp == '*')
	{
		return test(tmp + 1, str) || test(tmp + 1, str + 1) || test(tmp, str + 1);
	}
	else if (*tmp == *str)
	{
		return test(tmp + 1, str + 1);
	}
	return false;
}

int main()
{
	string tmp, str;
	while (cin >> tmp >> str)
	{
		bool ret = test(tmp.c_str(), str.c_str());
		if (ret)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	system("pause");
	return 0;
}
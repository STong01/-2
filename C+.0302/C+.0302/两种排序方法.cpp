#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;//�����ַ�������
	cin >> n;
	vector<string> s1;
	s1.resize(n);
	for (auto& str : s1)
	{
		cin >> str;//�����ַ���
	}

	bool lenSym = true;//�����ж�
	bool lexSym = true;// �ֵ�������

	//��֤��������
	for(size_t i = 1; i < s1.size(); i++)
	{
		if (s1[i - 1].size() >= s1[i].size())
		{
			lenSym = false;
			break;
		}
	}

	//��֤�ֵ�������
	for (size_t i = 1; i < s1.size(); i++)
	{
		if (s1[i - 1] >= s1[i])
		{
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym)
	{
		cout << "both" << endl;
	}
	else if (!lenSym && lexSym)
	{
		cout << "lexicographically" << endl;
	}
	else if (lenSym && !lexSym)
	{
		cout << "lengths" << endl;
	}
	else if (!lenSym && !lexSym)
	{
		cout << "none" << endl;
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	string str;
	while (getline(cin, str)) 
	{
		vector<string> names;  // �����������
		int tmp = 0;
		int len = str.length();
		while (tmp < len)
		{  // λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ�����Ӹ�λ������
			if (str[tmp] == '"')
			{  // �ҵ�˫����Ҫ����˫�����ڲ�
				int end = str.find('"', tmp + 1);
				names.push_back(str.substr(tmp + 1, end - tmp - 1));  // ��ȡ�����ŵ�names��
				tmp = end + 2;  // ���������˫���źͶ���
			}
			else 
			{
				int end = str.find(",", tmp + 1);
				if (end == -1) 
				{  // �Ҳ�������֤���������һ���ַ����ˣ�ֱ�Ӵ���ַ���������
					names.push_back(str.substr(tmp, str.size() - tmp));
					break;
				}
				names.push_back(str.substr(tmp, end - tmp));
				tmp = end + 1;  // ��������Ķ���
			}
		}
		getline(cin, str);
		//for (int i = 0; i < names.size(); i++)
		//{
		//	if (names[i].find(str))
		//	{
		//		cout << "Important!" << endl;
		//		break;
		//	}
		//	else if (i == names.size() - 1)
		//	{
		//		cout << "Ignore" << endl;
		//		break;
		//	}
		//}
		if (names.end() == find(names.begin(), names.end(), str))
			// find�����������������м���ң����һ������ΪҪ�ҵ�ֵ
			// �ҵ��˷��ض�Ӧ���������Ҳ�����������ĩβλ�ã�������Ϊend()
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int length)
{
	//length是string的总容量
	if (string == nullptr || length <= 0)
	{
		return;
	}

	//定义string的实际长度str_length
	int str_length = 0;
	int numofblank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		str_length++;

		if (string[i] == ' ')
		{
			numofblank++;
		}

		++i;
	}

	int new_length = str_length + numofblank * 2;

	if (new_length > length)
	{
		return;
	}

	while (str_length >= 0 && str_length < new_length)
	{
		if (string[str_length] == ' ')
		{
			string[new_length--] = '0';
			string[new_length--] = '2';
			string[new_length--] = '%';
		}
		else
		{
			string[new_length--] = string[str_length];
		}
		--str_length;

	}
}

int main()
{
	char string[30] = "I will be success!";

	ReplaceBlank(string, 30);

	cout << string << endl;

	system("pause");
	return 0;
}
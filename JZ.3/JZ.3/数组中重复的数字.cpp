#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}

	return false;
}

int main2()
{
	int numbers[] = { 4, 3, 1, 0, 4, 5, 4 };
	int length = 7;
	int val = 0;
	while (duplicate(numbers, length, &val))
	{
		cout << val << endl;
		break;
	}

	system("pause");
	return 0;
}
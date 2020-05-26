#include <iostream>
using namespace std;

int Min1(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("Invaild parameters");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	return result;
}

int Min2(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("Invaild parameters");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		//如果下标为index1、index2和indexMid指向的三个数字相等
		//则只能顺序查找

		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
		{
			return MinInOrder(numbers, index1, index2);
		}

		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

int main()
{
	int numbers1[] = { 1, 0, 1, 1, 1 };
	int numbers2[] = { 1, 1, 1, 0, 1 };
	cout << Min1(numbers1, 5) << endl;
	cout << Min1(numbers2, 5) << endl;
	cout << Min2(numbers1, 5) << endl;
	cout << Min2(numbers2, 5) << endl;


	system("pause");
	return 0;
}
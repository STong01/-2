#include <iostream>
#include <algorithm>
using namespace std;

void Swap(int* a, int* b)
{
	int* tmp = a;
	a = b;
	b = tmp;
}

//循环实现快排
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid Parameters");
	}

	//生成start与end之间的随机数
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				Swap(&data[index], &data[small]);
			}
		}

		++small;
		Swap(&data[small], &data[end]);

		return small;
	}
}

//递归实现快排
void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
	{
		return;
	}

	int index = Partition(data, length, start, end);
	if (index > start)
	{
		QuickSort(data, length, start, index - 1);
	}
	if (index < end)
	{
		QuickSort(data, length, index + 1, end);
	}
}

int main()
{

	system("pause");
	return 0;
}
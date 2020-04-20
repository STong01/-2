#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxGap 
{
public:
	int findMaxGap(vector<int> A, int n) 
	{
		int num = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			vector<int> A1;
			vector<int> A2;
			for (int j = 0; j <= i; j++)
			{
				A1.push_back(A[j]);
			}
			for (int p = i; p < n; p++)
			{
				A2.push_back(A[p]);
			}
			sort(A1.begin(), A1.end());
			sort(A2.begin(), A2.end());
			int max1 = A1[i];
			int max2 = A2[n - i - 1];
			int sum = max(max1, max2) - min(max1, max2);
			num = max(num, sum);
		}
		return num;
	}
};

//class MaxGap{
//public:
//	int findMaxGap(vector<int> A, int n)
//	{
//		// write code here
//		int max = 0;
//		int pos = 0;
//		for (int i = 0; i < n; i++)
//		if (max < A[i]){
//			max = A[i];
//			pos = i;
//		}
//		if (pos == 0)
//			return A[0] - A[n - 1];
//		if (pos == n - 1)
//			return A[n - 1] - A[0];
//		int left = (A[pos] - A[0]);
//		int right = (A[pos] - A[n - 1]);
//		return left > right ? left : right;
//	}
//};

int main1()
{
	MaxGap test;
	vector<int> A = {15, 30, 61, 99};
	cout << test.findMaxGap(A, 4) << endl;
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b)((a)>(b)?(a):(b))

#if 1
//一个数组中只有两个数字是出现一次， 其他所有数字都出现了两次。
void findnum(int * src, int n, int * pnum1, int * pnum2){
	int i;
	int sum = 0;
	for(i = 0; i < n; i++){
		sum^=src[i];
	}
	int pos;
	for (pos = 0; !(sum & 1 << pos); pos++);
	int num1 = 0, num2 = 0;
	for (i = 0; i < n; i++){
		if (src[i] & 1 << pos){
			num1 ^= src[i];
		}
		else{
			num2 ^= src[i];
		}
	}
	*pnum1 = num1;
	*pnum2 = num2;
}

int main(){
	int arr[] = { 5, 3, 9, 1, 7, 5, 4, 7, 4, 2, 9, 2 };
	int num1, num2;
	findnum(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2);
	printf("%d,%d\n", num1, num2);
	system("pause");
	return 0;
}
#endif

#if 0
//n空瓶子换水喝水问题,m为初始瓶子数；
int main(){
	int m, n;
	printf("请输入初始瓶子数：");
	scanf("%d", &m);
	printf("请输入换算值：");
	scanf("%d", &n);
	int drink = m, cover = m;
	int sum = m;
	while (cover >= n){
		drink = cover;
		cover = drink / n + drink % n;
		sum += drink / n;
		/*sum += cover / 2;
		cover = cover / n + cover%n;*/
	}
	printf("%d\n", sum+(cover == n - 1));
	system("pause");
	return 0;
}
#endif

#if 0
char * strcpy(char * dst, const char * src){
	char * tmp = dst;
	while (*dst++ = *src++);
	return tmp;
}
char * strcat(char * dst, const char * src){
	char * tmp = dst;
	while (*dst++);
	dst--;
	while (*dst++ = *src++);
	return tmp;
}
int main(){

	system("pause");
	return 0;
}
#endif

#if 0

int main(){
	int data[101][1001] = { 0 };
	int size, n;//背包大小，物品种类数；
	int weight[101] = { 0 };//物品大小；
	int value[101] = { 0 };//物品价值；
	int i,j;
	scanf("%d%d", &size, &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", weight + i, value + i);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= size; j++){
			if (j < weight[i]){
				data[i][j] = data[i - 1][j];
			}
			else{
				data[i][j] = MAX(data[i - 1][j], data[i - 1][j - weight[i] + value[i]]);
			}
		}
	}
	printf("%d", data[n][size]);
	system("pause");
	return 0;
}
#endif

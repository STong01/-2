#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[10][10] = { 0 };
	int x, y;
	int x2, y2;
	scanf("%d%d", &x, &y);
	scanf("%d%d", &x2, &y2);//Ê÷×®Î»ÖÃ
	int i, j;
	for (i = 1; i <= x; i++){
		for (j = 1; j <= y; j++){
			if (i == x2 && j == y2){
				continue;   //Ê÷×®
			}
			if (i == 1 && j == 1){
				a[i][j] = 1;
			}
			else{
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
	printf("%d\n", a[x][y]);
	system("pause");
	return 0;
}
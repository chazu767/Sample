#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int main(void) {
	int i,j,tmp;
	//配列に格納する変数に関してはconst intの方が良い??
	const int num = 100;
	int st[num],ans[num];
	//毎回乱数を異なる値にする．
	srand((unsigned int)time(NULL));
	//乱数の生成100個
	printf("乱数の生成\n");
	for (i = 0; i < 100; i++) {
			st[i] = rand() % 100 + 1;
			ans[i] = st[i];
			printf("%d,",st[i]);		
	}
	printf("\n");
	
	//バブルソート昇順
	printf("ここからソート昇順\n");
	for (i = 0; i < num; i++) {
		for (j =i+1; j < num; j++) {
			if (ans[i] > ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//結果(昇順)
	for (i = 0; i < 100; i+=10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i+j]);
		}
		printf("\n");
	}
	printf("\n");

	//バブルソート(降順)
	printf("ここからソート降順\n");
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ans[i] < ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//結果(降順)
	for (i = 0; i < 100; i += 10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i + j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
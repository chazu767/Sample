#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//少数の関数
float rnd() {
	return((double)(rand() % RAND_MAX) / (double)(RAND_MAX));
}

//IDの選定(整数型)
int rndpnum(int a) {
	return rand() % a;
}

//計算
double distance(double x0, double y0, double x1, double y1) {
	return sqrt((pow(x0 - x1, 2) + pow(y0 - y1, 2)));
}

int main(void){
	srand((unsigned int)time(NULL));
	const int pnum = 5;
	int test=rndpnum(pnum);
	const int dem = 2;
	int n = 0;
	int id = 0;
	float d=0.0,dmin=100.0;

	bool pp[pnum] = {0};
	float p[pnum][dem];
	int erabi = 0;

	//座標を格納
	for (int i = 0; i < pnum; i++) {
		for (int j = 0; j < dem; j++) {
			p[i][j] = rnd();
			//printf("ID[%d][%d]の値%.2lf",i,j,p[i][j]);
			printf("%.2lf,",p[i][j]);

		}
		printf("\n");
	}
	id = rndpnum(pnum);
	while (pp[id] == false) {
		//最初の選ばれたIDをtrueにさらに表示する.
		pp[id] = 1;
		dmin = 100.0;
		printf("最初の選ばれたIDは[%d]\n", id);
		erabi = id;

		//for (int cc = 0; cc < pnum; cc++) {
		//	if (cc == id) {
		//		printf("最初の選ばれたIDは[%d]", cc);
		//		erabi = cc;
		//	}
		//}
		//printf("\n");

		//最短の計算
		for (int k = 0; k < pnum; k++) {
			if (pp[k] == 0) {
				d = distance(p[erabi][0], p[erabi][1], p[k][0], p[k][1]);
				if (d < dmin) {
					dmin = d;
					printf("一番小さかった値は%lf\n", dmin);
					id = k;
				}
			}
		}
	}

	/*
		printf("\n");
		//最小値が選定されたIDをtrueにする,更に表示する．
		pp[id] = 1;
		printf("一番近かったIDは[%d]\n", id);

		//ppの中身を参照するプログラム
		printf("\n");
		for (int c = 0; c < pnum; c++) {
			printf("pp[%d]の中身%d\n",c,pp[c]);
		}
		printf("\n");

		//ここまで完成
		*/
	return 0;
}
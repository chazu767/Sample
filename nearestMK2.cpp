#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

//ユークリッド距離の関数
float euclid(int x0, int y0, int x1, int y1) {
	return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

int main(void) {
	int i, j, tmp;
	//配列に格納する変数に関してはconst intの方が良い??
	const int num = 100;
	int st[num], ans[num];
	//毎回乱数を異なる値にする．
	srand((unsigned int)time(NULL));
	//乱数の生成100個
	printf("乱数の生成\n");
	for (i = 0; i < 100; i++) {
		st[i] = rand() % 100 + 1;
		ans[i] = st[i];
		printf("%d,", st[i]);
	}
	printf("\n");

	//バブルソート昇順
	printf("ここからソート昇順\n");
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ans[i] > ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//結果(昇順)
	for (i = 0; i < 100; i += 10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i + j]);
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

	//------------------------------------------------------------------------------

	/*
	//最近棒法

	//idは0から99までの100個，xyは0をxとし，yを1とする.
	const int id = 100, xy = 2;
	//decは決定されたidに対して処理を行う変数である(はじめ選ぶiIDを決めるためconstで宣言してはいけない)
	//decminは適当に決めておく(141より大きければ平気??)
	//boxはユークリッド計算した値を格納する変数
	int p[id][xy], dec;
	float decmin=1000.0,box=0.0;
	//pdecはpに対して処理がなされたときに1,初期は0のfalseである．
	bool pdec[id] = { 0 };

	for (i = 0; i < id; i++) {
		for (j = 0; j < xy; j++) {
			p[i][j]= rand() % 100 + 1;
			printf("%d,",p[i][j]);
			//Excel抽出用
		}
		printf("\n");
	}
	printf("\n");

	//IDの選択(ランダム)
	dec = rand() % id;
	printf("最初に選ばれたIDは[%d]\n",dec);

	while (pdec[dec] == false) {
		//pdec最初のIDランダムに対してtrueを入れる.
		pdec[dec] = 1;

		//毎回更新する必要のある値(評価値の更新する)
		decmin = 1000.0;
		//IDの表示
		printf("ID[%d]---",dec);

		//最短距離の計算
		printf("最短距離");
		for (i = 0; i < id; i++) {
			//pdec初めに選ばれたのは1なので自分自身が選ばれることはない
			if (pdec[i] == 0) {
				box = euclid(p[dec][0], p[dec][1], p[i][0], p[i][1]);
				//最初の比較は通る(decminは1000のため)
				if (box < decmin) {
					decmin = box;
					printf("%.2f,", decmin);
					//decの選定はifで回りきった最後の値iになるためなのは間違い
					j = i;
				}
			}
		}
		//decはループを抜てけてから更新する.
		dec = j;
		printf("\n");
	}
	*/


	//--------------------------------------------------------------------------------------------------------
	//最近棒法(改良版未完成)
	//idは0から99までの100個，xyは0をxとし，yを1とする.
	const int id = 100, xy = 2;
	//decは決定されたidに対して処理を行う変数である(はじめ選ぶiIDを決めるためconstで宣言してはいけない)
	//decminは適当に決めておく(141より大きければ平気??)
	//boxはユークリッド計算した値を格納する変数
	int p[id][xy], dec, groupid = 0, tag[100] = { 0 };

	//平均，重心を求める変数
	int cntx[id] = { 0 }, cnty[id] = { 0 };


	float decmin = 1000.0, box = 0.0;
	//pdecはpに対して処理がなされたときに1,初期は0のfalseである．
	bool pdec[id] = { 0 };

	for (i = 0; i < id; i++) {
		for (j = 0; j < xy; j++) {
			p[i][j] = rand() % 100 + 1;
			printf("%d,", p[i][j]);
			//Excel抽出用
		}
		printf("\n");
	}
	printf("\n");

	//IDの選択(ランダム)
	dec = rand() % id;
	printf("最初に選ばれたIDは[%d]\n", dec);

	while (pdec[dec] == false) {
		//pdec最初のIDランダムに対してtrueを入れる.
		pdec[dec] = 1;

		//毎回更新する必要のある値(評価値の更新する)
		decmin = 1000.0;
		//IDの表示
		printf("ID[%d]---GROUPID[%d] ", dec, tag[dec]);

		//最短距離の計算
		printf("最短距離");
		for (i = 0; i < id; i++) {
			//pdec初めに選ばれたのは1なので自分自身が選ばれることはない
			if (pdec[i] == 0) {
				box = euclid(p[dec][0], p[dec][1], p[i][0], p[i][1]);
				//最初の比較は通る(decminは1000のため)
				if (box < decmin) {
					decmin = box;
					printf("%.2f,", decmin);
					//decの選定はifで回りきった最後の値iになるためなのは間違い
					j = i;
				}
			}
		}

		//タグ付けするプログラム
		if (decmin >= 10) {
			groupid++;
		}
		tag[j] = groupid;

		//x,yの値を足していく
		cntx[groupid] += p[j][0];
		cnty[groupid] += p[j][1];
		printf("GROUPIDの合計値[%d]x:[%d]y:[%d]", groupid, cntx[groupid], cnty[groupid]);


		//decはループを抜てけてから更新する.
		dec = j;

		printf("\n");
	}

	//-----------------------------------------------------------------------------------------------








	return 0;
}


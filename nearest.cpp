#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//�����̊֐�
float rnd() {
	return((double)(rand() % RAND_MAX) / (double)(RAND_MAX));
}

//ID�̑I��(�����^)
int rndpnum(int a) {
	return rand() % a;
}

//�v�Z
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

	//���W���i�[
	for (int i = 0; i < pnum; i++) {
		for (int j = 0; j < dem; j++) {
			p[i][j] = rnd();
			//printf("ID[%d][%d]�̒l%.2lf",i,j,p[i][j]);
			printf("%.2lf,",p[i][j]);

		}
		printf("\n");
	}
	id = rndpnum(pnum);
	while (pp[id] == false) {
		//�ŏ��̑I�΂ꂽID��true�ɂ���ɕ\������.
		pp[id] = 1;
		dmin = 100.0;
		printf("�ŏ��̑I�΂ꂽID��[%d]\n", id);
		erabi = id;

		//for (int cc = 0; cc < pnum; cc++) {
		//	if (cc == id) {
		//		printf("�ŏ��̑I�΂ꂽID��[%d]", cc);
		//		erabi = cc;
		//	}
		//}
		//printf("\n");

		//�ŒZ�̌v�Z
		for (int k = 0; k < pnum; k++) {
			if (pp[k] == 0) {
				d = distance(p[erabi][0], p[erabi][1], p[k][0], p[k][1]);
				if (d < dmin) {
					dmin = d;
					printf("��ԏ����������l��%lf\n", dmin);
					id = k;
				}
			}
		}
	}

	/*
		printf("\n");
		//�ŏ��l���I�肳�ꂽID��true�ɂ���,�X�ɕ\������D
		pp[id] = 1;
		printf("��ԋ߂�����ID��[%d]\n", id);

		//pp�̒��g���Q�Ƃ���v���O����
		printf("\n");
		for (int c = 0; c < pnum; c++) {
			printf("pp[%d]�̒��g%d\n",c,pp[c]);
		}
		printf("\n");

		//�����܂Ŋ���
		*/
	return 0;
}
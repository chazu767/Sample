#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

//���[�N���b�h�����̊֐�
float euclid(int x0, int y0, int x1, int y1) {
	return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}

int main(void) {
	int i, j, tmp;
	//�z��Ɋi�[����ϐ��Ɋւ��Ă�const int�̕����ǂ�??
	const int num = 100;
	int st[num], ans[num];
	//���񗐐����قȂ�l�ɂ���D
	srand((unsigned int)time(NULL));
	//�����̐���100��
	printf("�����̐���\n");
	for (i = 0; i < 100; i++) {
		st[i] = rand() % 100 + 1;
		ans[i] = st[i];
		printf("%d,", st[i]);
	}
	printf("\n");

	//�o�u���\�[�g����
	printf("��������\�[�g����\n");
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ans[i] > ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//����(����)
	for (i = 0; i < 100; i += 10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i + j]);
		}
		printf("\n");
	}
	printf("\n");

	//�o�u���\�[�g(�~��)
	printf("��������\�[�g�~��\n");
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ans[i] < ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//����(�~��)
	for (i = 0; i < 100; i += 10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i + j]);
		}
		printf("\n");
	}
	printf("\n");

	//------------------------------------------------------------------------------

	/*
	//�ŋߖ_�@

	//id��0����99�܂ł�100�Cxy��0��x�Ƃ��Cy��1�Ƃ���.
	const int id = 100, xy = 2;
	//dec�͌��肳�ꂽid�ɑ΂��ď������s���ϐ��ł���(�͂��ߑI��iID�����߂邽��const�Ő錾���Ă͂����Ȃ�)
	//decmin�͓K���Ɍ��߂Ă���(141���傫����Ε��C??)
	//box�̓��[�N���b�h�v�Z�����l���i�[����ϐ�
	int p[id][xy], dec;
	float decmin=1000.0,box=0.0;
	//pdec��p�ɑ΂��ď������Ȃ��ꂽ�Ƃ���1,������0��false�ł���D
	bool pdec[id] = { 0 };

	for (i = 0; i < id; i++) {
		for (j = 0; j < xy; j++) {
			p[i][j]= rand() % 100 + 1;
			printf("%d,",p[i][j]);
			//Excel���o�p
		}
		printf("\n");
	}
	printf("\n");

	//ID�̑I��(�����_��)
	dec = rand() % id;
	printf("�ŏ��ɑI�΂ꂽID��[%d]\n",dec);

	while (pdec[dec] == false) {
		//pdec�ŏ���ID�����_���ɑ΂���true������.
		pdec[dec] = 1;

		//����X�V����K�v�̂���l(�]���l�̍X�V����)
		decmin = 1000.0;
		//ID�̕\��
		printf("ID[%d]---",dec);

		//�ŒZ�����̌v�Z
		printf("�ŒZ����");
		for (i = 0; i < id; i++) {
			//pdec���߂ɑI�΂ꂽ�̂�1�Ȃ̂Ŏ������g���I�΂�邱�Ƃ͂Ȃ�
			if (pdec[i] == 0) {
				box = euclid(p[dec][0], p[dec][1], p[i][0], p[i][1]);
				//�ŏ��̔�r�͒ʂ�(decmin��1000�̂���)
				if (box < decmin) {
					decmin = box;
					printf("%.2f,", decmin);
					//dec�̑I���if�ŉ�肫�����Ō�̒li�ɂȂ邽�߂Ȃ̂͊ԈႢ
					j = i;
				}
			}
		}
		//dec�̓��[�v�𔲂Ă��Ă���X�V����.
		dec = j;
		printf("\n");
	}
	*/


	//--------------------------------------------------------------------------------------------------------
	//�ŋߖ_�@(���ǔŖ�����)
	//id��0����99�܂ł�100�Cxy��0��x�Ƃ��Cy��1�Ƃ���.
	const int id = 100, xy = 2;
	//dec�͌��肳�ꂽid�ɑ΂��ď������s���ϐ��ł���(�͂��ߑI��iID�����߂邽��const�Ő錾���Ă͂����Ȃ�)
	//decmin�͓K���Ɍ��߂Ă���(141���傫����Ε��C??)
	//box�̓��[�N���b�h�v�Z�����l���i�[����ϐ�
	int p[id][xy], dec, groupid = 0, tag[100] = { 0 };

	//���ρC�d�S�����߂�ϐ�
	int cntx[id] = { 0 }, cnty[id] = { 0 };


	float decmin = 1000.0, box = 0.0;
	//pdec��p�ɑ΂��ď������Ȃ��ꂽ�Ƃ���1,������0��false�ł���D
	bool pdec[id] = { 0 };

	for (i = 0; i < id; i++) {
		for (j = 0; j < xy; j++) {
			p[i][j] = rand() % 100 + 1;
			printf("%d,", p[i][j]);
			//Excel���o�p
		}
		printf("\n");
	}
	printf("\n");

	//ID�̑I��(�����_��)
	dec = rand() % id;
	printf("�ŏ��ɑI�΂ꂽID��[%d]\n", dec);

	while (pdec[dec] == false) {
		//pdec�ŏ���ID�����_���ɑ΂���true������.
		pdec[dec] = 1;

		//����X�V����K�v�̂���l(�]���l�̍X�V����)
		decmin = 1000.0;
		//ID�̕\��
		printf("ID[%d]---GROUPID[%d] ", dec, tag[dec]);

		//�ŒZ�����̌v�Z
		printf("�ŒZ����");
		for (i = 0; i < id; i++) {
			//pdec���߂ɑI�΂ꂽ�̂�1�Ȃ̂Ŏ������g���I�΂�邱�Ƃ͂Ȃ�
			if (pdec[i] == 0) {
				box = euclid(p[dec][0], p[dec][1], p[i][0], p[i][1]);
				//�ŏ��̔�r�͒ʂ�(decmin��1000�̂���)
				if (box < decmin) {
					decmin = box;
					printf("%.2f,", decmin);
					//dec�̑I���if�ŉ�肫�����Ō�̒li�ɂȂ邽�߂Ȃ̂͊ԈႢ
					j = i;
				}
			}
		}

		//�^�O�t������v���O����
		if (decmin >= 10) {
			groupid++;
		}
		tag[j] = groupid;

		//x,y�̒l�𑫂��Ă���
		cntx[groupid] += p[j][0];
		cnty[groupid] += p[j][1];
		printf("GROUPID�̍��v�l[%d]x:[%d]y:[%d]", groupid, cntx[groupid], cnty[groupid]);


		//dec�̓��[�v�𔲂Ă��Ă���X�V����.
		dec = j;

		printf("\n");
	}

	//-----------------------------------------------------------------------------------------------








	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int main(void) {
	int i,j,tmp;
	//�z��Ɋi�[����ϐ��Ɋւ��Ă�const int�̕����ǂ�??
	const int num = 100;
	int st[num],ans[num];
	//���񗐐����قȂ�l�ɂ���D
	srand((unsigned int)time(NULL));
	//�����̐���100��
	printf("�����̐���\n");
	for (i = 0; i < 100; i++) {
			st[i] = rand() % 100 + 1;
			ans[i] = st[i];
			printf("%d,",st[i]);		
	}
	printf("\n");
	
	//�o�u���\�[�g����
	printf("��������\�[�g����\n");
	for (i = 0; i < num; i++) {
		for (j =i+1; j < num; j++) {
			if (ans[i] > ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	//����(����)
	for (i = 0; i < 100; i+=10) {
		for (j = 0; j < 10; j++) {
			printf("%d,", ans[i+j]);
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

	return 0;
}
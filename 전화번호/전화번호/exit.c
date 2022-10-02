// fopen, fclose, fprintf, fscanf
#include<stdio.h>
// ����� �ڷ���
#include"my_struct.h"
//fopen ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

// �Լ� end�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void end(Phonelist* head) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	Phonelist* file_p = NULL;
	file_p = head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt ������ w(����) ���� ����
	fp = fopen("PHONE_BOOK.txt", "w");

	// file_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
	while (file_p->next != NULL) {

		/*
		fprintf: ���ڿ��� ���Ͽ� ����
		file_p->next->next�� NULL�̸� fprintf �ƴϸ� else�� �̵��ϰ� fprintf
		���� ���� ������ ���� �ʱ� ����.
		*/
		if (file_p->next->next == NULL) {
			fprintf(fp, "%s %s", file_p->name, file_p->phone_num);
		}
		else {
			fprintf(fp, "%s %s\n", file_p->name, file_p->phone_num);
		}

		// �����ͺ��� file_p�� file_p->next�� ����Ų��.
		file_p = file_p->next;
	}
	// ���� ������ �ݱ�
	fclose(fp);

	return 0;
}
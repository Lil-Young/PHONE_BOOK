// fopen, fclose, fscanf, printf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strcmp
#include<string.h>
//
#include"my_struct.h"

// �Լ� open_F�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void open_F(Phonelist*head, Phonelist* tail, int* cnt) {

	// �����ͺ��� ���� �� �ʱ�ȭ
	Phonelist* open_p = NULL;
	Phonelist* newNode = NULL;
	FILE* fp = NULL;

	// ���� ����
	char name[10];
	char number[15];

	// ���� ���� �� �ʱ�ȭ
	int is_eof = 0;

	// PHONE_BOOK.txt ������ r(�б�) ���� ����
	fp = fopen("PHONE_BOOK.txt", "r");
	// fp�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
	if (fp == NULL) {
		printf("��ȭ��ȣ�ΰ� �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("��ȭ��ȣ�θ� �ҷ��ɴϴ�.\n");
	}

	// ���ѷ���
	while (1) {
		// fscanf(fp, "%s %s", name, number)���� name, number�� ���� ���� �� ������ EOF�� ��ȯ
		is_eof = fscanf(fp, "%s %s", name, number);

		// is_eof�� EOF�� ��ġ�ϸ� ������ ���̹Ƿ� �ݺ����� Ż���ϱ� ���� break�� �Ѵ�.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num �޸� �Ҵ�
		newNode = (Phonelist*)malloc(sizeof(Phonelist));
		newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
		newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

		// strcpy�� name�� �ִ� ���ڿ��� newNode->name���� ����, number�� �ִ� ���ڿ��� newNode->phone_num���� ����
		strcpy(newNode->name, name);
		strcpy(newNode->phone_num, number);

		// newNode ����
		open_p = tail->prev;
		newNode->next = open_p->next;
		newNode->prev = open_p;
		open_p->next = newNode;
		tail->prev = newNode;

		// cnt�� 1����
		(*cnt)++;
	}
	// ���� ������ �ݱ�
	fclose(fp);

	return 0;
}
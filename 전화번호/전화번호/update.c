// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

// �Լ� update�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void update(Phonelist* head, Phonelist* tail) {

	// ������ �����ͺ��� ���� �� �ʱ�ȭ
	Phonelist* update_node;
	Phonelist* newNode = NULL;
	char name[10];
	char number[15];

	// �����ͺ��� update_p�� head->next�� ����Ų��.
	update_node = head->next;
	printf("�����ϰ���� �̸��� �Է��ϼ���: ");

	// scanf�� name�� �Է¹޴´�.
	scanf("%s", name);

	// update_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
	while (update_node->next != NULL) {

		// strcmp�� update_node->name�� name�� ���ڿ��� ��ġ�ϸ� 0�� ��ȯ�Ѵ�.
		if (strcmp(update_node->name, name) == 0) {
			printf("�����ϰ���� ��ȭ��ȣ�� �Է��ϼ���: ");

			// scanf�� number�� �Է¹޴´�.
			scanf("%s", number);

			// update_node->phone_num �޸� ����
			free(update_node->phone_num);

			// update_node->phone_num �޸� �Ҵ�
			update_node->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

			// strcpy�� number�� �ִ� ���ڿ��� update_node->phone_num���� ����
			strcpy(update_node->phone_num, number);
			break;
		}
		// �����ͺ��� update_node�� update_node->next�� ����Ų��.
		update_node = update_node->next;
	}
	// update_node->next�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
	if (update_node->next == NULL) {
		printf("�����ϰ���� �̸��� ���������ʽ��ϴ�.\n");
	}
	else {
		printf("��ȭ��ȣ�� %s�� �����մϴ�.\n", number);
	}
	return 0;
}
#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����
//test3
void update(Phonelist* head, Phonelist* tail) {
	Phonelist* update_node;
	Phonelist* newNode = NULL;
	char name[10];
	char number[15];
	update_node = head->next;
	printf("�����ϰ���� �̸��� �Է��ϼ���: ");
	scanf("%s", name);
	while (update_node->next != NULL) {
		if (strcmp(update_node->name, name) == 0) {
			printf("�����ϰ���� ��ȭ��ȣ�� �Է��ϼ���: ");
			scanf("%s", number);
			free(update_node->phone_num);
			update_node->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);
			strcpy(update_node->phone_num, number);
			break;
		}
		update_node = update_node->next;
	}
	if (update_node->next == NULL) {
		printf("�����ϰ���� �̸��� ���������ʽ��ϴ�.\n");
	}
	else {
		printf("��ȭ��ȣ�� %s�� �����մϴ�.\n", number);
	}
	return 0;
}
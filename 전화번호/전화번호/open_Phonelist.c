#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����

void open_P(Phonelist*head, Phonelist* tail, int* cnt) { // github test
	FILE* fp = NULL;
	fp = fopen("c.txt", "r");
	Phonelist* open_p = NULL;
	Phonelist* newNode = NULL;
	char name[15];
	char number[15];
	int is_eof = 0;
	if (fp == NULL) {
		printf("������ �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("������ �ҷ��ɴϴ�.\n");
	}
	while (1) {
		is_eof = fscanf(fp, "%s %s", name, number); // fscanf(fp, "%s %s", name, number)�� -1�� ��ȯ
		if (is_eof == EOF) { // EOF�� -1
			break;
		}
		newNode = (Phonelist*)malloc(sizeof(Phonelist));
		newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
		newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);
		strcpy(newNode->name, name);
		strcpy(newNode->phone_num, number);

		open_p = tail->prev;
		newNode->next = open_p->next;
		newNode->prev = open_p;
		open_p->next = newNode;
		tail->prev = newNode;
		(*cnt)++;
	}
	fclose(fp);
	return 0;
}
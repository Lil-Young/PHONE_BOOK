#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언

void open_P(Phonelist*head, Phonelist* tail, int* cnt) { // github test
	FILE* fp = NULL;
	fp = fopen("c.txt", "r");
	Phonelist* open_p = NULL;
	Phonelist* newNode = NULL;
	char name[15];
	char number[15];
	int is_eof = 0;
	if (fp == NULL) {
		printf("파일이 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("파일을 불러옵니다.\n");
	}
	while (1) {
		is_eof = fscanf(fp, "%s %s", name, number); // fscanf(fp, "%s %s", name, number)는 -1을 반환
		if (is_eof == EOF) { // EOF는 -1
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
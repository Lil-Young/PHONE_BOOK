#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언
//test3
void update(Phonelist* head, Phonelist* tail) {
	Phonelist* update_node;
	Phonelist* newNode = NULL;
	char name[10];
	char number[15];
	update_node = head->next;
	printf("수정하고싶은 이름을 입력하세요: ");
	scanf("%s", name);
	while (update_node->next != NULL) {
		if (strcmp(update_node->name, name) == 0) {
			printf("수정하고싶은 전화번호를 입력하세요: ");
			scanf("%s", number);
			free(update_node->phone_num);
			update_node->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);
			strcpy(update_node->phone_num, number);
			break;
		}
		update_node = update_node->next;
	}
	if (update_node->next == NULL) {
		printf("수정하고싶은 이름이 존재하지않습니다.\n");
	}
	else {
		printf("전화번호를 %s로 수정합니다.\n", number);
	}
	return 0;
}
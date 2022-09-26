// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

// 함수 update를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void update(Phonelist* head, Phonelist* tail) {

	// 변수와 포인터변수 선언 및 초기화
	Phonelist* update_node;
	Phonelist* newNode = NULL;
	char name[10];
	char number[15];

	// 포인터변수 update_p는 head->next를 가리킨다.
	update_node = head->next;
	printf("수정하고싶은 이름을 입력하세요: ");

	// scanf로 name을 입력받는다.
	scanf("%s", name);

	// update_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
	while (update_node->next != NULL) {

		// strcmp로 update_node->name과 name의 문자열이 일치하면 0을 반환한다.
		if (strcmp(update_node->name, name) == 0) {
			printf("수정하고싶은 전화번호를 입력하세요: ");

			// scanf로 number을 입력받는다.
			scanf("%s", number);

			// update_node->phone_num 메모리 해제
			free(update_node->phone_num);

			// update_node->phone_num 메모리 할당
			update_node->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

			// strcpy로 number에 있는 문자열을 update_node->phone_num으로 복사
			strcpy(update_node->phone_num, number);
			break;
		}
		// 포인터변수 update_node는 update_node->next를 가리킨다.
		update_node = update_node->next;
	}
	// update_node->next가 NULL이면 printf 아니면 else로 이동하고 printf
	if (update_node->next == NULL) {
		printf("수정하고싶은 이름이 존재하지않습니다.\n");
	}
	else {
		printf("전화번호를 %s로 수정합니다.\n", number);
	}
	return 0;
}
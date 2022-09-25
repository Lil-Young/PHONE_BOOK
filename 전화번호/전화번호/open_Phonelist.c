// fopen, fclose, fscanf, printf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcpy, strcmp
#include<string.h>
//
#include"my_struct.h"

// 함수 open_F을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void open_F(Phonelist*head, Phonelist* tail, int* cnt) {

	// 포인터변수 선언 및 초기화
	Phonelist* open_p = NULL;
	Phonelist* newNode = NULL;
	FILE* fp = NULL;

	// 변수 선언
	char name[10];
	char number[15];

	// 변수 선언 및 초기화
	int is_eof = 0;

	// PHONE_BOOK.txt 파일을 r(읽기) 모드로 열기
	fp = fopen("PHONE_BOOK.txt", "r");
	// fp가 NULL이면 printf 아니면 else로 이동하고 printf
	if (fp == NULL) {
		printf("전화번호부가 존재하지 않습니다.\n");
		return 0;
	}
	else {
		printf("전화번호부를 불러옵니다.\n");
	}

	// 무한루프
	while (1) {
		// fscanf(fp, "%s %s", name, number)에서 name, number의 값을 읽을 수 없으면 EOF를 반환
		is_eof = fscanf(fp, "%s %s", name, number);

		// is_eof와 EOF가 일치하면 파일의 끝이므로 반복문을 탈출하기 위해 break를 한다.
		if (is_eof == EOF) {
			break;
		}
		// newNode, newNode->name, newNode->phone_num 메모리 할당
		newNode = (Phonelist*)malloc(sizeof(Phonelist));
		newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
		newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

		// strcpy로 name에 있는 문자열을 newNode->name으로 복사, number에 있는 문자열을 newNode->phone_num으로 복사
		strcpy(newNode->name, name);
		strcpy(newNode->phone_num, number);

		// newNode 연결
		open_p = tail->prev;
		newNode->next = open_p->next;
		newNode->prev = open_p;
		open_p->next = newNode;
		tail->prev = newNode;

		// cnt를 1증가
		(*cnt)++;
	}
	// 파일 포인터 닫기
	fclose(fp);

	return 0;
}
// printf
#include<stdio.h>
// malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// 사용할 자료형
#include"my_struct.h"

// 함수 insert를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void insert(Phonelist* tail, char* name, char* number, int* cnt) {
    
    // 포인터 변수 선언 및 초기화
    Phonelist* insert_p = NULL;
    Phonelist* newNode = NULL;

    // newNode, newNode->name, newNode->phone_num 메모리 할당
    newNode = (Phonelist*)malloc(sizeof(Phonelist));
    newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

    // strcpy로 name에 있는 문자열을 newNode->name으로 복사, number에 있는 문자열을 newNode->phone_num으로 복사
    strcpy(newNode->name, name);
    strcpy(newNode->phone_num, number);

    // newNode 연결
    insert_p = tail->prev;
    newNode->next = insert_p->next;
    newNode->prev = insert_p;
    insert_p->next = newNode;
    tail->prev = newNode;

    //cnt를 1증가
    (*cnt)++;

    printf("%s, %s를 삽입합니다.\n", insert_p->next->name, insert_p->next->phone_num);
    return 0;
}
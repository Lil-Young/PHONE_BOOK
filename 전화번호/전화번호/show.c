#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언

void show(Phonelist* head, Phonelist* tail, int* cnt) {
    int count = 1;
    Phonelist* show_p = NULL;
    show_p = head->next;
    printf("전화번호부안에는 %d개의 연락처가 있습니다.\n", (*cnt));
    while (show_p->next != NULL) {
        printf("%d. 성함: %s, 전화번호: %s\n", count, (show_p->name), (show_p->phone_num));
        show_p = show_p->next;
        count++;
    }
    return 0;
}
// printf, scanf
#include<stdio.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

// 함수 show를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void show(Phonelist* head, Phonelist* tail, int* cnt) {

    // 변수와 포인터변수 선언 및 초기화
    int count = 1;
    Phonelist* show_p = NULL;

    // 포인터변수 show_p는 head->next를 가리킨다.
    show_p = head->next;
    printf("전화번호부안에는 %d개의 연락처가 있습니다.\n", (*cnt));

    // show_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
    while (show_p->next != NULL) {
        printf("%d. 이름: %s, 전화번호: %s\n", count, (show_p->name), (show_p->phone_num));

        // 포인터변수 show_p는 show_p->next를 가리킨다.
        show_p = show_p->next;

        //count를 1증가
        count++;
    }
    return 0;
}
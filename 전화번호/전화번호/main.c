// printf, scanf
#include<stdio.h>
// malloc
#include<stdlib.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

/*
* printf는 문자열을 출력하는 함수
* return 0은 함수를 종료한다.
* break는 반복문을 탈출시킨다 또한 switch문을 탈출시킨다.
*/
int main(void) {
    // 변수와 포인터변수 선언 및 초기화
    int cnt = 0;
    int select = 0;
    Phonelist* head = NULL;
    Phonelist* tail = NULL;

    // head, tail 메모리할당
    head = (Phonelist*)malloc(sizeof(Phonelist));
    tail = (Phonelist*)malloc(sizeof(Phonelist));

    // head 초기화
    head->next = NULL;
    head->prev = NULL;
    head->name = NULL;
    head->phone_num = NULL;

    // tail 초기화
    tail->next = NULL;
    tail->prev = NULL;
    tail->name = NULL;
    tail->phone_num = NULL;

    // head, tail 연결
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;

    // 파일불러오기
    // oepn_F 함수를 호출하고 인자들을 전달한다.
    open_F(head, tail, &cnt);
    // 변수 선언
    char name[10];
    char number[15];

    printf("\t\t *** Function -> 1: Insert, 2: Show, 3: Delete, 4: Update, 5: All_delete, 6: Exit *** \n");
    printf("\t\t\t\t\t *** never input string in \"select\" ***\n");

    // 무한루프
    while (1) {
        printf("Select Function: ");
        // scanf로 select를 입력받는다.
        scanf("%d", &select);
        // 조건문 switch~case로 select와 일치하는 case로 이동한다.
        switch (select) {
        case 1:
            // scanf로 name, number를 입력받는다.
            printf("Name: ");
            scanf("%s", name);
            printf("Number: ");
            scanf("%s", number);
            // insert 함수를 호출하고 인자들을 전달한다.
            insert(tail, name, number, &cnt);
            break;
        case 2:
            // show 함수를 호출하고 인자들을 전달한다.
            show(head, &cnt);
            break;
        case 3:
            // del 함수를 호출하고 인자들을 전달한다.
            del(head, &cnt);
            break;
        case 4:
            // update 함수를 호출하고 인자들을 전달한다.
            update(head);
            break;
        case 5:
            // all_del 함수를 호출하고 인자들을 전달한다.
            all_del(head, &cnt);
            break;
        case 6:
            // end 함수를 호출하고 인자들을 전달한다.
            end(head);
            printf("전화번호부를 저장하고 종료합니다.\n");
            return 0;
        default :
            printf("Try again (1, 2, 3, 4, 5, 6)\n");
            break;
        }
    }
}
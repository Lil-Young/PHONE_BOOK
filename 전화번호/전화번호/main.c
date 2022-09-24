#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언




int main(void) {
    int cnt = 0;
    int select = 0;
    Phonelist* head = NULL;
    Phonelist* tail = NULL;
    Phonelist* cur = NULL;
    Phonelist* p = NULL;
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
    open_P(head, tail, &cnt);

    char name[10];
    char number[15];
    printf("\t\t\t\t\t*** Select 1, 2, 3, 4, 5, 6 ***\n");
    printf("\t\t *** 1: Insert, 2: Show, 3: Delete, 4: Update, 5: All_delete, 6: Exit *** \n");
    printf("\t\t\t\t\t *** never input string in \"select\" ***\n");
    while (1) {
        printf("select function: ");
        scanf("%d", &select);
        switch (select) {
        case 1:
            printf("Name: ");
            scanf("%s", name);
            printf("Number: ");
            scanf("%s", number);
            insert(tail, name, number, &cnt);
            break;
        case 2:
            show(head, tail, &cnt);
            break;
        case 3:
            del(head, tail, &cnt);
            break;
        case 4:
            update(head, tail);
            break;
        case 5:
            all_del(head, tail, &cnt);
            break;
        case 6:
            end(head, tail);
            printf("전화번호부가 종료되었습니다.\n");
            return 0;
        default:
            printf("Try again(1, 2, 3, 4, 5, 6, 7)\n");
            break;
        }
    }
    return 0;
}
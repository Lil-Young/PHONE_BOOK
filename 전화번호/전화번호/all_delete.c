// printf
#include<stdio.h>
// free
#include<stdlib.h>
//
#include"my_struct.h"

// 함수 all_del을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void all_del(Phonelist* head, Phonelist* tail, int* cnt) {

    // 포인터변수 선언 및 초기화
    Phonelist* all_del_node = head->next;

    // all_del_node->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
    while (all_del_node->next != NULL) {

        // all_del_node가 가리키는 노드 양옆에 있는 노드들 연결
        all_del_node->prev->next = all_del_node->next;
        all_del_node->next->prev = all_del_node->prev;

        // all_del_node->name, all_del_node->phone_num, all_del_node 메모리 해제
        free(all_del_node->name);
        free(all_del_node->phone_num);
        free(all_del_node);

        // 포인터변수 all_del_node는 head->next를 가리킨다.
        all_del_node = head->next;

        // cnt를 1감소
        (*cnt)--;
    }
    printf("전화번호부를 초기화합니다.\n");
    return 0;
}
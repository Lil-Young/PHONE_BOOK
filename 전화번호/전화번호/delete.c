// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcmp
#include<string.h>
// 사용할 자료형
#include"my_struct.h"
// scanf 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

// 함수 del을 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void del(Phonelist* head, int* cnt) {

    // 변수와 포인터변수 선언 및 초기화
    Phonelist* del_node = head->next;
    char name[10];

    printf("삭제하고싶은 이름을 입력해주세요: ");
    // scanf로 name을 입력받는다.
    scanf("%s", name);

    // del_node->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
    while (del_node->next != NULL) {
        // strcmp로 del_node->name과 name의 문자열이 일치하면 0을 반환한다.
        if (strcmp(del_node->name, name) == 0) {
            break;
        }
        // 포인터변수 del_node는 del_node->next를 가리킨다.
        del_node = del_node->next;
    }
    // del_node->next가 NULL이면 printf 아니면 else로 이동하고 printf
    if (del_node->next == NULL) {
        printf("삭제하려는 이름이 존재하지 않습니다.\n");
    }
    else {
        printf("%s, %s를 삭제합니다.\n", del_node->name, del_node->phone_num);

        // del_node가 가리키는 노드 양옆에 있는 노드들 연결
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;

        // del_node->name, del_node->phone_num, del_node 메모리 해제
        free(del_node->name);
        free(del_node->phone_num);
        free(del_node);

        // cnt를 1감소
        (*cnt)--;;
    }

    return 0;
}
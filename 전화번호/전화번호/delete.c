#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언

void del(Phonelist* head, Phonelist* tail, int* cnt) {
    Phonelist* del_node = head->next;

    char name[10];
    printf("삭제하고싶은 이름을 입력해주세요: ");
    scanf("%s", name);
    while (del_node->next != NULL) {
        if (strcmp(del_node->name, name) == 0) {
            break;
        }
        del_node = del_node->next;
    }
    if (del_node->next == NULL) {
        printf("삭제하려는 이름이 존재하지 않습니다.\n");
    }
    else {
        printf("%s, %s를 삭제합니다.\n", del_node->name, del_node->phone_num);
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
        free(del_node->name);
        free(del_node->phone_num);
        free(del_node);
        (*cnt)--;;
    }

    return 0;
}
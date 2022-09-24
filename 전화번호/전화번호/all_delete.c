#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include<stdlib.h> //free, malloc 사용을 위해 헤더파일 선언
#include<string.h> //strcpy 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf 에러방지를 위해 선언
// update를 하고 all_delte를하면 터짐 -? 해결은했는데 update를 저렇게하는게 맞는지 의심이듦
void all_del(Phonelist* head, Phonelist* tail, int* cnt) {
    Phonelist* all_del_node = head->next;
    while (all_del_node->next != NULL) {
        all_del_node->prev->next = all_del_node->next;
        all_del_node->next->prev = all_del_node->prev;
        free(all_del_node->name);
        free(all_del_node->phone_num);
        free(all_del_node);
        (*cnt)--;;
        all_del_node = head->next;
    }
    printf("전화번호부를 초기화합니다.\n");
    return 0;
}
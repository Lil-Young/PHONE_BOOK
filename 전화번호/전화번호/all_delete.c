#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����
// update�� �ϰ� all_delte���ϸ� ���� -? �ذ����ߴµ� update�� �������ϴ°� �´��� �ǽ��̵�
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
    printf("��ȭ��ȣ�θ� �ʱ�ȭ�մϴ�.\n");
    return 0;
}
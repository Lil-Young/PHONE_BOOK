#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����

void del(Phonelist* head, Phonelist* tail, int* cnt) {
    Phonelist* del_node = head->next;

    char name[10];
    printf("�����ϰ���� �̸��� �Է����ּ���: ");
    scanf("%s", name);
    while (del_node->next != NULL) {
        if (strcmp(del_node->name, name) == 0) {
            break;
        }
        del_node = del_node->next;
    }
    if (del_node->next == NULL) {
        printf("�����Ϸ��� �̸��� �������� �ʽ��ϴ�.\n");
    }
    else {
        printf("%s, %s�� �����մϴ�.\n", del_node->name, del_node->phone_num);
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
        free(del_node->name);
        free(del_node->phone_num);
        free(del_node);
        (*cnt)--;;
    }

    return 0;
}
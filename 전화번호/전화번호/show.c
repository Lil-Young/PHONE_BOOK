#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
//#include<string>
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����

void show(Phonelist* head, Phonelist* tail, int* cnt) {
    int count = 1;
    Phonelist* show_p = NULL;
    show_p = head->next;
    printf("��ȭ��ȣ�ξȿ��� %d���� ����ó�� �ֽ��ϴ�.\n", (*cnt));
    while (show_p->next != NULL) {
        printf("%d. ����: %s, ��ȭ��ȣ: %s\n", count, (show_p->name), (show_p->phone_num));
        show_p = show_p->next;
        count++;
    }
    return 0;
}
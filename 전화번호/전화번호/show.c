// printf, scanf
#include<stdio.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

// �Լ� show�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void show(Phonelist* head, Phonelist* tail, int* cnt) {

    // ������ �����ͺ��� ���� �� �ʱ�ȭ
    int count = 1;
    Phonelist* show_p = NULL;

    // �����ͺ��� show_p�� head->next�� ����Ų��.
    show_p = head->next;
    printf("��ȭ��ȣ�ξȿ��� %d���� ����ó�� �ֽ��ϴ�.\n", (*cnt));

    // show_p->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
    while (show_p->next != NULL) {
        printf("%d. �̸�: %s, ��ȭ��ȣ: %s\n", count, (show_p->name), (show_p->phone_num));

        // �����ͺ��� show_p�� show_p->next�� ����Ų��.
        show_p = show_p->next;

        //count�� 1����
        count++;
    }
    return 0;
}
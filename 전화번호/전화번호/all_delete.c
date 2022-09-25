// printf
#include<stdio.h>
// free
#include<stdlib.h>
//
#include"my_struct.h"

// �Լ� all_del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void all_del(Phonelist* head, Phonelist* tail, int* cnt) {

    // �����ͺ��� ���� �� �ʱ�ȭ
    Phonelist* all_del_node = head->next;

    // all_del_node->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
    while (all_del_node->next != NULL) {

        // all_del_node�� ����Ű�� ��� �翷�� �ִ� ���� ����
        all_del_node->prev->next = all_del_node->next;
        all_del_node->next->prev = all_del_node->prev;

        // all_del_node->name, all_del_node->phone_num, all_del_node �޸� ����
        free(all_del_node->name);
        free(all_del_node->phone_num);
        free(all_del_node);

        // �����ͺ��� all_del_node�� head->next�� ����Ų��.
        all_del_node = head->next;

        // cnt�� 1����
        (*cnt)--;
    }
    printf("��ȭ��ȣ�θ� �ʱ�ȭ�մϴ�.\n");
    return 0;
}
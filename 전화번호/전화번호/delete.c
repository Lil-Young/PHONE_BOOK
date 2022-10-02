// printf, scanf
#include<stdio.h>
// free, malloc
#include<stdlib.h>
// strcmp
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

// �Լ� del�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void del(Phonelist* head, int* cnt) {

    // ������ �����ͺ��� ���� �� �ʱ�ȭ
    Phonelist* del_node = head->next;
    char name[10];

    printf("�����ϰ���� �̸��� �Է����ּ���: ");
    // scanf�� name�� �Է¹޴´�.
    scanf("%s", name);

    // del_node->next�� NULL�� �ƴϸ� �ݺ����� ������ NULL�� �Ǹ� �ݺ����� �����Ѵ�.
    while (del_node->next != NULL) {
        // strcmp�� del_node->name�� name�� ���ڿ��� ��ġ�ϸ� 0�� ��ȯ�Ѵ�.
        if (strcmp(del_node->name, name) == 0) {
            break;
        }
        // �����ͺ��� del_node�� del_node->next�� ����Ų��.
        del_node = del_node->next;
    }
    // del_node->next�� NULL�̸� printf �ƴϸ� else�� �̵��ϰ� printf
    if (del_node->next == NULL) {
        printf("�����Ϸ��� �̸��� �������� �ʽ��ϴ�.\n");
    }
    else {
        printf("%s, %s�� �����մϴ�.\n", del_node->name, del_node->phone_num);

        // del_node�� ����Ű�� ��� �翷�� �ִ� ���� ����
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;

        // del_node->name, del_node->phone_num, del_node �޸� ����
        free(del_node->name);
        free(del_node->phone_num);
        free(del_node);

        // cnt�� 1����
        (*cnt)--;;
    }

    return 0;
}
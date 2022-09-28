// printf
#include<stdio.h>
// malloc
#include<stdlib.h>
// strcpy, strlen
#include<string.h>
// ����� �ڷ���
#include"my_struct.h"

// �Լ� insert�� void������ �����ϰ� �Ű�����(�Ķ����)�� ���޵� ���ڸ� �޴´�.
void insert(Phonelist* tail, char* name, char* number, int* cnt) {
    
    // ������ ���� ���� �� �ʱ�ȭ
    Phonelist* insert_p = NULL;
    Phonelist* newNode = NULL;

    // newNode, newNode->name, newNode->phone_num �޸� �Ҵ�
    newNode = (Phonelist*)malloc(sizeof(Phonelist));
    newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);

    // strcpy�� name�� �ִ� ���ڿ��� newNode->name���� ����, number�� �ִ� ���ڿ��� newNode->phone_num���� ����
    strcpy(newNode->name, name);
    strcpy(newNode->phone_num, number);

    // newNode ����
    insert_p = tail->prev;
    newNode->next = insert_p->next;
    newNode->prev = insert_p;
    insert_p->next = newNode;
    tail->prev = newNode;

    //cnt�� 1����
    (*cnt)++;

    printf("%s, %s�� �����մϴ�.\n", insert_p->next->name, insert_p->next->phone_num);
    return 0;
}
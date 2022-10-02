// printf, scanf
#include<stdio.h>
// malloc
#include<stdlib.h>
// ����� �ڷ���
#include"my_struct.h"
// scanf ���� ���� ���� ������ ���� ����
#define _CRT_SECURE_NO_WARINGS

/*
* printf�� ���ڿ��� ����ϴ� �Լ�
* return 0�� �Լ��� �����Ѵ�.
* break�� �ݺ����� Ż���Ų�� ���� switch���� Ż���Ų��.
*/
int main(void) {
    // ������ �����ͺ��� ���� �� �ʱ�ȭ
    int cnt = 0;
    int select = 0;
    Phonelist* head = NULL;
    Phonelist* tail = NULL;

    // head, tail �޸��Ҵ�
    head = (Phonelist*)malloc(sizeof(Phonelist));
    tail = (Phonelist*)malloc(sizeof(Phonelist));

    // head �ʱ�ȭ
    head->next = NULL;
    head->prev = NULL;
    head->name = NULL;
    head->phone_num = NULL;

    // tail �ʱ�ȭ
    tail->next = NULL;
    tail->prev = NULL;
    tail->name = NULL;
    tail->phone_num = NULL;

    // head, tail ����
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;

    // ���Ϻҷ�����
    // oepn_F �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
    open_F(head, tail, &cnt);
    // ���� ����
    char name[10];
    char number[15];

    printf("\t\t *** Function -> 1: Insert, 2: Show, 3: Delete, 4: Update, 5: All_delete, 6: Exit *** \n");
    printf("\t\t\t\t\t *** never input string in \"select\" ***\n");

    // ���ѷ���
    while (1) {
        printf("Select Function: ");
        // scanf�� select�� �Է¹޴´�.
        scanf("%d", &select);
        // ���ǹ� switch~case�� select�� ��ġ�ϴ� case�� �̵��Ѵ�.
        switch (select) {
        case 1:
            // scanf�� name, number�� �Է¹޴´�.
            printf("Name: ");
            scanf("%s", name);
            printf("Number: ");
            scanf("%s", number);
            // insert �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            insert(tail, name, number, &cnt);
            break;
        case 2:
            // show �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            show(head, &cnt);
            break;
        case 3:
            // del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            del(head, &cnt);
            break;
        case 4:
            // update �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            update(head);
            break;
        case 5:
            // all_del �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            all_del(head, &cnt);
            break;
        case 6:
            // end �Լ��� ȣ���ϰ� ���ڵ��� �����Ѵ�.
            end(head);
            printf("��ȭ��ȣ�θ� �����ϰ� �����մϴ�.\n");
            return 0;
        default :
            printf("Try again (1, 2, 3, 4, 5, 6)\n");
            break;
        }
    }
}
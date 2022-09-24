#include<stdio.h> //printf, scanf ����� ���� ������� ����
#include<stdlib.h> //free, malloc ����� ���� ������� ����
#include<string.h> //strcpy ����� ���� ������� ����
#include"my_struct.h"
#define _CRT_SECURE_NO_WARINGS //scanf ���������� ���� ����
int insert(Phonelist* tail, char* name, char* number, int* cnt) {
    Phonelist* insert_p = NULL;
    Phonelist* newNode = NULL;

    newNode = (Phonelist*)malloc(sizeof(Phonelist));
    newNode->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    newNode->phone_num = (char*)malloc(sizeof(char) * strlen(number) + 1);
    strcpy(newNode->name, name);
    strcpy(newNode->phone_num, number);

    insert_p = tail->prev;
    newNode->next = insert_p->next;
    newNode->prev = insert_p;
    insert_p->next = newNode;
    tail->prev = newNode;
    (*cnt)++;

    return 0;
}
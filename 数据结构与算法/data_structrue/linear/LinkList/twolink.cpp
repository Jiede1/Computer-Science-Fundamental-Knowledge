//˫������
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
};

//����ڵ����
void insertValue(){
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}


//ɾ���ڵ����
void delete_value(){
    p->next=q->next;
    q->next->prior=p;
    free(q);
}

//�������

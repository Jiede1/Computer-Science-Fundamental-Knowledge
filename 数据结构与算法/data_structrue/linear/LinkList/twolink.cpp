//双向链表
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
};

//插入节点操作
void insertValue(){
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}


//删除节点操作
void delete_value(){
    p->next=q->next;
    q->next->prior=p;
    free(q);
}

//求表长操作

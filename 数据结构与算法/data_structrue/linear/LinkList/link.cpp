// ����
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void InitList(LNode *L){
    cout<<L<<endl;


	L = (LNode *)malloc( sizeof( LNode) );
	(L)->next = NULL;
	(L)->data=1;
	cout<<L<<endl;
}

// ͷ�巨
LinkList List_HeadInsert(LinkList &L){
    //ÿ�ξ���ͷ�ڵ�֮�����Ԫ��
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

//β�巨
LinkList List_TailInsert(LinkList &L){
    //ÿ�ξ��ڱ�β֮�����Ԫ��
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r=L; //��βָ��
    scanf("%d",&x);
    while(x!=9999){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    return L;
}

//�����ȡ������Ԫ��
LinkList getElem(LinkList L, int n){
    int j =1;
    LNode *p=L->next;
    if(n==0){
        return L;
    }
    if(n<1)
        return NULL;
    while(p&&j<n){
        printf("%d\n",p->data);
        p=p->next;
        j++;
    }
    return p;
}

//��ֵ����
LNode *locateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL && p->data!=e)
        p=p->next;
    cout<<p->data;
    return p;
}

//��������
void inser_value(LinkList L,int i, LinkList s){
    LinkList p = getElem(L,i-1);
    s->next = p->next;
    p->next =s;
}
//ǰ��
void insetBack(){
    //�ɻ��ں����ɺ󽻻��²���ڵ��ǰ���ڵ��data
}

//ɾ���ڵ����
void delete_value(LinkList L, int i){
    LinkList p= getElem(L,i-1); // Ҫɾ���ڵ��ǰ���ڵ�
    LinkList q=p->next;
    p->next = q->next;
    free(q);
}

//ɾ��ĳ�ڵ��ͨ��ɾ�����̽ڵ㣬���������ڵ��dataֵ�Ϳ�


//���

int mainlink(){
    /*
    LNode *newlist;
    cout<<newlist<<endl;
    cout<<&newlist<<endl;
    InitList(newlist);
    cout<<newlist<<endl;
    */

    LNode *L;
    List_TailInsert(L);
    //getElem(L,4);
    //locateElem(L,4);
    LinkList s  = (LinkList) malloc(sizeof(LNode));
    s->next=NULL;
    s->data=878;
    inser_value(L,3,s);
    printf("after insert\n");
    getElem(L,5);
    /*
    int* p;
    int i=10;
    p=&i;
    cout<<p<<','<<*p<<endl;
    *p=20;
    cout<<p<<','<<*p<<endl;
    cout<<i<<endl;
    */
}



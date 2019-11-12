// 链表
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

// 头插法
LinkList List_HeadInsert(LinkList &L){
    //每次均在头节点之后插入元素
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

//尾插法
LinkList List_TailInsert(LinkList &L){
    //每次均在表尾之后插入元素
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r=L; //表尾指针
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

//按序号取出链表元素
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

//按值查找
LNode *locateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL && p->data!=e)
        p=p->next;
    cout<<p->data;
    return p;
}

//后插入操作
void inser_value(LinkList L,int i, LinkList s){
    LinkList p = getElem(L,i-1);
    s->next = p->next;
    p->next =s;
}
//前插
void insetBack(){
    //可基于后插完成后交换新插入节点和前驱节点的data
}

//删除节点操作
void delete_value(LinkList L, int i){
    LinkList p= getElem(L,i-1); // 要删除节点的前驱节点
    LinkList q=p->next;
    p->next = q->next;
    free(q);
}

//删除某节点可通过删除其后继节点，并交换两节点的data值就可


//求表长

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



///一级指针
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof (Node)  //定义struct List这个类型的长度

typedef struct List  //定义结构体
{
	int num;
	struct List *next;
}Node,*LinkList;

LinkList create(LinkList head)  //创建单链表,注意函数的形参是一个叫head的结构体指针
{
	LinkList p1,p2;  //p1,p2也是结构体的指针类型
	int i,m=10;
	head=p1=(LinkList)malloc(LEN);  //申请内存，直接使用head(一级指针)
	head->next = NULL;        //直接使用head
	for(i=1;i<m;i++)
	{
		p2=(LinkList)malloc(LEN);  //尾插法建立链表
		p2->num=i;
		p1->next=p2;
		p1=p2;
	}
	p2->next=NULL;
	return head;  //使用一级指针时，返回的仍然是链表的指针，在调用时要有一个同类型的指针去接收才能使用链表
}
int mainOne()
{
	LinkList L=NULL;
	int i;
	L=create(L);  //在调用时要有一个同类型的指针去接收
	while(L->next != NULL)
	{
		L =L->next;
		printf("%d",L->num);
	}
	return 0;
}

///二级指针
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof (Node)  //定义struct List这个类型的长度
#define OK 1
#define ERROR 0

int create(LinkList *head)//(参数为二级指针)LinkList本身就是一个指针类型，而head前面还有一个*，说明head是指针的指针，也就是二级指针
{
	LinkList p1,p2;  //p1,p2是一级指针
	int i,m=10;
	*head=p1=(LinkList)malloc(LEN);       //申请内存，因为*head相当于一级指针，所以这里使用*head
	(*head)->next = NULL;                 //由于*的运算优先级低于成员操作符->,所以这里要加括号
	for(i=1;i<m;i++)
	{
		p2=(LinkList)malloc(LEN);  //尾插法建立链表
		p2->num=i;
		p1->next=p2;
		p1=p2;
	}
	p2->next=NULL;
	return OK;//注意使用二级指针时可以直接在函数中对链表进行操作，不需要返回链表，因此返回值可以是一个状态
}
int mainTwo()
{
	LinkList L;
	int i=0;
	create(&L);           //实参传入指针的地址，也就是二级指针，直接在函数中实现了对链表的操作，不再需要用其他指针去接收
	while(L->next != NULL)
	{
		L =L->next;
		printf("%d",L->num);
	}
	return 0;
}


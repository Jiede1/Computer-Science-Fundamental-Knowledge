///һ��ָ��
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof (Node)  //����struct List������͵ĳ���

typedef struct List  //����ṹ��
{
	int num;
	struct List *next;
}Node,*LinkList;

LinkList create(LinkList head)  //����������,ע�⺯�����β���һ����head�Ľṹ��ָ��
{
	LinkList p1,p2;  //p1,p2Ҳ�ǽṹ���ָ������
	int i,m=10;
	head=p1=(LinkList)malloc(LEN);  //�����ڴ棬ֱ��ʹ��head(һ��ָ��)
	head->next = NULL;        //ֱ��ʹ��head
	for(i=1;i<m;i++)
	{
		p2=(LinkList)malloc(LEN);  //β�巨��������
		p2->num=i;
		p1->next=p2;
		p1=p2;
	}
	p2->next=NULL;
	return head;  //ʹ��һ��ָ��ʱ�����ص���Ȼ�������ָ�룬�ڵ���ʱҪ��һ��ͬ���͵�ָ��ȥ���ղ���ʹ������
}
int mainOne()
{
	LinkList L=NULL;
	int i;
	L=create(L);  //�ڵ���ʱҪ��һ��ͬ���͵�ָ��ȥ����
	while(L->next != NULL)
	{
		L =L->next;
		printf("%d",L->num);
	}
	return 0;
}

///����ָ��
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof (Node)  //����struct List������͵ĳ���
#define OK 1
#define ERROR 0

int create(LinkList *head)//(����Ϊ����ָ��)LinkList�������һ��ָ�����ͣ���headǰ�滹��һ��*��˵��head��ָ���ָ�룬Ҳ���Ƕ���ָ��
{
	LinkList p1,p2;  //p1,p2��һ��ָ��
	int i,m=10;
	*head=p1=(LinkList)malloc(LEN);       //�����ڴ棬��Ϊ*head�൱��һ��ָ�룬��������ʹ��*head
	(*head)->next = NULL;                 //����*���������ȼ����ڳ�Ա������->,��������Ҫ������
	for(i=1;i<m;i++)
	{
		p2=(LinkList)malloc(LEN);  //β�巨��������
		p2->num=i;
		p1->next=p2;
		p1=p2;
	}
	p2->next=NULL;
	return OK;//ע��ʹ�ö���ָ��ʱ����ֱ���ں����ж�������в���������Ҫ����������˷���ֵ������һ��״̬
}
int mainTwo()
{
	LinkList L;
	int i=0;
	create(&L);           //ʵ�δ���ָ��ĵ�ַ��Ҳ���Ƕ���ָ�룬ֱ���ں�����ʵ���˶�����Ĳ�����������Ҫ������ָ��ȥ����
	while(L->next != NULL)
	{
		L =L->next;
		printf("%d",L->num);
	}
	return 0;
}


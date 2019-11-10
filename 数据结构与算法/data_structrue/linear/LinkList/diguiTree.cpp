/*
    用递归实现对没有头结点的链表实现删除给定数字
    输出最终结果
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef int ElemType;
const int MaxSize = 100;


typedef struct LNode{
     ElemType data;
     struct LNode *next;
}LNode,*LinkList;


//递归删除链表节点函数
void Del_X_3(LinkList *L,ElemType x) {
     LNode *p;
     if(*L == NULL) {
          return;
     }
     if((*L)->data == x) {
        p = *L;
        (*L) = (*L)->next;
        free(p);
        Del_X_3(L,x);
        //printf("if2--> %d\n",L->data);
     } else {
         Del_X_3(&((*L)->next),x);
         //printf("else--> %d\n",L->data);
     }

     //printf("--->%d\n",L->data);
}

int main(int argc,char **agrv) {
    int n;
    while(~scanf("%d",&n)) {
         int x;
         LinkList L = NULL;

         LNode *s, *r = L;
         for(int i = 0;i < n;++i) {

             scanf("%d",&x);
             s = (LNode *)malloc(sizeof(LNode));
             s->data = x;

             if(L == NULL) L = s;
             else r->next = s;
             r = s;
             //printf("-->%u\n",r);
         }
         r->next = NULL;

         printf("Please enter you want to delete number: ");
         scanf("%d",&x);

         LNode *p = L;
         while(p) {
             printf("%ox ",p);
             p = p->next;
         }
         puts("");

         Del_X_3(&L,x);

//         //test
         p = L;
         while(p) {
             printf("%ox %d\n",p,p->data);
             p = p->next;
         }
         puts("");

    }
    return 0;
}

typedef int ElemType;
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;



typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LiStack;

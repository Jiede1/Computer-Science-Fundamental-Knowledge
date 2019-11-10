// 实现顺序表
#include<stdio.h>
#include<stdlib.h>
#define initsize 100
typedef int Datatype;
typedef struct {
    Datatype *data;
    int n;
    int maxsize;
}seqlist;
void init(seqlist *L)
{
    L->data=(Datatype*)malloc(sizeof(Datatype)*initsize);
    L->n=0;
    L->maxsize=initsize;
}
void creat(seqlist *L,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&L->data[i]);
    }
    L->n=n;
}
int Findmid(seqlist *L,seqlist *H )
{
    int mid1,mid2,left1=0,left2=0,right1=(L->n)-1,right2=(H->n)-1;

    while(left1!=right1||left2!=right2)
    {   mid1=(left1+right1)/2;
        mid2=(left2+right2)/2;
        if(L->data[mid1]==H->data[mid2])//如果两个序列中位数相同，那么就是整个序列的中位数
        {return L->data[mid1];
            break;}
        if(L->data[mid1]<H->data[mid2])//当
        {
            if((left1+right1)%2==0)//如果每个序列有奇数个元素
            {
                left1=mid1;//去掉序列1中位数之前的元素
                right2=mid2;//去掉序列二中位数之后的元素
            }
            else
            {
                left1=mid1+1;//去掉序列1包括中位数以及之前的元素
                right2=mid2;
            }

        }
        else
        {
            if((left2+right2)%2==0)
            {
                left2=mid2;
                right1=mid1;
            }
            else
            {
                left2=mid2+1;//去掉序列二中位数及之前的元素
                right1=mid1;
            }
        }

    }
    return L->data[left1]<H->data[left2]?L->data[left1]:H->data[left2];//两个表都只剩一个元素时，较小的是中位数
}
void show(seqlist L)
{
    for(int i=0;i<L.n;i++)
        {if(i!=L.n-1)
        printf("%d ",L.data[i]);
        else
            printf("%d\n",L.data[i]);
        }

}
int main11()
{   int n,j,k;
    seqlist L;
    seqlist H;
    seqlist M;
    init(&L);
    init(&H);
    init(&M);
    printf("请输出顺序串1的长度");
    scanf("%d",&n);
    printf("请输入初始值：");
    creat(&L,n);
    printf("你创建的顺序表1为：\n");
    show(L);
    printf("请输出顺序串2的长度");
    scanf("%d",&j);
    printf("请输入初始值：");
    creat(&H,j);
    printf("你创建的顺序表2为：\n");
    show(H);
    int h=Findmid(&L,&H);
    printf("中位数是：");
    printf("%d",h);
    system("pause");

}


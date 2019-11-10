// ʵ��˳���
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
        if(L->data[mid1]==H->data[mid2])//�������������λ����ͬ����ô�����������е���λ��
        {return L->data[mid1];
            break;}
        if(L->data[mid1]<H->data[mid2])//��
        {
            if((left1+right1)%2==0)//���ÿ��������������Ԫ��
            {
                left1=mid1;//ȥ������1��λ��֮ǰ��Ԫ��
                right2=mid2;//ȥ�����ж���λ��֮���Ԫ��
            }
            else
            {
                left1=mid1+1;//ȥ������1������λ���Լ�֮ǰ��Ԫ��
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
                left2=mid2+1;//ȥ�����ж���λ����֮ǰ��Ԫ��
                right1=mid1;
            }
        }

    }
    return L->data[left1]<H->data[left2]?L->data[left1]:H->data[left2];//������ֻʣһ��Ԫ��ʱ����С������λ��
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
    printf("�����˳��1�ĳ���");
    scanf("%d",&n);
    printf("�������ʼֵ��");
    creat(&L,n);
    printf("�㴴����˳���1Ϊ��\n");
    show(L);
    printf("�����˳��2�ĳ���");
    scanf("%d",&j);
    printf("�������ʼֵ��");
    creat(&H,j);
    printf("�㴴����˳���2Ϊ��\n");
    show(H);
    int h=Findmid(&L,&H);
    printf("��λ���ǣ�");
    printf("%d",h);
    system("pause");

}


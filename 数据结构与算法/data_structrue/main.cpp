#include <iostream>

using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

int *test(int *b)  //b�����Ǿ�̬�������������Ҳ�����Ƕ�̬������׵�ַ
{
   for(int i=0;i<5;i++) //�������������Ԫ��
     cout<<*(b+i)<<" ";
   cout<<endl;
   int *c=new int[5];  //��̬����һ������
   //int c[5];

   //������Ӵ���б���ֻ�Ϊint c[5];���������е���test�޷��õ�c����
   for(int i=0;i<5;i++)    //������ĸ���ֵ���ڴ�����������ֵ��5
     *(c+i)=*(b+i)+5;
    cout<<c<<endl;
   return c;          //�����´����Ķ�̬������׵�ַ
}
int mainq()
{
  int *b=new int[5];  //������̬����b
  for(int i=0;i<5;i++)//��ֵ
    *(b+i)=i+1;

  //�Ӵ���б����Ҳ���Ի�Ϊint b[5]={0,1,2,3,4};��Ҳ�����Ǿ�̬����
  int *c=test(b);     //��b��Ϊ����������test����������ֵ����c
    cout<<c<<endl;
  for(int i=0;i<5;i++)    //���test���ص�����ĸ���
     cout<<*(c+i)<<" ";
  cout<<endl;
  delete c;
  //cout<<c<<endl;
   for(int i=0;i<5;i++)    //���test���ص�����ĸ���
     cout<<*(c+i)<<" ";
  return 0;
}

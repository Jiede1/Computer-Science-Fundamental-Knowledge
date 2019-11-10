#include <iostream>

using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

int *test(int *b)  //b可以是静态数组的数组名，也可以是动态数组的首地址
{
   for(int i=0;i<5;i++) //输出传入的数组各元素
     cout<<*(b+i)<<" ";
   cout<<endl;
   int *c=new int[5];  //动态创建一个数组
   //int c[5];

   //如果将加粗倾斜部分换为int c[5];则主函数中调用test无法得到c数组
   for(int i=0;i<5;i++)    //新数组的各项值等于传入的数组各项值加5
     *(c+i)=*(b+i)+5;
    cout<<c<<endl;
   return c;          //返回新创建的动态数组的首地址
}
int mainq()
{
  int *b=new int[5];  //创建动态数组b
  for(int i=0;i<5;i++)//赋值
    *(b+i)=i+1;

  //加粗倾斜部分也可以换为int b[5]={0,1,2,3,4};即也可以是静态数组
  int *c=test(b);     //将b作为参数，调用test函数，返回值赋给c
    cout<<c<<endl;
  for(int i=0;i<5;i++)    //输出test返回的数组的各项
     cout<<*(c+i)<<" ";
  cout<<endl;
  delete c;
  //cout<<c<<endl;
   for(int i=0;i<5;i++)    //输出test返回的数组的各项
     cout<<*(c+i)<<" ";
  return 0;
}

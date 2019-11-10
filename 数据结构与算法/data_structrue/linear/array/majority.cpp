// 实现主元素寻找

#include<stdlib.h>
#include<stdio.h>
#include <iostream>
using namespace std;


int Majority ( int A[ ], int n )
{
    int i, c, count=1;
    c = A[0];
    for ( i=1; i<n; i++ )
        if ( A[i] == c )
            count++;
        else
            if ( count > 0)
                count--;
            if(count <= 0)
            {   c = A[i];
                count = 1;
            }
    if ( count>0 )
        for ( i=count=0; i<n; i++ )
            if ( A[i] == c )
                count++;
    if ( count> n/2 )
        return c; //确认候选主元素
     else
        return -1; //不存在主元素
}
int main1(){
    int a[] = {3,3,4,5,2,3,4,5,4,3,3,3,3,3,3,3,3,3,3};
    int result = Majority(a,sizeof(a)/sizeof(a[0]));
    cout<<result;

}

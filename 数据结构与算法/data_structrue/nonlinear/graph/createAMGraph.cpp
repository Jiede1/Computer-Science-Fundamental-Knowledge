/*
邻接多重表存储图
*/
#include<stdlib.h>
#include<cstdio>
#include<iostream>
using namespace std;


#define MAX_VERTEX_NUM 20                   //图中顶点的最大个数
#define InfoType int                        //边含有的信息域的数据类型
#define VertexType int                      //图顶点的数据类型
typedef enum {unvisited,visited}VisitIf;    //边标志域
typedef struct EBox{
    VisitIf mark;                           //标志域
    int ivex,jvex;                          //边两边顶点在数组中的位置下标
    struct EBox * ilink,*jlink;             //分别指向与ivex、jvex相关的下一个边
    InfoType *info;                         //边包含的其它的信息域的指针
}EBox;
typedef struct VexBox{
    VertexType data;                        //顶点数据域
    EBox * firstedge;                       //顶点相关的第一条边的指针域
}VexBox;
typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];//存储图中顶点的数组
    int vexnum,degenum;//记录途中顶点个数和边个数的变量
}AMLGraph;

int LocateVex(AMLGraph *G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) {
        if (G->adjmulist[i].data==v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回 -1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

void createAMLGraph(AMLGraph* G){
    //输入有向图的顶点数和弧数
    cout<<"输入有向图的顶点数和弧数,逗号隔开:"<<endl;
    scanf("%d,%d",&(G->vexnum),&(G->degenum));
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (int i=0; i<G->vexnum; i++) {
        cout<<"输入每个顶点的数据:"<<endl;
        scanf("%d",&(G->adjmulist[i].data));
        G->adjmulist[i].firstedge=NULL;
    }
    //构建邻接多重表
    for (int k=0;k<G->degenum; k++) {
        int v1,v2;
        cout<<"输入边的数据信息,逗号隔开："<<endl;
        scanf("%d,%d",&v1,&v2);
        //确定v1、v2在数组中的位置下标
        int i=LocateVex(G, v1);
        int j=LocateVex(G, v2);
        //建立弧的结点
        EBox * p=(EBox*)malloc(sizeof(EBox));
        p->ivex=i;
        p->jvex=j;
        p->mark=unvisited;
        //采用头插法插入新的p结点
        p->ilink=G->adjmulist[i].firstedge;
        p->jlink=G->adjmulist[j].firstedge;
        G->adjmulist[i].firstedge=p;
        G->adjmulist[j].firstedge=p;
    }
}
int main(void)
{
    cout<<"建图"<<endl;
    AMLGraph AML;
    createAMLGraph(&AML);

    return 0;
}

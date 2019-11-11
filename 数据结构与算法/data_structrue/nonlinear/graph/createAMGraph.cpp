/*
�ڽӶ��ر�洢ͼ
*/
#include<stdlib.h>
#include<cstdio>
#include<iostream>
using namespace std;


#define MAX_VERTEX_NUM 20                   //ͼ�ж����������
#define InfoType int                        //�ߺ��е���Ϣ�����������
#define VertexType int                      //ͼ�������������
typedef enum {unvisited,visited}VisitIf;    //�߱�־��
typedef struct EBox{
    VisitIf mark;                           //��־��
    int ivex,jvex;                          //�����߶����������е�λ���±�
    struct EBox * ilink,*jlink;             //�ֱ�ָ����ivex��jvex��ص���һ����
    InfoType *info;                         //�߰�������������Ϣ���ָ��
}EBox;
typedef struct VexBox{
    VertexType data;                        //����������
    EBox * firstedge;                       //������صĵ�һ���ߵ�ָ����
}VexBox;
typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];//�洢ͼ�ж��������
    int vexnum,degenum;//��¼;�ж�������ͱ߸����ı���
}AMLGraph;

int LocateVex(AMLGraph *G,VertexType v){
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G->vexnum; i++) {
        if (G->adjmulist[i].data==v) {
            break;
        }
    }
    //����Ҳ����������ʾ��䣬���� -1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

void createAMLGraph(AMLGraph* G){
    //��������ͼ�Ķ������ͻ���
    cout<<"��������ͼ�Ķ������ͻ���,���Ÿ���:"<<endl;
    scanf("%d,%d",&(G->vexnum),&(G->degenum));
    //ʹ��һά����洢�������ݣ���ʼ��ָ����ΪNULL
    for (int i=0; i<G->vexnum; i++) {
        cout<<"����ÿ�����������:"<<endl;
        scanf("%d",&(G->adjmulist[i].data));
        G->adjmulist[i].firstedge=NULL;
    }
    //�����ڽӶ��ر�
    for (int k=0;k<G->degenum; k++) {
        int v1,v2;
        cout<<"����ߵ�������Ϣ,���Ÿ�����"<<endl;
        scanf("%d,%d",&v1,&v2);
        //ȷ��v1��v2�������е�λ���±�
        int i=LocateVex(G, v1);
        int j=LocateVex(G, v2);
        //�������Ľ��
        EBox * p=(EBox*)malloc(sizeof(EBox));
        p->ivex=i;
        p->jvex=j;
        p->mark=unvisited;
        //����ͷ�巨�����µ�p���
        p->ilink=G->adjmulist[i].firstedge;
        p->jlink=G->adjmulist[j].firstedge;
        G->adjmulist[i].firstedge=p;
        G->adjmulist[j].firstedge=p;
    }
}
int main(void)
{
    cout<<"��ͼ"<<endl;
    AMLGraph AML;
    createAMLGraph(&AML);

    return 0;
}

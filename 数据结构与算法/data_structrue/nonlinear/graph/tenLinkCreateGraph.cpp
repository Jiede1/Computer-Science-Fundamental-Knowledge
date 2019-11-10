/*
ʮ������洢ͼ
*/
#include<stdlib.h>
#include<cstdio>
#include<iostream>
using namespace std;

#define  MAX_VERTEX_NUM 20
#define  InfoType int//ͼ�л�������Ϣ����������
#define  VertexType int
typedef struct ArcBox{
    int tailvex,headvex;//��β����ͷ��Ӧ�����������е�λ���±�
    struct ArcBox *hlik,*tlink;//�ֱ�ָ��ͷ��ͬ�ͻ�β��ͬ����һ����
    InfoType *info;//�洢�������Ϣ��ָ��
}ArcBox;
typedef struct VexNode{
    VertexType data;//�����������
    ArcBox *firstin,*firstout;//ָ���Ըö���Ϊ��ͷ�ͻ�β�������׸����
}VexNode;

typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];//�洢�����һά����
    int vexnum,arcnum;//��¼ͼ�Ķ������ͻ���
}OLGraph;

int LocateVex(OLGraph *G,VertexType v){
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G->vexnum; i++) {
        if (G->xlist[i].data==v) {
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
//����ʮ��������
void CreateDG(OLGraph *G){
    //��������ͼ�Ķ������ͻ���
    cout<<"��������ͼ�Ķ������ͻ���,���Ÿ���:"<<endl;
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //ʹ��һά����洢�������ݣ���ʼ��ָ����ΪNULL
    for (int i=0; i<G->vexnum; i++) {
        cout<<"����ÿ�����������:"<<endl;
        scanf("%d",&(G->xlist[i].data));
        G->xlist[i].firstin=NULL;
        G->xlist[i].firstout=NULL;
    }
    //����ʮ������
    for (int k=0;k<G->arcnum; k++) {
        int v1,v2;
        cout<<"����ߵ�������Ϣ,���Ÿ�����"<<endl;
        scanf("%d,%d",&v1,&v2);
        //ȷ��v1��v2�������е�λ���±�
        int i=LocateVex(G, v1);
        int j=LocateVex(G, v2);
        //�������Ľ��
        ArcBox * p=(ArcBox*)malloc(sizeof(ArcBox));
        p->tailvex=i;
        p->headvex=j;
        //����ͷ�巨�����µ�p���
        p->hlik=G->xlist[j].firstin;
        p->tlink=G->xlist[i].firstout;
        G->xlist[j].firstin=G->xlist[i].firstout=p;
    }
}

int main(void)
{
    cout<<"��ͼ"<<endl;
    OLGraph OL;
    CreateDG(&OL);

    return 0;
}

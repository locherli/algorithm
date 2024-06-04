#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

typedef char VerTexType;              		//���趥�����������Ϊ�ַ���
typedef int ArcType;
#define MVNum 100                       	//��󶥵���
#define MaxInt 32767                    	//��ʾ����ֵ������

//----------------ͼ���ڽӾ���---------------------
typedef struct
{
	VerTexType vexs[MVNum];            		//�����
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ���
	int vexnum, arcnum;                		//ͼ�ĵ�ǰ�����ͱ���
} AMGraph;

//����edge�Ķ���,�����洢ͼG�����б�
struct edge
{
	int Head;						//�ߵ�ʼ��
	int Tail;						//�ߵ��յ�
	ArcType lowcost;			   //���ϵ�Ȩֵ
};


//�����洢��С�������ıߣ����㣨u,v)
struct treeEdge
{
	int u, v;
};

int Vexset[MVNum];							//��������Vexset�Ķ���,��¼�����������ڵ���ͨ����
void CreateUDN(AMGraph& G);//��������ͼ���ڽӾ����ʾ
void Sort(struct edge edges[], int edgesNum);  //��edges�����������
void GraphToEdges(AMGraph& G, struct edge edges[]);  //��ͼG�����еıߴ���edges����
void PrintMST(AMGraph& G, struct treeEdge tree[]);//�����С������


void Kruskal(struct edge edges[], int vexsNum, int edgesNum, struct treeEdge tree[]);
//edges�洢ͼG�ıߣ����Ѿ���С�����ź���vexsNum��ʾͼG�Ķ������, edgesNum ��ʾͼG�ı���, ����kruskal�㷨���ͼG����С������,����С�������ıߴ���tree����



void Kruskal(struct edge edges[], int vexsNum, int edgesNum, struct treeEdge tree[])
//edges�洢ͼG�ıߣ����Ѿ���С�����ź���vexsNum��ʾͼG�Ķ������, edgesNum ��ʾͼG�ı���, ����kruskal�㷨���ͼG����С������,����С�������ıߴ���tree����
{
	int mark[MVNum] = { 0 };
	for (int i = 0; i < vexsNum; i++)
		mark[i] = i;	//each node belongs to itself

	int cnt = 0;	//iterator of tree[]
	for (int i = 0; i < edgesNum; i++)
	{
		//check if the head and tail comes from the different set
		if (mark[edges[i].Head] == mark[edges[i].Tail])
			continue;
		//merge head the tail
		int v1 = mark[edges[i].Head];
		int v2 = mark[edges[i].Tail];

		for (int j = 0; j < vexsNum; j++){
			if (mark[j] == v2)
				mark[j] = v1;
		}

		tree[cnt].u = edges[i].Head;
		tree[cnt].v = edges[i].Tail;
		cnt++;

	}

}//MiniSpanTree_Kruskal

//====================================================
int main()
{
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);   //redirector
	cin.tie(0);
	cout.tie(0);

	struct treeEdge  minTree[MVNum];
	struct edge Edges[(MVNum * (MVNum - 1)) / 2]; //�����(MVNum * (MVNum - 1)) / 2����
	AMGraph G;
	CreateUDN(G);
	GraphToEdges(G, Edges);  // ��ͼG�еıߴ���Edges����
	Sort(Edges, G.arcnum);  //��Edges�����������
	Kruskal(Edges, G.vexnum, G.arcnum, minTree);  //����Kruskal�㷨��MST
	PrintMST(G, minTree);
	return 0;
}///main

// ����ͼ���ڽӾ���
void CreateUDN(AMGraph& G) {
	cin >> G.vexnum >> G.arcnum;    //input

	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
	}
	// ��ʼ���ڽӾ���
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	// ����ߵ���Ϣ
	int v1, v2;
	int w;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2 >> w;
		G.arcs[v1][v2] = G.arcs[v2][v1] = w;
	}
}
void GraphToEdges(AMGraph& G, struct edge edges[])  //��ͼG�����еıߴ���edges����
{
	int i, j, k = 0;
	for (i = 0; i < G.vexnum - 1; ++i)
		for (j = i + 1; j < G.vexnum; ++j)
			if (G.arcs[i][j] != MaxInt)
			{
				edges[k].lowcost = G.arcs[i][j];
				edges[k].Head = i;
				edges[k].Tail = j;
				k++;
			}
}
//----------ð������-------------------
void Sort(struct edge edges[], int edgesNum)
{
	int m = edgesNum - 1;
	int flag = 1;
	struct edge temp_edge;
	while ((m > 0) && flag == 1)
	{
		flag = 0;
		for (int j = 0; j < m; j++)
		{
			if (edges[j].lowcost > edges[j + 1].lowcost)
			{
				flag = 1;
				temp_edge = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp_edge;
			}//if
		}//for
		--m;
	}//while
}//Sort
void PrintMST(AMGraph& G, struct treeEdge tree[])//�����С������
{
	int i, u0, v0;
	cout << "the MST is:\n";
	for (i = 0; i < G.vexnum - 1; i++)
	{
		u0 = tree[i].u;
		v0 = tree[i].v;
		cout << "(" << G.vexs[u0] << " , " << G.vexs[v0] << ")��" << G.arcs[u0][v0] << endl;        //�����ǰ����С��(u0, v0)
	}
	cout << endl;
}
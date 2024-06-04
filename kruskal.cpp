#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;
#define MVNum 100                       	//最大顶点数
#define MaxInt 32767                    	//表示极大值，即∞

//----------------图的邻接矩阵---------------------
typedef struct
{
	VerTexType vexs[MVNum];            		//顶点表
	ArcType arcs[MVNum][MVNum];      		//邻接矩阵
	int vexnum, arcnum;                		//图的当前点数和边数
} AMGraph;

//辅助edge的定义,用来存储图G的所有边
struct edge
{
	int Head;						//边的始点
	int Tail;						//边的终点
	ArcType lowcost;			   //边上的权值
};


//用来存储最小生成树的边，顶点（u,v)
struct treeEdge
{
	int u, v;
};

int Vexset[MVNum];							//辅助数组Vexset的定义,记录各个顶点所在的连通分量
void CreateUDN(AMGraph& G);//创建无向图的邻接矩阵表示
void Sort(struct edge edges[], int edgesNum);  //对edges数组进行排序
void GraphToEdges(AMGraph& G, struct edge edges[]);  //将图G中所有的边存入edges数组
void PrintMST(AMGraph& G, struct treeEdge tree[]);//输出最小生成树


void Kruskal(struct edge edges[], int vexsNum, int edgesNum, struct treeEdge tree[]);
//edges存储图G的边，且已经从小到大排好序，vexsNum表示图G的顶点个数, edgesNum 表示图G的边数, 利用kruskal算法求解图G的最小生成树,将最小生成树的边存入tree数组



void Kruskal(struct edge edges[], int vexsNum, int edgesNum, struct treeEdge tree[])
//edges存储图G的边，且已经从小到大排好序，vexsNum表示图G的顶点个数, edgesNum 表示图G的边数, 利用kruskal算法求解图G的最小生成树,将最小生成树的边存入tree数组
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
	struct edge Edges[(MVNum * (MVNum - 1)) / 2]; //最多有(MVNum * (MVNum - 1)) / 2条边
	AMGraph G;
	CreateUDN(G);
	GraphToEdges(G, Edges);  // 将图G中的边存入Edges数组
	Sort(Edges, G.arcnum);  //对Edges数组进行排序
	Kruskal(Edges, G.vexnum, G.arcnum, minTree);  //采用Kruskal算法求MST
	PrintMST(G, minTree);
	return 0;
}///main

// 构造图的邻接矩阵
void CreateUDN(AMGraph& G) {
	cin >> G.vexnum >> G.arcnum;    //input

	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
	}
	// 初始化邻接矩阵
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	// 输入边的信息
	int v1, v2;
	int w;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2 >> w;
		G.arcs[v1][v2] = G.arcs[v2][v1] = w;
	}
}
void GraphToEdges(AMGraph& G, struct edge edges[])  //将图G中所有的边存入edges数组
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
//----------冒泡排序-------------------
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
void PrintMST(AMGraph& G, struct treeEdge tree[])//输出最小生成树
{
	int i, u0, v0;
	cout << "the MST is:\n";
	for (i = 0; i < G.vexnum - 1; i++)
	{
		u0 = tree[i].u;
		v0 = tree[i].v;
		cout << "(" << G.vexs[u0] << " , " << G.vexs[v0] << ")：" << G.arcs[u0][v0] << endl;        //输出当前的最小边(u0, v0)
	}
	cout << endl;
}
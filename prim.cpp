#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#define rep(i,a,n) for (int i=a;i<=n;i++)//iΪѭ��������aΪ��ʼֵ��nΪ����ֵ������
#define per(i,a,n) for (int i=a;i>=n;i--)//iΪѭ�������� aΪ��ʼֵ��nΪ����ֵ���ݼ���
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair

using namespace std;

const int inf = 0x3f3f3f3f;//�����
const int maxn = 1e3;//���ֵ��
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>  pll;
typedef pair<int, int> pii;
//*******************************�ָ��ߣ�����Ϊ�Զ������ģ��***************************************//

int n, m;//ͼ�Ĵ�С�ͱ�����
int graph[maxn][maxn];//ͼ
int lowcost[maxn], closest[maxn];//lowcost[i]��ʾi�����뼯������ľ��룬closest[i]��ʾi��֮�����ߵĶ�����š�
int sum;//������С��������Ȩֵ�ܺ͡�
void Prim(int s) {
	//��ʼ����������ȡ������Ϣ��
	rep(i, 1, n) {
		if (i == s)
			lowcost[i] = 0;
		else
			lowcost[i] = graph[s][i];
		closest[i] = s;
	}
	int minn, pos;//���뼯������ıߣ�pos����õ���ձ��±ꡣ
	sum = 0;
	rep(i, 1, n) {
		minn = inf;
		rep(j, 1, n) {
			//�ҳ�������С��������������ıߡ�
			if (lowcost[j] != 0 && lowcost[j] < minn) {
				minn = lowcost[j];
				pos = j;
			}
		}
		if (minn == inf)break;//˵��û���ҵ���
		sum += minn;//������С��������Ȩֵ֮�͡�
		lowcost[pos] = 0;//����lowcost
		rep(j, 1, n) {
			//���ڵ㼯���м������µĵ㣬����Ҫȥ���¡�
			if (lowcost[j] != 0 && graph[pos][j] < lowcost[j]) {
				lowcost[j] = graph[pos][j];
				closest[j] = pos;//�ı��붥��j�����Ķ�����š�
			}
		}
	}
	cout << sum << endl;//closest�����������Ҫ����С��������������ľ��Ǳߡ�
}
void print(int s) {
	//��ӡ��С��������
	int temp;
	rep(i, 1, n) {
		//����s��Ȼ���㣬�ʳ�ȥ���Ϊn-1���ߡ�
		if (i != s) {
			temp = closest[i];
			cout << temp << "->" << i << "��ȨֵΪ��" << graph[temp][i] << endl;
		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);//�ύ��ʱ��Ҫע�͵�

	ios::sync_with_stdio(false);
	cin.tie(0);
	 cout.tie(0);
	while (cin >> n >> m) {
		memset(graph, inf, sizeof(graph));//��ʼ����
		int u, v, w;//��ʱ������
		rep(i, 1, m) {
			cin >> u >> v >> w;
			//��������ۣ�������������ͼΪ����
			graph[u][v] = graph[v][u] = w;
		}
		//��ȡ����㣬������Ĭ��ȡ1.
		Prim(1);
		print(1);//��ӡ��С��������
	}
	return 0;
}




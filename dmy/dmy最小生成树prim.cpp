#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, q;
int dist[5005],pre[5005], c[5005];
bool b[5005];
struct Node {
	int y,v;
	Node(int _y, int _v) {y=_y; v=_v;};
};
vector<Node> edges[5005];
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		//无向图 
		edges[x].push_back(Node(y,z));
		edges[y].push_back(Node(x,z));
	}
	//Prim算法： 连通图，直接n轮即可 
	memset(dist, 127, sizeof(dist));
	memset(b, 0, sizeof(b));
	dist[1]=0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		//找dist里最小的点
		int idx=-1;
		int temp=1<<30;
		for(int i=1; i<=n; i++) {
			if(!b[i]&&dist[i]<1<<30&&temp>dist[i]) {
				idx=i;
				temp=dist[i];
			}
		}
		//从找到的点扩展 
		b[idx]=true;
		//当前边加入，是一条怎样的边？终点是idx，但不知道起点 
		ans+=dist[idx];
		//不需要判断b[idx]，因为n轮就会出去，而且前面找最小值的代码已经剔除C里的点，所以C里dist值是否变化没关系 
		for(auto e:edges[idx]) {
			int y=e.y, v=e.v;
			dist[y]=min(dist[y],v);
		}
	}
	cout<<ans; 
	return 0;
}



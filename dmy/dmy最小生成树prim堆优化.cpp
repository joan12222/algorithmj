#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
int dist[5005],pre[5005], c[5005];
bool b[5005];
struct Node {
	int y,v;
	Node(int _y, int _v) {y=_y; v=_v;};
};
vector<Node> edges[5005];
priority_queue<pair<int, int> > q;//dist, idx 

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
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		//找dist里最小的点
		int idx=q.top().second;
		q.pop();
		if(b[idx]) continue;
		//从找到的点扩展 
		b[idx]=true;
		//当前边加入，是一条怎样的边？终点是idx，但不知道起点 
		ans+=dist[idx];
		for(auto e:edges[idx]) {
			int y=e.y, v=e.v;
			//需要判断b[y]，否则C连的点会被再加入队列
			//思考下和dijstra堆优化的区别 
			if(!b[y]) {
				dist[y]=min(dist[y],v);
				q.push(make_pair(-dist[y],y));
			}
		}
	}
	cout<<ans; 
	return 0;
}



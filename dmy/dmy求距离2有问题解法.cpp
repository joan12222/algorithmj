#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, int> > to[20005];
int dist[20005]; 
bool b[20005];
int u,v; 

void bfs(int x) {
	queue<int> q;
	q.push(x);
	dist[x]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		//第一个点的第一轮：把i距离的点放入 i i i 
		//第二个点的第一轮：i,i,i+1,i+1,i,i <-此时队列不单调，这种解法是有问题的 
		//dijkstra算法是找到距离最小的点后，用它去更新出边点的距离，下一次再从距离里找最小的 
		for(auto y:to[now]) {
			if(!b[y.first])
				if(!y.second) {
					dist[y.first]=dist[now];
					q.push(y.first);
					b[y.first]=true; 
				}
		}
		//终点已经走到，后面不需要再走了 
		if(dist[v]!=-1) break;
		//第一个点的第二轮：把i+1距离的点放入 i,i,i,i+1,i+1 
		for(auto y:to[now]) {
			if(!b[y.first])
				if(y.second) {
					dist[y.first]=dist[now]+y.second;
					q.push(y.first);
					b[y.first]=true; 
				}
		}
	}
	cout<<dist[v];
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		to[x].push_back(make_pair(y,z));
		to[y].push_back(make_pair(x,z));
	}
	for(int i=1; i<=k; i++) {
		cin>>u>>v;
		memset(dist,0xff,sizeof(dist)); //dist初始为-1 
		memset(b, 0, sizeof(b));
		bfs(u);
	}
	return 0;
}



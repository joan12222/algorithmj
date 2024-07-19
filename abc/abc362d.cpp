#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, int> > edges[200005];
ll a[200005];
ll dist[200005];
bool vis[200005];
int n,m;
priority_queue<pair<int, int> > q; //dist, index

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		dist[i]=1e18;
	}

	for(int i=1;i<=m;i++) {
		int x,y,w;
		cin>>x>>y>>w;
		edges[x].push_back(make_pair(y,w));
		edges[y].push_back(make_pair(x,w));
	}
//	vis[1]=true;
	dist[1]=a[1];
	q.push(make_pair(-dist[1], 1));
	while(!q.empty()) {
		int x=q.top().second; //vertex
		q.pop();
		if(vis[x]) continue;
		for(auto y:edges[x]) {
			if(vis[y.first]) continue;
			dist[y.first]=min(dist[y.first], dist[x]+y.second+a[y.first]);
//			vis[y.first]=true;
			q.push(make_pair(-dist[y.first], y.first));
		}
		vis[x]=true;	
	}
	for(int i=2; i<=n; i++) {
		cout<<dist[i]<<" ";
	}
	return 0;
}


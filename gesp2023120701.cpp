#include<bits/stdc++.h>
using namespace std;
#define ll long long
int v[100005];
int dist[100005];
vector<int> edges[100005];
int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<m;i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
	}
	memset(dist, 255, sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()) {
		int x=q.front();
		if(x==t) {
			cout<<dist[x]-v[s]+v[t];
			return 0;
		}
		q.pop();
		for(auto y:edges[x]) {
			if(dist[y]==-1) {
				dist[y]=dist[x]+1;
				q.push(y);
			}
		}
	}
	cout<<"No Solution";
	return 0;
}

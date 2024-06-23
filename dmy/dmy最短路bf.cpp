#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, q;
int dist[5005],pre[5005], c[5005];
struct Node {
	int y,v;
	Node(int _y, int _v) {y=_y; v=_v;};
};
vector<Node> edges[5005];
int main(){
	cin>>n>>m>>q;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		edges[x].push_back(Node(y,z));
	}
	//BFÀ„∑® 
	for(int k=1; k<=q; k++) {
		int s1, s2;
		cin>>s1>>s2;
		memset(dist, 127, sizeof(dist));
		memset(pre, 0, sizeof(pre));
		dist[s1]=0;
		for(int i=1; i<=n-1; i++) {
			bool ok=true;
			for(auto e:edges[i]) {
				int y=e.y, v=e.v;
				if(dist[i]<1<<30&&dist[i]+v<dist[y]) {
					dist[y]=dist[i]+v;
					pre[y]=i;
					ok=false;
				}
			}
			if(ok) {
				break;
			}
		}
		if(dist[s2]<1<<30) {
			cout<<dist[s2]<<endl;
			int l=0;
			for(int i=s2;i!=s1;i=pre[i]) {
				c[++l]=i;
			}
			c[++l]=s1;
			for(int i=l;i;i--) {
				cout<<c[i]<<" ";
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}



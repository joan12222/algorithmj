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
	cin>>n>>m>>q;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		edges[x].push_back(Node(y,z));
	}
	//Dijkstra算法 
	for(int k=1; k<=q; k++) {
		int s, t;
		cin>>s>>t;
		memset(dist, 127, sizeof(dist));
		memset(b, 0, sizeof(b));
		dist[s]=0;
		for(int i=1; i<=n; i++) {
			//找dist里最小的点
			int idx=-1;
			for(int i=1; i<=n; i++) {
				int temp=1<<30; //有问题？应该放在外面 
				if(!b[i]&&temp>dist[i]) {
					idx=i;
					temp=dist[i];
				}
			}
			if(idx==t||idx==-1) break;
			//从找到的点扩展 
			b[idx]=true;
			for(auto e:edges[idx]) {
				int y=e.y, v=e.v;
				if(dist[idx]<1<<30&&dist[idx]+v<dist[y]) {
					dist[y]=dist[idx]+v;
					pre[y]=idx;
				}
			}
		}
		if(dist[t]<1<<30) {
			cout<<dist[t]<<endl;
			int l=0;
			for(int i=t;i!=s;i=pre[i]) {
				c[++l]=i;
			}
			c[++l]=s;
			for(int i=l;i;i--) {
				cout<<c[i]<<" ";
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}



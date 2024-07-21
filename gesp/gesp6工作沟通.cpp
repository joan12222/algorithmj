#include<bits/stdc++.h>
using namespace std;
int n, query, m;
int a[305];
int b[305];
int fa[305];
int d[305];
queue<int> q;
vector<int> edges[305];
void bfs() {
	q.push(0);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(auto y:edges[x]) {
			d[y]=d[x]+1;
			q.push(y); 
		}
	}
}
int lca(int v1, int v2) {
//	cout<<v1<<" "<<v2<<" ";
	if(d[v1]<d[v2]) {
		swap(v1, v2);
	}
	while(d[v1]>d[v2]) v1=fa[v1];
	if(v1==v2) return v1;
	while(fa[v1]!=fa[v2]) {
		v1=fa[v1];
		v2=fa[v2];
	}
//	cout<<fa[v1]<<endl;
	return fa[v1];
} 
int main(){
	cin>>n;
	memset(fa, 255, sizeof(fa));
	memset(d, 255, sizeof(d));
	fa[0]=0;
	d[0]=0;
	for(int i=1;i<n;i++){
		cin>>a[i];
		fa[i]=a[i];
		//edge: a[i]->i
		edges[a[i]].push_back(i);
	}
	bfs();
	cin>>query;
	while(query--) {
		cin>>m;
		for(int i=1; i<=m; i++) {
			cin>>b[i];
		}
		int ans=b[1];
		for(int i=2; i<=m; i++) {
			ans=lca(ans, b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

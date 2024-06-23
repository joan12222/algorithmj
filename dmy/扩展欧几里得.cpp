#include<bits/stdc++.h>
using namespace std;
int n,m,k,vis[15],g[15][15];
bool flag=true;
bool check(){
	for(int i=1;i<=n;i++){
		if(vis[i]==0) return false;
	}
	return true;
}
void dfs(int i){
	vis[i]=1;
	for(int j=1;j<=n;j++){
		if(g[i][k]&&check()&&flag){
			cout<<"Yes";
			flag=false;
			break;
		}
		if(check()) break;
		if(g[i][j]&&vis[j]==0) dfs(j);
	}
	vis[i]=0;
}
int main(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		g[u][v]=1;
		g[v][u]=1;
	}
	cin>>k;
	dfs(k);
	if(flag) cout<<"No";
	return 0;
}

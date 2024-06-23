#include<bits/stdc++.h>
using namespace std; 
#define MAXN 100005
int a[9][9],b[9][9],c[9]; 
bool vis[9];
int n,m;

//可行性 
bool dfs(int x) {
	if(x==n+1) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(a[i][j]!=b[c[i]][c[j]])
					return false;
			} 
		}
		return true;
	}
	//枚举a图的x点是b图的i点：即c[x] 
	for(int i=1;i<=n;i++) {
		c[x]=i; 
		vis[i]=1;
		if(dfs(x+1)) return true; //表示找到第x+1点的映射 
		vis[i]=0;
	}
	return false; 
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(int i=1; i<=m; i++) {
		int x,y;
		cin>>x>>y;
		b[x][y]=b[y][x]=1;
	}
	cout<<dfs(1);
	return 0;
}

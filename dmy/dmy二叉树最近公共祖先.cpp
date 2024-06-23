#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int pre[MAXN];
int c1[MAXN], c2[MAXN];

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int x, y;
		cin>>x>>y;
		if(x) pre[x]=i;
		if(y) pre[y]=i;
	}
	int u,v;
	cin>>u>>v;
	int cnt1=0;
	//从叶子节点到根存储路径 
	while(u!=1) c1[++cnt1]=u,u=pre[u];
	c1[++cnt1]=1; 
	int cnt2=0;
	while(v!=1) c2[++cnt2]=v,v=pre[v];
	c2[++cnt2]=1;
	//从根往下比较，第一个最后一个相等的为LCA 
	int ans=0; 
	for(int i=cnt1,j=cnt2;i&&j;i--,j--) {
		if(c1[i]==c2[j]) ans=c1[i];
		else break;
	}
	cout<<ans<<endl;
	return 0;
}


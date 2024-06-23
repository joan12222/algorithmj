#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXM 10005
int head[MAXN]; //ÿ���ڵ�����ĵ�һ���ߵ��յ��Ȩ����ver,edge�����е�λ�� 
int nxt[MAXM]; //ģ��ָ�룬��ʾ����ͬ�ڵ��������һ������ver,edge�����е�λ�� 
int edge[MAXM]; 
int ver[MAXM]; //�ߵ����� 
int dist[MAXN]; 
int vis[MAXN];
int tot=0;
int n,m;

void addEdge(int x, int y, int z) {
	tot++;
	ver[tot]=y;
	edge[tot]=z;
	//�ڱ�ͷ������ 
	nxt[tot]=head[x]; 
	head[x]=tot;
}

int findMin() {
	int ans=1e9;
	int node=1;
	for(int i=1; i<=n; i++)	{
		if(ans>=dist[i]&&!vis[i]) {
			node=i;
			ans=dist[i];
		}
	}
	return node;
}

int main() {
	int x, y, z;
	memset(dist, 0x3f, sizeof(dist));
	dist[1]=0;
	vis[1]=1;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>x>>y>>z;
		addEdge(x, y, z);
	}
	for(int i=1; i<=n; i++) {
		x=findMin();
		for(int j=head[x];j;j=nxt[j]) {
			y=ver[j];
			z=edge[j];
			dist[y]=min(dist[y], dist[x]+z);
		}
		vis[i]=1;
	}
	if(dist[n]==0x3f3f3f3f) cout<<-1;
	else cout<<dist[n];
	return 0;
}

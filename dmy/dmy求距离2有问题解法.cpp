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
		//��һ����ĵ�һ�֣���i����ĵ���� i i i 
		//�ڶ�����ĵ�һ�֣�i,i,i+1,i+1,i,i <-��ʱ���в����������ֽⷨ��������� 
		//dijkstra�㷨���ҵ�������С�ĵ������ȥ���³��ߵ�ľ��룬��һ���ٴӾ���������С�� 
		for(auto y:to[now]) {
			if(!b[y.first])
				if(!y.second) {
					dist[y.first]=dist[now];
					q.push(y.first);
					b[y.first]=true; 
				}
		}
		//�յ��Ѿ��ߵ������治��Ҫ������ 
		if(dist[v]!=-1) break;
		//��һ����ĵڶ��֣���i+1����ĵ���� i,i,i,i+1,i+1 
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
		memset(dist,0xff,sizeof(dist)); //dist��ʼΪ-1 
		memset(b, 0, sizeof(b));
		bfs(u);
	}
	return 0;
}



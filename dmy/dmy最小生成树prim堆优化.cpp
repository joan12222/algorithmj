#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
int dist[5005],pre[5005], c[5005];
bool b[5005];
struct Node {
	int y,v;
	Node(int _y, int _v) {y=_y; v=_v;};
};
vector<Node> edges[5005];
priority_queue<pair<int, int> > q;//dist, idx 

int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		//����ͼ 
		edges[x].push_back(Node(y,z));
		edges[y].push_back(Node(x,z));
	}
	//Prim�㷨�� ��ͨͼ��ֱ��n�ּ��� 
	memset(dist, 127, sizeof(dist));
	memset(b, 0, sizeof(b));
	dist[1]=0;
	int ans=0;
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		//��dist����С�ĵ�
		int idx=q.top().second;
		q.pop();
		if(b[idx]) continue;
		//���ҵ��ĵ���չ 
		b[idx]=true;
		//��ǰ�߼��룬��һ�������ıߣ��յ���idx������֪����� 
		ans+=dist[idx];
		for(auto e:edges[idx]) {
			int y=e.y, v=e.v;
			//��Ҫ�ж�b[y]������C���ĵ�ᱻ�ټ������
			//˼���º�dijstra���Ż������� 
			if(!b[y]) {
				dist[y]=min(dist[y],v);
				q.push(make_pair(-dist[y],y));
			}
		}
	}
	cout<<ans; 
	return 0;
}



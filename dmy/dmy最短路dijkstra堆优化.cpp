#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, qq;
int dist[5005],pre[5005], c[5005];
bool b[5005];
priority_queue<pair<int, int> > q;
 
struct Node {
	int y,v;
	Node(int _y, int _v) {y=_y; v=_v;};
};
vector<Node> edges[5005];
int main(){
	cin>>n>>m>>qq;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		edges[x].push_back(Node(y,z));
	}
	//Dijkstra�㷨 
	for(int k=1; k<=qq; k++) {
		int s, t;
		cin>>s>>t;
		memset(dist, 127, sizeof(dist));
		memset(b, 0, sizeof(b));
		dist[s]=0;
		q.push({0,s}); 
		while(!q.empty()) {
			//��dist����С�ĵ�
			int idx = q.top().second;
			q.pop();
			if(b[idx]) continue;
			if(idx==t) break;
			b[idx]=true;
			for(auto e:edges[idx]) {
				int y=e.y, v=e.v;
				//����Ҫ�ж�b[idx]����Ϊ �Ѿ���C��ĵ�dist[idx]+v<dist[y]�������㣬���Բ��ᱻ���£�Ҳ���ᱻ�ٷŵ�queueLi  
				if(dist[idx]<1<<30&&dist[idx]+v<dist[y]) {
					dist[y]=dist[idx]+v;
					q.push({-dist[y], y});//����ɾ����֮ǰ��y���ڶ�����,���϶����ڶѶ� 
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



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
	for(int i=1; i<=n; i++) {
		//��dist����С�ĵ�
		int idx=-1;
		int temp=1<<30;
		for(int i=1; i<=n; i++) {
			if(!b[i]&&dist[i]<1<<30&&temp>dist[i]) {
				idx=i;
				temp=dist[i];
			}
		}
		//���ҵ��ĵ���չ 
		b[idx]=true;
		//��ǰ�߼��룬��һ�������ıߣ��յ���idx������֪����� 
		ans+=dist[idx];
		//����Ҫ�ж�b[idx]����Ϊn�־ͻ��ȥ������ǰ������Сֵ�Ĵ����Ѿ��޳�C��ĵ㣬����C��distֵ�Ƿ�仯û��ϵ 
		for(auto e:edges[idx]) {
			int y=e.y, v=e.v;
			dist[y]=min(dist[y],v);
		}
	}
	cout<<ans; 
	return 0;
}



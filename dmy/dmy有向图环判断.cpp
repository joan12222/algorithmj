#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> edges[10005];
int d[10005];
int q[10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
		d[y]++;
	}
	int front=1, rear=0;
	for(int i=1; i<=n; i++) {
		if(d[i]==0) {
			q[++rear]=i;
		}
	}
	while(front<=rear) {
		int x=q[front++];
		for(auto y:edges[x]) {
			if(--d[y]==0) {
				q[++rear]=y;
			}
		}		
	}
	if(rear==n) cout<<"No";
	else cout<<"Yes";
}



#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> edges[10005];
int d[10005];
priority_queue<int> q;
int ans[10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
		d[y]++;
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(d[i]==0) {
			q.push(-i);
		}
	}
	while(!q.empty()) {
		int x=-q.top();
		cout<<x<<" ";
		cnt++;
		q.pop();
		for(auto y:edges[x]) {
			if(--d[y]==0) {
				q.push(-y);
			}
		}		
	}
	return 0;
}



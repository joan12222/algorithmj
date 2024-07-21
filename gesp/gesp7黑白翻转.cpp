#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
vector<int> edges[100005];
int ans=0;
int n;
int h[100005];
void dfs(int x, int fa){
	for(auto y:edges[x]) {
		if(y!=fa) {
			dfs(y, x);
			if(a[y]==1) {
				h[x]=1;
			}
			if(a[x]==0&&h[x]==1) {
				ans++;
				a[x]=1;
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	dfs(1, 0);
	cout<<ans; 
	return 0;
}



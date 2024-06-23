#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int pre[MAXN];
vector<int> edges[MAXN]; 
int w[MAXN], ans[MAXN];

int solve(int x) {
	if(ans[x]) return ans[x];
	int tmp=w[x];
	for(auto y:edges[x]) {
		tmp+=solve(y);
	}
	ans[x]=tmp;  
	return tmp;
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int x, y;
		cin>>x>>y;
		if(x) {
			edges[i].push_back(x);
			pre[x]=i;
		}
		if(y) {
			edges[i].push_back(y);
			pre[y]=i;	
		}
	}
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	solve(1);
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";
	return 0;
}


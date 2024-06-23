#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> to[10];
bool b[20005];
int k;
int n, m;
void dfs(int x) {
	//为什么要这里设置？ 而不是下面？ 
	b[x]=true;
	for(auto y:to[x]) {
		if(!b[y]) {
			dfs(y);
//			b[y]=true;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(!b[i]) {
			dfs(i);
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}



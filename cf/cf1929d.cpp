#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
int q;
int n;
vector<int> edges[300005];
ll f[300005]; 
ll ans;
void dfs(int u, int fa) {
	f[u]=1;
	for(auto v:edges[u]) {
		if(v!=fa) {
			dfs(v,u);
			f[u]=f[u]*(f[v]+1)%MOD;
//			ans=(ans+f[v])%MOD;
		}
	}
}
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		//不能用auto e, e.clear 
		for(int i=0; i<30005;i++) {
			edges[i].clear();
		}
		memset(f, 0, sizeof(f));
		ans=1; //空集情况 
		for(int i=1; i<n; i++) {
			int u, v;
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1; i<=n; i++) {
			ans=(ans+f[i])%MOD;
		} 
		cout<<ans<<endl;
	}
	return 0;
}

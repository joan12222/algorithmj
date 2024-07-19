#include<bits/stdc++.h>
using namespace std;
#define ll long long
int color[100005];
int cnt[2];
vector<int> edges[200005];
void dfs(int k, int c) {
	color[k]=c;
	cnt[c]++;
	for(auto &y:edges[k]) {
		if(color[y]==-1) {
			dfs(y, c^1);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	};
	memset(color, 255, sizeof(color));
	int ans=0;
	for(int i=1; i<=n; i++) {
		memset(cnt, 0, sizeof(cnt));
		if(color[i]==-1) {
			dfs(i, 0);
			ans+=min(cnt[0], cnt[1]);
		}
	}
	cout<<ans<<" "<<(n-ans)<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],f[1001][1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(j<v[i]) f[i][j] = f[i-1][j];
			else f[i][j]=max(f[i-1][j], f[i-1][j-v[i]]+w[i]);
		}
	}
	int ans=0;
	for(int i=1; i<=m; i++) {
		ans=max(ans, f[n][i]);
	}
	cout<<ans;
	return 0;
}


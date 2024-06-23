#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],f[1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i];
	}
	//初始负无穷，负无穷转移出来还是负无穷 
	memset(f, 0xff, sizeof(f));
	f[0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=v[i]; j<=m; j++) {
			f[j]=max(f[j], f[j-v[i]]+w[i]);
		}
	}
	cout<<f[m];
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],l[1001],f[1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i]>>l[i];
	}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=l[i];k++) //将l[i]个物品分别做01背包 
			for(int j=v[i]; j<=m; j++) {
				f[j]=max(f[j], f[j-v[i]]+w[i]);
			}
	}
	cout<<f[m];
	return 0;
}


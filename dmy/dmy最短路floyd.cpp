#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, q, f[305][305];
int main(){
	cin>>n>>m>>q;
	memset(f, 127, sizeof(f));
	for(int i=1; i<=n; i++) f[i][i]=0;
	for(int i=1; i<=m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		f[x][y]=z;
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(f[i][k]<1<<30&&f[k][j]<1<<30)
					f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int x, y;
		cin>>x>>y;
		if(f[x][y]>=1<<30) cout<<"-1";
		else cout<<f[x][y];
	}
	return 0;
}



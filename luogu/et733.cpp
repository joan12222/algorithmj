#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
long long ans=0;
int main(){
	freopen("et733.in","r",stdin);
	freopen("et733.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<vector<vector<int> > > f(n+1, vector<vector<int> >(m+1,vector<int>(2,0)));
	
	f[1][1][1] = 1;
	for(int i=1; i<=n; i++) {
		f[i][0][0] = 1;
	}
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			f[i][j][1] = f[i-1][j-1][0]; 
			f[i][j][0] = f[i-1][j][1] + f[i-1][j][0];
		}
	}
	cout<<(f[n][m][0]+f[n][m][1])%1000007;
	return 0;
}

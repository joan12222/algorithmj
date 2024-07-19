#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int q;
int n,m; 
int a[12][12];
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>a[i][j];
			}
		}
		if(n>1) {
			for(int i=1; i<n; i++) {
				for(int j=1; j<=m; j++) {
					swap(a[i][j], a[i+1][j]);
				}
			}
		} else if(m>1) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<m; j++) {
					swap(a[i][j], a[i][j+1]);
				}
			}
		}else {
			cout<<-1<<endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

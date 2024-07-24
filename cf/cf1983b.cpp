#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
int n,m;
int t;
int a[N][N],b[N][N]; 
int r[N],c[N];
//观察规律，每次操作对行列的影响 
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		string s;
		cin>>s;
		for(int j=1; j<=m; j++) {
			a[i][j]=s[j-1]-'0';
		}
	}
	//将a数组清零，b数组做相应改变 
	for(int i=1; i<=n; i++) {
		string s;
		cin>>s;
		for(int j=1; j<=m; j++) {
			b[i][j]=s[j-1]-'0';
			b[i][j]=(b[i][j]-a[i][j]+3)%3;
		}
	}
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	//b数组每行每列求和 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			r[i]+=b[i][j];
			c[j]+=b[i][j];
		}
	}
	bool ok=true;
	for(int i=1; i<=n; i++) {
		if(r[i]%3) {
			ok=false;
			break;
		}
	}
	for(int j=1; j<=m; j++) {
		if(c[j]%3) {
			ok=false;
			break;
		}
	}
	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main() {
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}



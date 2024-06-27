#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[100005];
int f[200005];
int ans=-1e9;
int m,n;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	memset(f, 128, sizeof(f));
	f[0]=0;
	for(int i=0;i<=n+n;i++) {
		for(int j=0; j<m; j++) {
			if(i>=a[j]) {
				f[i]=max(f[i],f[i-a[j]]+b[i-a[j]]);
			}
		}
	}
	for(int i=n; i<=n+n; i++) {
		ans=max(ans, f[i]);
	}
	cout<<ans;
	return 0;
}

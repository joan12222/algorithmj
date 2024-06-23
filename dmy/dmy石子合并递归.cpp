#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
int f[100005];
int a[505],s[505];
int dfs(int l, int r) {
	if(l==r) return 0;
	int ans=1<<30;
	for(int i=l; i<r; i++) {
		ans=min(ans,dfs(l, i)+dfs(i+1, r));
	}
	return ans+s[r]-s[l-1];
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int ans;
	ans=dfs(1,n);
	cout<<ans<<endl;
	return 0;
}


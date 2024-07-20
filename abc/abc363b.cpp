#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int a[105];
bool cmp(int a, int b) {
	if(a>=b) return true;
	else return false; 
}
int main() {
	int n,t,p;
	cin>>n>>t>>p;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+1+n, cmp);
	int ans=t-a[p];
	if(ans<=0) cout<<0;
	else cout<<ans;
	return 0;
}

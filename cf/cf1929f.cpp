#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 200005 
int q;
int n,C;
int l[MAXN],r[MAXN],v[MAXN];
ll a[MAXN];
int tot=1;
void dfs(int k) {
	if(k==-1) return;
	dfs(l[k]);
	a[tot++]=v[k];
	dfs(r[k]);
}
ll pow_mod(ll x, ll n) {
	ll res=1;
	while(n) {
		if(n&1) res=res*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return res;
}
ll calc(ll n, ll m) {
	ll res=1;
	for(int i=1; i<=m; i++) res=res*i%MOD;
	res=pow_mod(res, MOD-2); //逆元相关？ 
	for(int i=n; i>=n-m+1; i--) res=res*i%MOD;
//	cout<<"res is "<<res<<endl;
	return res; 
}
int main() {
	cin>>q;
	while(q--) {
		ll ans=1;
		cin>>n>>C;
		for(int i=1; i<=n; i++) {
			cin>>l[i]>>r[i]>>v[i];
		}
		tot=1;
		dfs(1);
		a[0]=1;
		a[n+1]=C;
//		for(int i=0; i<=n+1; i++) cout<<a[i]<<" ";
//		cout<<endl;
		int start=a[0]; //val最小为1，第一个可以填进去的数 
		int cnt=0;
		for(int i=1;i<=n+1;i++) {
			if(a[i]!=-1) {
				ans = (ans*calc(a[i]-start+cnt, cnt))%MOD; //丢番图方程，转换为插板法 
				start=a[i];
				cnt=0;
			} else {
				cnt++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

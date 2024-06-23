#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const int b=131;
int q;
int n,k;
char c[200005];
ll hs[200005], rhs[200005], pwr[200005];
ll get_hs(int l, int r, ll *h) {
	return (h[r]-h[l-1]*pwr[r-l+1]%MOD+MOD)%MOD;
}
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>k>>(c+1);
		pwr[0]=1;
		for(int i=1; i<=n; i++) {
			hs[i]=(hs[i-1]*b+c[i]-'0')%MOD;
			rhs[i]=(rhs[i-1]*b+c[n-i+1]-'0')%MOD;
			pwr[i]=pwr[i-1]*b%MOD;
		}
		ll g0=0,g1=0;
		for(int i=0; i<n; i++) {
			g0=(g0*b+((i/k)%2))%MOD;
			g1=(g1*b+(1-(i/k)%2))%MOD;
		}
		int ans=-1;
		for(int p=1;p<=n;p++) {
			ll gh=(get_hs(p+1, n, hs)*pwr[p]+get_hs(n-p+1, n, rhs))%MOD;
			if(gh==g1||gh==g0) {
				ans=p;
				break;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}


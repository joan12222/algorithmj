#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll n;
ll pwr=1;
ll ans;
ll f;
int main() {
	cin>>n;
	f=n%MOD;//f[1]
	ans=f;
	ll t=n;
	ll l=0;
	while(t) {
		t/=10;
		l++;
	}
	for(int i=1;i<=l;i++) {
		pwr=pwr*10%MOD;
	}
	for(int i=2;i<=n;i++) {
		ans=(ans+((f%MOD)*(pwr%MOD))%MOD)%MOD;
		f=((f%MOD)*(pwr%MOD))%MOD;		
	}
	cout<<ans;
	return 0;
}


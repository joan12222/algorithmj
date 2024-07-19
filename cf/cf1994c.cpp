#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int q;
int n; 
ll a[200005];
ll sum[200005];
ll f[200005];
ll x;
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>x;
		ll ans=0;
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		if(a[n]<=x) f[n]=1;
		for(int i=n-1; i>0; i--) {
			// i, i+1, i+2, 
			for(int j=i+1; j<=n; j++) {
				if(sum[j]-sum[i]>x) {
					f[i]=j-i+f[j+1];
					j=i;
				}
			}
			ans+=f[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n;
int k[22];
ll ans[22];
ll gcd(ll a, ll b) {
	if(a>b) swap(a, b);
	if(a==0) return b;
	else return gcd(a, b%a);
}
ll lcm(ll a, ll b){
	return a*b/__gcd(a,b);
}
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		ll LCM=1;
		for(int i=1;i<=n;i++) {
			cin>>k[i];
			LCM=lcm(LCM,k[i]);
		}
		ll sum=0;
		for(int i=1;i<=n;i++) {
			ans[i]=LCM/k[i];
			sum+=ans[i];
		}
		if(sum>=LCM) cout<< -1;
		else {
			for(int i=1;i<=n;i++) {
				cout<<ans[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}


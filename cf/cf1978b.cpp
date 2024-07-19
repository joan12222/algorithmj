#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b;
int t;
int main(){
	cin>>t;
	while(t--) {
		cin>>n>>a>>b;
		ll k=min(n,b);
		ll ans=0;
		if(b>a) k=min(k,b-a);
		else k=0;
		//11, 10, 9, 8,7
		//b, b-1, b-k+1
		if(k!=0) {
			ans=k*(b+b-k+1)/2;
		}
		ans+=a*(n-k);
		cout<<ans<<endl;
	}
	return 0;
}



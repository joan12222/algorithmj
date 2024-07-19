#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
ll ans=0;
ll maxx=0;
ll a[100005];
int main() {
	cin>>t;
	while(t--) {
		ans=0;
		maxx=0;
		cin>>n;
		cin>>a[1];
		for(int i=2;i<=n;i++) {
			cin>>a[i];
			if(a[i-1]>a[i]) {
				ans+=a[i-1]-a[i];
				maxx=max(maxx, a[i-1]-a[i]);
				a[i]=a[i-1];
			} 
		}
		ans+=maxx;
		cout<<ans<<endl;
	}
	return 0;
}


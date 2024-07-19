#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n,m;
ll a[200005];
ll b[200005];
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=m;i++) {
			cin>>b[i];
		}
		sort(b+1, b+1+m);
		ll sum=0;
		ll maxx=(n%2)?(n+1)/2:n/2;
		for(int i=1;i<=maxx;i++) {
			int d1=b[m-i+1]-a[i];
			sum+=abs(d1);
		}
		for(int i=n;i>maxx;i--) {
			int d2=b[n-i+1]-a[i];
//			cout<<d2<<" ";
			sum+=abs(d2);
		}
		cout<<sum<<endl;
	}
	return 0;
}

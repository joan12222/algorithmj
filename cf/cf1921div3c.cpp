#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll n,f,a,b;
ll m[200005];
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>f>>a>>b;
		for(int i=1;i<=n;i++) {
			cin>>m[i];
		}
		for(int i=1;i<=n;i++) {
			if(((m[i]-m[i-1])*a)<b) f-=(m[i]-m[i-1])*a;
			else f-=b;
		}
		if(f>0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

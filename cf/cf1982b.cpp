#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		ll x,y,k;
		cin>>x>>y>>k;
		while(k&&x!=1) {
			int cnt=min(k,y-x%y);
			k-=cnt;
			x+=cnt;
			while(x%y==0) x/=y;
		}
		k=k%(y-1);
		x+=k;
		cout<<x<<endl;
	}
	return 0;
}



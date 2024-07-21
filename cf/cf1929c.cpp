#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 105
ll k,x,a;
int t;

void solve() {
	cin>>k>>x>>a;
	ll temp=a; //之前本金 
	ll sum=0;//之前付过的钱，之前轮数都亏 
	ll now;//本轮打算放的钱 
	for(int i=1; i<=x+1; i++) {
		if(i==x+1) now=a; // all in
		else now=sum/(k-1)+1; //sum+now<now*k now>sum/(k-1) 每次保证如果我赢的话，都不会亏，这样对方会让我输 
		a-=now;
		if(a<0) {
			cout<<"No"<<endl;
			return;
		}
		sum+=now; 
	}
	a+=now*k;
	if(a<=temp) cout<<"No"<<endl;
	else cout<<"Yes"<<endl; 
}
int main() {
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
} 

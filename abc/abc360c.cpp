#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005],w[100005];
priority_queue<int> q[100005];
ll n;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		q[a[i]].push(-w[i]);
	}
	ll ans=0;
	for(ll i=1; i<=n; i++) {
		while(q[i].size()>=2) {
			ans+=q[i].top();
			q[i].pop();
		}
	}
	cout<<-ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAXN 60
int t,n;
int a[MAXN];
map<int, int> m;
void solve() {
	cin>>n;
	m.clear();
	int maxx=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto v:m) {
		if(v.second%2) {
			cout<<"YES"<<endl;
			return;
		}
	} 
	cout<<"NO"<<endl;
}
int main() {
	cin>>t;
	while(t--) {
		solve();
	}
		
	return 0;
} 

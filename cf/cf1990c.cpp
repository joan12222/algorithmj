#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,t;
int a[N],b[N];
map<int, int> m;
void solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int cnum=0;
	m.clear();	
	for(int i=1; i<=n; i++) {
		m[a[i]]++;
		if(m[a[i]]>=2&&a[i]>cnum) {
			b[i]=a[i];
			cnum=a[i];
		}else {
			b[i]=cnum;
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
int main() {
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
} 

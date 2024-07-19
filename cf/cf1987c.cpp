#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n;
ll t[100005]; 
ll a[100005];
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		t[n]=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=n-1; i>=1; i--) {
			t[i]=max(t[i+1]+a[i+1]-a[i]+1,0ll);
		}
		cout<<(a[1]+t[1])<<endl;
	}
	return 0;
}


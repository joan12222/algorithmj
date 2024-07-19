#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n,k;
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>k;
		int d2=n+n-2;
		if(d2*2>=k) cout<<(int)ceil((double)k/2)<<endl;
		else cout<<(d2+k-2*d2)<<endl;
	}
	return 0;
}

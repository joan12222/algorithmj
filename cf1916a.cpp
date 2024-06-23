#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define MAXN 105
int b[6];
/*
7
##....#

*/

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		long long product=1;
		for(int i=1; i<=n; i++) {
			cin>>b[i];
			product*=b[i];
		}
		if(2023%product) {
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<2023/product<<" ";
		for(int i=2; i<=k; i++) {
			cout<<1<<" ";
		}
		cout<<endl;
	}
	return 0;
} 

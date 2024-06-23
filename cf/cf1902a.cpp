#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define MAXN 105
deque<int> dq;

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
		dq.clear();
		for(int i=1; i<=k; i++) {
			cout<<i;
		}
		for(int i=k+1; i<=n; i++) {
			cout<<n-i+k+1;
		}
		
    	cout<<endl;
	}
	return 0;
} 

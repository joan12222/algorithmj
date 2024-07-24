#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 105
int n;
int t;
int a[N];
void solve() {
	cin>>n;
/*	for(int k=n;k>0;k--) {
		if(2*k>n) {
			a[k]=k;
		} else {
			//1k, 2k, 3k
			//a[k]+a[2*k]=x*k
			int sum=k*100000;
			for(int j=2*k; j<=n; j+=k) {
				sum-=a[j];
			}
			a[k]=sum%k==0?k:sum%k;;
		}
	}
	*/
	for(int i=1; i<=n; i++) {
		cout<<i<<" ";
	}
	cout<<endl;
}

int main() {
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}



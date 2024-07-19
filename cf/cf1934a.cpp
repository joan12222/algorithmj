#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n;
int a[105];
ll ans;


//5 1 3 2 -3 -1 10 3

int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1, a+n+1);
		ans=a[n]-a[1]+a[n]-a[2]+a[n-1]-a[1]+a[n-1]-a[2];
		cout<<ans<<endl;
	}
	return 0;
}


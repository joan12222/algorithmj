#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[105];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ans=n;
	for(int i=1; i<=n; i++) {
		m-=a[i];
		if(m<0) {
			ans=(i-1);
			break;
		}
	}
	cout<<ans;
	return 0;
}


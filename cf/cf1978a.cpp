#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[105];
int main(){
	int t,n;
	cin>>t;
	int maxx;
	while(t--) {
		cin>>n;
		maxx=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<n;i++) {
//			cout<<a[i];
			maxx=max(maxx, a[i]);
		}
		int ans=a[n]+maxx;
		cout<<ans<<endl;
	}
	return 0;
}



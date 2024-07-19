#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n;
int a[105];
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				ans=max(ans, a[j]-a[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

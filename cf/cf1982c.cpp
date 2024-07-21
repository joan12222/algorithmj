#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,l,r;
ll sum[100005];
int a[100005];
int main() {
	cin >> t;
	while(t--) {
		cin>>n>>l>>r;
		memset(sum, 0, sizeof(sum));
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		int ans=0;
		int p=0;//left
		int q=1;//right pointer
		while(q<=n) {
			if(sum[q]-sum[p]>=l) {
				if(sum[q]-sum[p]<=r) {
					ans++;
					p=q;
					q++;
					continue;
				}else {
					p++;
				}
			} else {
				q++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



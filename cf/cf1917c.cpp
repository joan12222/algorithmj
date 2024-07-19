#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k,d;
ll ans=0;
int a[2005];
int b[100005];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>k>>d;
		ll ans=0,now=0; 
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=0; i<k; i++) cin>>b[i];
		//做0次操作1 
		for(int i=1; i<=n; i++) {
			if(a[i]==i) ans++;
		}
		ans+=(d-1)/2; 

		//b[j]=n,每次每个元素都加1，最多N次，就再也不会得分了 
		//n 1 1 1 n, 每k次才能每个元素都加1，要k*n次，直接做操作2的话，最多2*n次也拿到相同的n分了，所以最多循环2*n次 
		//先用i天做i次操作1，再操作2 
		for(int i=1; i<=min(4005, d-1); i++) {
			now=0;
			for(int j=1; j<=b[(i-1)%k]; j++) a[j]++;
			for(int j=1; j<=n; j++) {
				if(a[j]==j) now++;
			}
			now+=(d-i-1)/2;
			ans=max(ans, now);
		}
		cout<<ans<<endl;
	}
	return 0;
}


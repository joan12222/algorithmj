#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n;
int a[50005]; 
//求区间最大值的最小值 
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		int ans=1e9;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}		
		for(int i=1; i<n; i++) {
			ans=min(ans,max(a[i], a[i+1]));
		}		
		cout<<(ans-1) <<endl;
	}
	return 0;
}


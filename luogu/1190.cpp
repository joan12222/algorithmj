#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10110];
int ans=0;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int t=m+1; // m+1 ~ n;
	while(t<=n+m) {
		for(int j=1; j<=m; j++) {
			a[j]--;
			if(a[j]==0) {
				a[j]=a[t];
				t++;
			}
		}
		ans++;
	}
	
	cout<<ans;
	return 0;
}
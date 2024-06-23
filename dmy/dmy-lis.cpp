#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10005];
int f[10005];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	f[1]=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(a[i]>a[j])
				f[i]=max(f[i], f[j]+1);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(a[i]>a[j])
				f[i]=max(f[i], f[j]+1);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		ans=max(ans, f[i]);
	}
	cout<<ans;
	return 0;
}


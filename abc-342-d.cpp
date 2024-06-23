#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n;
int cnt[200005];
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1; i<=n;i++) {
		if(a[i]==0) {
			ans+=n-i;
			continue;
		}
		for(int j=2;j*j<=a[i];j++) {
			while(a[i]%(j*j)==0) {
				a[i]=a[i]/(j*j);
			}
		}
		ans+=cnt[a[i]];
		cnt[a[i]]++;
	}
	cout<<ans;
	return 0;
}

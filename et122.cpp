#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[100010];
int b[100010];
long long ans=0;
int main(){
	freopen("et122.in","r",stdin);
	freopen("et122.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	int cnt=1;
	for(int i=2; i<=n; i++) {
		if(a[i]!=a[i-1]) {
			cnt++;
		} 
	}
	cout<<cnt;
	cout<<cnt*(cnt+1)/2;
	return 0;
}

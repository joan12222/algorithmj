#include<bits/stdc++.h>
using namespace std;
long long tpower[40];
long long a[10000010],b[10000010];

int main(){
	int n;
	cin>>n;
	tpower[0]=1;
	for(int i=1;i<=30;i++) {
		tpower[i]=2*tpower[i-1];
	}

	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>b[i];
	}
	for(int i=1;i<=n;i++) {
		printf("%lld\n",a[i]*tpower[b[i]]);
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int a, b, p;
	cin>>a>>b>>p;
	int ans=1;
	for(;b;b>>=1) {
		if(b&1) {
			ans=(long long)ans*a%p;
		}
		a=(long long)a*a%p;
	}
	cout<<ans;
	return 0;
}

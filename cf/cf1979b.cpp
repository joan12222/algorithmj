#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int main() {
	cin>>q;
	while(q--) {
		int a, b;
		cin>>a>>b;
		int t=a^b;
		cout<<(t&-t)<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int main() {
	int r;
	cin>>r;
	if(r>=1&&r<=99) {
		cout<<(100-r)<<endl;
	} else if(r>=100&&r<199) {
		cout<<(200-r)<<endl;
	}else cout<<(300-r)<<endl;
	return 0;
}

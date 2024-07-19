#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll n;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
//23: 10111 只需考虑bit为1
// 1x111:相当于0从左开始往右移
// 0x111
// 1x011
// 1x101
// 1x110
// 1x111
		int c=__builtin_popcountll(n);
		if(c==1) {
			cout<<1<<endl;
			cout<<n<<endl;
			continue;
		} else {
			cout<<(c+1)<<endl;
			for(int i=60;i>=0;i--) {
				if(n>>i&1) {
					cout<<(n^(1ll<<i))<<" "; //相当于将0从左开始移动 
				}
			}
			cout<<n<<endl; 
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll n;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
//23: 10111 ֻ�迼��bitΪ1
// 1x111:�൱��0����ʼ������
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
					cout<<(n^(1ll<<i))<<" "; //�൱�ڽ�0����ʼ�ƶ� 
				}
			}
			cout<<n<<endl; 
		}
	}
	return 0;
}


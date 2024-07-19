#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll m, n;
vector<ll> ans;
/*
	1	0	1
	0	0	1
r:	1	0
	0	0
111	111
100	011
011	011
4		8	1	8	8		5	1	6	0		1	2	8	6		4	3	0	7		2
0100 1000 0001 1000 1000 0101 0001 0110 0000 0001 0010 1000 0110 0100 0011 0000 0111 0010
0000 0100 0101 0000 0011 0101 1001 1001 0110 0010 0111 0011 0111 0000 0100 1001 0110 0000
		4	5	0	3	5		9	9	6	2		7	3	7	0		4	9	6	0
0100 
a^b=c b=c^a
b>
a^c^a=c
*/

//481885160128643072
//45035996273704960
int main() {
	cin>>q;
	while(q--) {
		int i;
		cin>>n>>m;
		if((n^m)<n) {//包含n和m最高位都为1的情况 
			cout<<1<<endl;
			cout<<n<<" "<<m<<endl;
			continue; 
		}
		//n最高位为1，m最高位为0 
		ans.clear();
		ans.push_back(n);
		bool flag=false;
		ll now=n;
		for(i=63; i>=0; i--) {
			ll bits=1ll<<i;
			if(!(n&bits)&&(m&bits)) {
				i=-1;
				break;
			}
			int n1;
			if((n&bits)&&flag) { 	//把m的0变为1，其它数字和m一样 
				n=m|bits;
				ans.push_back(n);
				if(n==m) {
					break;
				}
			}
			if(n&bits) { //把n的1变为0往m靠 
				flag=true;
				if(!(m&bits)) {
					n-=bits;
//					ans.push_back(n);
				}
			}
		}
		if(i<0) cout<<-1<<endl;
		else {
			cout<<(ans.size()-1)<<endl;
			for(auto x:ans) {
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll n, m;
ll c[70];
int main(){
	cin>>n>>m;
	//����m��bit i��0~n������˶��ٴ� 
	for(ll i=0; (1ll<<i)<m; i++) {
		//m��bit iΪ1 
		if((m&(1ll<<i))) {
//			cout<<(n&((1<<(i+1))-1))<<endl;
			c[i]=(n&((1ll<<(i+1))-1))%MOD; //��iλ�Ժ�
			if(n>=(1ll<<i)) {
				c[i]+=(((n>>(i+1))%MOD)*((1ll<<i)%MOD))%MOD;
				c[i]%=MOD;
			}
		}	
	}
	ll ans=0;
	for(int i=0; i<70; i++) {
		if(c[i]!=0) {
//			cout<<i<<" "<<c[i]<<" "<<endl;
			ans+=c[i]%MOD;
		}
	}
	cout<<ans%MOD;
	return 0;
}



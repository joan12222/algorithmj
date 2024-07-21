#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200005
ll n,x;
ll a[MAXN];
ll f[MAXN];//表示从第i个蘑菇开始吃，有多少种可能性 
int t;

void solve() {
	cin>>n>>x;
	for(int i=1; i<=n; i++) {
		cin>>a[n];
	}
	int j=-1; //tail指针，后面就开始sum>x了 
	ll sum=0;
	memset(f, 0, sizeof(f));
	for(int i=n; i>0; i--) {
		sum+=a[i];
		if(j==-1) {
			if(sum<=x) f[i]+=1;
			if(i+2<=n) f[i]+=f[i+2];//重新计算 
			j=i;
		} else {
			if(sum<=x) {
				f[i]+=j-i+1;
				if(j+2<=n) f[i]+=f[j+2];
			}else {
				while(sum>x) {
					sum-=a[j];
					j--;
				} //此时sum<=x
				if(sum==0) { //与sum<=0一样，因为sum是和，不可能出现<0的情况 
					j=-1;
					sum=0;
					f[i]+=1;
					if(i+1<=n) f[i]+=f[i+1];//正好为0，只需要顺延1 
				} else {
					f[i]+=j-i+1;
					if(j+2<=n) f[i]+=f[j+2];
				}
			}
		}
	}
}
int main() {
	cin>>t;
	while(t--) {
		solve();
		ll ans=0;
		for(int i=1; i<=n; i++) {
			cout<<f[i]<<" ";
			ans+=f[i]; 
		}
		cout<<ans<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200005
ll n,x;
ll a[MAXN];
ll f[MAXN];//��ʾ�ӵ�i��Ģ����ʼ�ԣ��ж����ֿ����� 
int t;

void solve() {
	cin>>n>>x;
	for(int i=1; i<=n; i++) {
		cin>>a[n];
	}
	int j=-1; //tailָ�룬����Ϳ�ʼsum>x�� 
	ll sum=0;
	memset(f, 0, sizeof(f));
	for(int i=n; i>0; i--) {
		sum+=a[i];
		if(j==-1) {
			if(sum<=x) f[i]+=1;
			if(i+2<=n) f[i]+=f[i+2];//���¼��� 
			j=i;
		} else {
			if(sum<=x) {
				f[i]+=j-i+1;
				if(j+2<=n) f[i]+=f[j+2];
			}else {
				while(sum>x) {
					sum-=a[j];
					j--;
				} //��ʱsum<=x
				if(sum==0) { //��sum<=0һ������Ϊsum�Ǻͣ������ܳ���<0����� 
					j=-1;
					sum=0;
					f[i]+=1;
					if(i+1<=n) f[i]+=f[i+1];//����Ϊ0��ֻ��Ҫ˳��1 
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

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int q;
int n; 
ll a[200005];
ll f[200005];//f[i]表示以a[i]开头

ll x;
int main() {
	cin>>q;
	while(q--) {
		cin>>n>>x;
		for(int i=1; i<=n; i++) cin>>a[i];
		ll ans=0;
		memset(f, 0, sizeof(f));
		int j=-1; //新一轮准备开始 
		ll sum=0;
		/*
// 1 1 1 1 x=2
f[4]=1 j=4 sum=1
f[3]=2 j=4 sum=2
f[2]=2  j=3, sum=2
f[1]=3  j=3,sum=3
		j=2,sum=2
// 1 2 3 x=2
f[3]=0 j=3 sum=3
f[2]=1   j=3 sum=5
	   j=2 sum=2
f[1]=1 j=2 sum=3 
// 10 x=6
f[1]=0 j=1 sum=10
//1 2 1 4 3 8 x=3
f[6]=0 j=6 sum=8
f[5]=1  sum=11 j=6
	   sum=3 j=5  (3)
f[4]=1  sum=7 j=5
       sum=4 j=4
       sum=0 j=3 (4,3) j=-1
f[3]=2  sum=1 j=3 (1) (1,4,3)  
f[2]=3   sum=3 j=3 (2) (2,1) (2,1,4,3)
f[1]=3 sum=4,j=3
		sum=3,j=2; (1) (1,2),(1,2,1,4,3)
		*/
		for(int i=n; i>0; i--) {
			sum+=a[i];
			if(j==-1) {
				if(sum<=x) f[i]+=1;
				if(i+2<=n) f[i]+=f[i+2];
				j=i;
			} else {
				if(sum<=x) {
					f[i]+=j-i+1;
					if(j+2<=n) f[i]+=f[j+2];
				} else {
					while(sum>x) {
						sum-=a[j];
						j--;
					}
					if(sum==0) {
						j=-1;
						if(i+1<=n) f[i]=f[i+1];
					} else {
						f[i]+=j-i+1;
						if(j+2<=n) f[i]+=f[j+2];
					}					
				}
			}
		}
		for(int i=1;i<=n;i++) {
//			cout<<f[i]<<" ";
			ans+=f[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

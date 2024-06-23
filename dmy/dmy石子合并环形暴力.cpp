#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
int s[505];
int f[1005][1005];
int a[2010];
int main() {
	cin>>n;
	memset(f, 0x3f, sizeof(f));
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1; i<=2*n; i++) {
		s[i]=s[i-1]+a[i];
		f[i][i]=0;
	}	
	//枚举区间长度 ,虽然后面结果区间长度是n,但转移过程中，所有2n区间都要计算 
	for(int i=1;i<2*n;i++) {
		//枚举左端点 
		for(int j=1;j<=2*n-i;j++) {
			//枚举分界线 
			for(int k=j;k<i+j;k++) {
				f[j][i+j]=min(f[j][i+j], f[j][k]+f[k+1][i+j]);
			}
			f[j][i+j]+=s[i+j]-s[j-1];
		}
	}
	int ans=1<<30;
	for(int i=1;i<=n; i++) {
		ans=min((f[i][n+i-1]), ans);
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
int f[1005][1005];
int a[505],s[505];
int main() {
	cin>>n;
	memset(f, 0x3f, sizeof(f));
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		f[i][i]=0; 
	}
	//f[i][j]
	//枚举区间长度 
	for(int i=1; i<n;i++) {
		//枚举左端点 
		for(int j=1;j<=n-i;j++) {
			//枚举分界线 
			for(int k=j;k<i+j;k++) {
				f[j][i+j]=min(f[j][i+j], f[j][k]+f[k+1][i+j]);
			}
			f[j][i+j]+=s[i+j]-s[j-1];
		}
	}
	cout<<f[1][n];
	return 0;
}


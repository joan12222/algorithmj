#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
char s[505];
int f[1005][1005];
int a[505];
int main() {
	cin>>n;
	cin>>s+1; 
	memset(f, 0, sizeof(f));
	//f[i][j]
	//枚举区间长度 
	for(int i=1; i<n;i++) {
		//枚举左端点 
		for(int j=1;j<=n-i;j++) {
			if((s[j]=='('&&s[i+j]==')')||(s[j]=='['&&s[i+j]==']')) {
				f[j][i+j]=f[i+1][i+j-1]+2;
			}
			//枚举分界线 
			for(int k=j;k<i+j;k++) {
				f[j][i+j]=max(f[j][i+j], f[j][k]+f[k+1][i+j]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[2005];
int f[2005][2005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=a[i]*n;
	}
	for(int l=2; l<=n; l++) {
		for(int i=1; i<=n; i++) {
			// j-i+1=l
			int j=i+l-1;
			if(j>n) break;
			f[i][j]=max(f[i+1][j] + a[i]*(n-l+1), f[i][j-1]+a[j]*(n-l+1));
		}
	}
	cout<<f[1][n];
	return 0;
}

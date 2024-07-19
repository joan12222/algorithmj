#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005], b[1005], c[1005];
int f[1005][3][1005];
int cmp(int a, int b) {
	if(a==b) return 1;
	else if(a==2&&b==0) return 0;
	else if(a==0&&b==2) return 2;
	else if(a>b) return 2;
	else return 0; 
} 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	f[1][0][0]=cmp(0,c[1])*a[1];
	f[1][1][0]=cmp(1,c[1])*a[1];
	f[1][2][0]=cmp(2,c[1])*a[1];
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=2; j++) {
			for(int k=0; k<i; k++) {
				int t=cmp(j, c[i])*a[i];
				f[i][j][k]=f[i-1][j][k]+t; //iÂÖºÍi-1ÂÖÒ»Ñù
				if(k>0) {
					for(int prev=0; prev<=2; prev++) {
						if(prev!=j)
							f[i][j][k]=max(f[i][j][k], f[i-1][prev][k-1]+t-b[k]);
					}
				}
			}
		}
	}
	int ans=-2e9;
	for(int j=0; j<=2; j++) {
		for(int k=0; k<n; k++) {
			ans=max(ans, f[n][j][k]);
		}
	}
	cout<<ans;
	return 0;
}

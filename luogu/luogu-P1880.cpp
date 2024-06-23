#include<bits/stdc++.h>
using namespace std;
int n,a[105];
int pre[105];
int minn[105][105],maxx[105][105];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	memset(minn,0x3f,sizeof(minn));
	memset(maxx,-1,sizeof(maxx));
	pre[0]=0;
	for(int i=1;i<2*n;i++){
		pre[i]=pre[i-1]+a[i];
		maxx[i][i]=minn[i][i]=0;
	}
	
	for(int len=2; len<=n; len++) {
		for(int l=1; l<=2*n-len+1; l++) {
			int r=l+len-1;
			for(int p=l; p<r; p++) {
				maxx[l][r] = max(maxx[l][r], maxx[l][p]+maxx[p+1][r]+pre[r]-pre[l-1]);
				minn[l][r] = min(minn[l][r], minn[l][p]+minn[p+1][r]+pre[r]-pre[l-1]);
			}
		}
	}
	int minans=0x3f3f3f3f;
	int maxans=-1;
	for(int i=1; i<=n; i++) {
		minans=min(minans, minn[i][i+n-1]);
		maxans=max(maxans, maxx[i][i+n-1]);
	}
	cout<<minans<<endl<<maxans<<endl;
	return 0;
}


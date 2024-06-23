#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[105][105],f[10005];
//完全背包，正着写，一维数组 
int main() {
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++){ //天数 
		for(int j=1;j<=n;j++){ //纪念品 
			cin>>a[j][i];
		}
	}

	for(int i=1; i<t; i++) { //i天
		//第i天操作每种纪念品能获取的最大收益
		int maxx=-1;
		memset(f, 0, sizeof(f)); 
		for(int j=1; j<=n; j++) {  //j纪念品 
			for(int k=a[j][i]; k<=m; k++) { 
				// f[k],当前有k钱，对第j种物品操作，能获取的最大收益
				f[k] = max(f[k], f[k-a[j][i]]+a[j][i+1]-a[j][i]);
				maxx = max(maxx, f[k]);
			}
		}
		m+=maxx;
	}
	cout<<m; 
	return 0;
} 

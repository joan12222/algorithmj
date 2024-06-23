#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[1005][1005];
int f[1005][1005];
int r;
int ans=-1;
/*
//搜索 
void dfs(int x, int y, int res) {
	if(x>=r+1) {
		ans=max(ans, res+a[x][y]);
		return;
	}
	dfs(x+1, y, res+a[x][y]);
	dfs(x+1, y+1, res+a[x][y]);

}
int main(){
	cin>>r;
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=i; j++) {
			cin>>a[i][j];
		}
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
*/

/*
//记忆化搜索 
int dfs(int x, int y) {
	if(x>=r+1) {
		return a[x][y];
	}
	if(f[x][y]!=-1) return f[x][y];
	f[x][y] = max(dfs(x+1, y), dfs(x+1,y+1)) + a[x][y];
	return f[x][y];
}
int main(){
	cin>>r;
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=i; j++) {
			cin>>a[i][j];
		}
	}
	memset(f, 255, sizeof(f));
	cout<<dfs(1,1);
	return 0;
}
*/

/*
//动态规划 -- 迭代 
*/
int main(){
	cin>>r;
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=i; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=i; j++) {
			f[i][j] = max(f[i-1][j], f[i-1][j-1]) + a[i][j];
		}
	}
	for(int j=1; j<=r; j++) {
		ans = max(f[r][j], ans);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int ans = INT_MIN;
int r;
int c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int steps[101][101]={0};
int dfs(int x, int y) {
	if(steps[x][y]) return steps[x][y];
	steps[x][y]=1;
	for(int i=0; i<4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&a[nx][ny]>a[x][y]) {
			dfs(nx, ny);
			steps[x][y] = max(steps[x][y], steps[nx][ny]+1);
		}
	}
	return steps[x][y];
}
int main(){
	// 25, (2,3,4,5),
	cin>>r>>c;
	for(int i = 1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			cin>>a[i][j];
		}
	}
	for(int i = 1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout<<ans;
}
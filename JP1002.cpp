#include<bits/stdc++.h>
using namespace std;
int ex, ey;
int hx, hy;
int ans=0;
pair<int, int> p[9];
int vis[22][22]={0};
bool eaten(int nx, int ny) {
	for(int i=1;i<=8;i++) {
		if(nx==p[i].first&&ny==p[i].second) {
			return true;
		}
	}
	return false;
}
void dfs(int x, int y) {
	if(x==ex&&y==ey) {
		ans++;
		return;
	}
	int nx=x+1;
	int ny=y;
	if(nx<=ex&&ny<=ey&&eaten(nx, ny)==0&&vis[nx][ny]==0) {
		vis[nx][ny]=1;
		dfs(nx,ny);
	}
	nx=x;
	ny=y+1;
	if(nx<=ex&&ny<=ey&&eaten(nx, ny)==0&&vis[nx][ny]==0) {
		vis[nx][ny]=1;
		dfs(nx,ny);
	}
}
int main(){
	cin>>hx>>hy>>ex>>ey;
	p[1].first=hx+1,p[1].second=hy+2;
	p[2].first=hx+2,p[1].second=hy+1;
	p[3].first=hx+2,p[1].second=hy-1;
	p[4].first=hx+1,p[1].second=hy-2;
	p[5].first=hx-1,p[1].second=hy-2;
	p[6].first=hx-2,p[1].second=hy-1;
	p[7].first=hx-2,p[1].second=hy+1;
	p[8].first=hx-1,p[1].second=hy+2;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
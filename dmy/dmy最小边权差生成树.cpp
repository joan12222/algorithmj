#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
struct Node {
	int x,y,v;
	bool operator < (const Node &A) {
		return v<A.v;
	}
}a[100005];
int fa[50001];
int findset(int i) {
	if(i==fa[i]) return i;
	return fa[i]=findset(fa[i]);
}
inline void Kruskal() {
	sort(a+1, a+m+1);
	int ans=1<<30;
	//枚举生成树里边权最小的边的可能性 
	for(int i=1; i<=m; i++) {
		for(int i=1; i<=n; i++) {
			fa[i]=i;
		}		
		int cnt=n;
		//开始构建最小生成树 
		for(int j=i;j<=m;j++) {
			int x=findset(a[j].x),y=findset(a[j].y);
			if(x!=y) {
				fa[x]=y;
				cnt--;
			}
			if(cnt==1) {
				ans=min(ans, a[j].v-a[i].v);
				break;
			}
		}
	}
	cout<<ans;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>a[i].x>>a[i].y>>a[i].v;
	}
	Kruskal();
	return 0;
}



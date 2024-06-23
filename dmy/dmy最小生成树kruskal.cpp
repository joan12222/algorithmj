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
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	sort(a+1, a+m+1);
	int ans=0;
	for(int i=1; i<=m; i++) {
		int x=findset(a[i].x),y=findset(a[i].y);
		if(x!=y) {
			fa[x]=y;
			ans+=a[i].v;
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



#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[100005];
int ans=-1e9;
int m,n;
void dfs(int k,int v){
	ans=max(ans, v);
	if(k>=n) return;
	for(int i=0;i<m;i++) {
		dfs(k+a[i],v+b[k]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

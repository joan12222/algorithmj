#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
int leftchild[MAXN];
int rightchild[MAXN];
int val[MAXN];

int ans=0;
void dfs(int k, int d) {
	ans=max(d, ans);
	if(leftchild[k]) dfs(leftchild[k], d+1);
	if(rightchild[k]) dfs(rightchild[k], d+1);
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>leftchild[i]>>rightchild[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#include<bitset>
using namespace std;
int c[20];
#define ll long long
int n,W;
int best=1e9;
int cable[20];
//第k只猫，现有curr辆车 
void dfs(int k, int curr) {
	if(k==n+1) {
		best=min(curr, best);
		return;
	}
	if(curr>=best) return;
	for(int i=1; i<=curr; i++) {
		if(c[k]+cable[i]<=W) {
			cable[i]+=c[k];
			dfs(k+1, curr);
			cable[i]-=c[k];			
		}
	}
	cable[curr+1]=c[k];
	dfs(k+1,curr+1);
	cable[curr+1]=0;
}

int main(){
	cin>>n>>W;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(1,0);
	cout<<best;
	return 0;
}



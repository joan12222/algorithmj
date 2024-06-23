#include<bits/stdc++.h>
using namespace std;
int n,k;
long long steps[100005];
int dfs(int m){
	if(m==0) return 1;
	if(steps[m]!=-1) return steps[m];
	
	int maxx;
	int ans=0;
	if(m<=k) {
		maxx=m;
	}else {
		maxx=k;
	}
	// dfs(m-1)*dfs(1) + dfs(m-2)*dfs(2)
	for(int i=1; i<=max(maxx, 1); i++) {
		ans=(ans+dfs(m-i))%100003;
	}
	steps[m]=ans;
	return ans;
}

int main(){
	cin>>n>>k;
	memset(steps, -1, sizeof(steps));
	cout<<dfs(n)%100003;

	return 0;
}

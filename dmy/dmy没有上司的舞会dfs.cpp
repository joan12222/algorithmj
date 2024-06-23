#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
vector<int> edges[200005];
int a[200005];
int f[200005];
int dfs(int x, int b) {
	int ans1=0, ans2=0;
	if(b==false) {
		for(auto y:edges[x]){
			ans1+=max(dfs(y, 1),dfs(y,0));
		}
	} else {
		ans2+=a[x];
		for(auto y:edges[x]){
			ans2+=dfs(y,0);
		}
	}
	return ans1>ans2?ans1:ans2;
}
int main() {
	cin>>n;
	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;
		edges[x].push_back(i);
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cout<<max(dfs(1,1),dfs(1,0));
	return 0;
}


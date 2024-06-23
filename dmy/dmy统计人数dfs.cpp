#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
vector<int> edges[200005];
int s[200005];
int b[200005];
int dfs(int x) {
	s[x]=1;
	for(auto y: edges[x]) {
		if(!b[y]) {
			s[x]+=dfs(y);
			b[y]=true;
		}
	}
	return s[x];
}
int main() {
	cin>>n;
	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;
		edges[x].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=n; i++)
		cout<<s[i]<<endl;
	return 0;
}


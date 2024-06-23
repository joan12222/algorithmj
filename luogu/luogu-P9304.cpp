#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> to[100005];
int maxx=0;
void dfs(int x, int fa, int depth) {
	if(depth>maxx) maxx=depth;
	for(int y:to[x]) {
		if(y!=fa) 
			dfs(y, x, depth+1);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	dfs(1, 0, 0);
	for(int i=1; i<=n; i++) {
		cout<<2*(i-1)-min(i-1, maxx)<<endl;
	}
}

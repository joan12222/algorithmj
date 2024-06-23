#include<bits/stdc++.h>
using namespace std;
int books[21]={0};
pair<int, int> p[21];
void dfs(int k, int b) {
	if(k==n+1) {
		for(int i=1;i<=x;i++) {
			if(books[i]!=1) return;
		}
		ans++;
		return;
	}
	books[b]++;
	dfs(k+1, p[k].first);
	dfs(k+1, p[k].second);
}
int main(){
	cin>>x;
	for(int i=1; i<=x;i++) {
		cin>>p[i].first>>p[i].second;
	}
	// i means person
	dfs(1, p[1].first);
	dfs(1, p[1].second);
	return 0;
}
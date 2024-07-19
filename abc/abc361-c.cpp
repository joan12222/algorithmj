#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
vector<int> t[100];
char res[100];
int ans=0;
bool is_real[100];
bool check() {
	for(int i=1;i<=m;i++) {
		int cnt=0;
		for(auto idx:t[i]) {
			if(is_real[idx]) cnt++;
		}
		if((cnt<k&&res[i]=='o')||(cnt>=k&&res[i]=='x')) return false;
	}
	return true;
}
void dfs(int now) {
	if(now==n+1) {
		if(check()) ans++;
		return;
	}
	dfs(now+1);
	is_real[now]=true;
	dfs(now+1);
	is_real[now]=false;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int c;
		cin>>c;
		for(int j=1;j<=c;j++) {
			int x;
			cin>>x;
			t[i].push_back(x);
		}
		cin>>res[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}



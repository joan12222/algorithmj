#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> to[10];
bool b[10];
int k;
int n, m;
bool dfs(int x, int c) {
	//������b[x]=1 ����x���յ����ʱ������
	//c==n��������c==n+1:��һ���㲻�� 
	if(c==n&&x==k) return true;
	for(auto y:to[x]) {
		if(!b[y]) {
			b[y]=1; 
			if(dfs(y,c+1)) return true;
			b[y]=0;
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	cin>>k;
	if(dfs(k,0)) cout<<"Yes";
	else cout<<"No";
	return 0;
}



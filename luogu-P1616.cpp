#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int t[10005];
int v[10005];
//vector<vector<int>> f(10005, vector<int>(10005, 0));
//int f[10005][10005];
long long f[10000005];
int tt,m;
int main(){
	cin>>tt>>m;
	for(int i=1; i<=m; i++) {
		cin>>t[i]>>v[i];
	}
	/*
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=tt; j++) {
			if(j>=t[i]) f[i][j] = max(f[i][j-t[i]] + v[i], f[i-1][j]); 
			else f[i][j] = f[i-1][j];
			//f[i][j] = max(f[i-1][j-t[i]]+v[i], f[i-1][j]);
		}
	}*/
	for(int i=1; i<=m; i++) {
		for(int j=t[i]; j<=tt; j++) {
			f[j]=max(f[j], f[j-t[i]]+v[i]);
		}
	}
	cout<<f[tt];
	return 0;
}

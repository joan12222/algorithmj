#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
vector<int> edges[200005];
int c[200005];
int f[200005];
queue<int> q;
int bfs() {
	//有点像双指针 
	c[1]=1;
	for(int k=1,l=1;l<=k;l++) {
		int now=c[l];
		for(auto y: edges[now]) {
			c[++k]=y;
		}
	}
}
int main() {
	cin>>n;
	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;
		edges[x].push_back(i);
	}
	bfs();
	//数组里存放着bfs序，从后往前计算size 
	for(int i=n; i; i--) {
		int now=c[i];
		f[now]=1;
		for(auto y: edges[now]) {
			f[now]+=f[y];
		}		
	}
	for(int i=1; i<=n; i++) {
		cout<<f[i]<<endl;
	}
	return 0;
}

